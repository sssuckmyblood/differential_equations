#include "mainwindow.h"
#include "ui_mainwindow.h"

QSqlDatabase db;

void MainWindow::db_create(){

    ui->spinner->setVisible(true);
    ui->spinner->setEnabled(true);
    QMovie *movie = new QMovie(":/gif/loading.gif");
    ui->spinner->setMovie(movie);
    movie->start();


    db = QSqlDatabase::addDatabase("QPSQL");
    db.setHostName(ui->pg_ip->text());
    db.setDatabaseName(ui->pg_bd->text());
    db.setUserName(ui->pg_user->text());

    if(ui->pg_password->isEnabled())
        db.setPassword(ui->pg_password->text());

    db.setPort(ui->pg_port->value());
    db.setConnectOptions("connect_timeout=2");



      if(db.open()){
        QSqlQuery query;
        if(!query.exec(
                     "create sequence if not exists equation_id_seq increment 1 start 0 minvalue 0 maxvalue 2147483647;"
                     "create table if not exists equation ( "
                     " id integer NOT NULL DEFAULT nextval('equation_id_seq'::regclass), "
                     "name_equ character varying(256), "
                     "a_equ numeric, "
                     "b_equ numeric, "
                     "y0_equ numeric, "
                     "accuracy numeric, "
                     "date timestamp without time zone, "
                     "primary key (id) );  "
                     "alter table if exists equation "
                     "owner to postgres;  "
                     "comment on table equation "
                     "is 'table with equation parameters'; "
                     "create table if not exists method_euler ( "
                     "id integer not null, "
                     "x numeric, "
                     "y numeric, "
                     "exact numeric, "
                     "error numeric   );  "
                     "alter table if exists method_euler "
                     "owner to postgres;  "
                     "comment on table method_euler "
                     "is 'table for euler method'; "
                     "create table if not exists method_runge ( "
                     "id integer not null, "
                     "x numeric, "
                     "y numeric, "
                     "exact numeric, "
                     "error numeric  );  "
                     "alter table if exists method_runge "
                     "owner to postgres;  "
                     "comment on table method_runge "
                     "is 'table for runge method';"
                     "ALTER SEQUENCE IF EXISTS public.equation_id_seq OWNED BY equation.id; "
                     "ALTER TABLE equation "
                     "ADD CONSTRAINT equation_uni UNIQUE (name_equ,  a_equ, b_equ,  y0_equ, accuracy) "
                    )) {
                        QMessageBox::critical(NULL, QObject::tr("Ошибка подключения"), "Информация о ошибке:<br>" +
                                                    query.lastError().text());
                        db.close();
                        QSqlDatabase::removeDatabase(db.connectionName());

                        }

                    delete movie;
                    ui->spinner->setVisible(false);
                    ui->spinner->setEnabled(false);


      } else {

                  QMessageBox::critical(NULL, QObject::tr("Ошибка подключения"), "Информация о ошибке:<br>" +
                                              db.lastError().databaseText());
                  db.close();
                  QSqlDatabase::removeDatabase(db.connectionName());

                  delete movie;
                  ui->spinner->setVisible(false);
                  ui->spinner->setEnabled(false);

      }

}

void MainWindow::data_to_bd(){

    if (db.open()){

        QDateTime dateTime = dateTime.currentDateTime();

        QString equ_name;

           if(ui->combo_equ->isEnabled()){

              ui->combo_equ->setItemText(ui->combo_equ->currentIndex(), ui->combo_equ->currentText().remove(" ---> в БД"));
              equ_name = ui->combo_equ->currentText();

           } else
                 equ_name = ui->line_equ->text();


              QSqlQuery query_equ;
              QSqlQuery query_euler;
              QSqlQuery query_runge;

              query_equ.prepare("INSERT INTO equation (name_equ, a_equ, b_equ, y0_equ, accuracy, date) "
                            "VALUES (:name_equ, :a_equ, :b_equ, :y0_equ, :accuracy, :date)"
                            "RETURNING id"
                            );

              query_equ.bindValue(":name_equ",  equ_name);
              query_equ.bindValue(":a_equ", ui->a->value());
              query_equ.bindValue(":b_equ", ui->b->value());
              query_equ.bindValue(":y0_equ", ui->y0->value());
              query_equ.bindValue(":accuracy", ui->accuracy->value());
              query_equ.bindValue(":date", dateTime.toString("yyyy-MM-dd HH:mm"));

              if(query_equ.exec()){

                    query_equ.next();
                    int id = query_equ.value(0).toInt();


                        query_euler.prepare("INSERT INTO method_euler (id, x, y, exact, error) "
                                            "VALUES (:id, :x, :y, :exact, :error)"
                                            );

                        query_runge.prepare("INSERT INTO method_runge (id, x, y, exact, error) "
                                            "VALUES (:id, :x, :y, :exact, :error)"
                                            );

                    if(ui->combo_equ->isEnabled()){

                        for(int i = 2; i < ui->euler_data->rowCount(); i++){

                            query_euler.bindValue(":id", id);
                            query_euler.bindValue(":x", ui->euler_data->item(i,0)->text());
                            query_euler.bindValue(":y", ui->euler_data->item(i,1)->text());
                            query_euler.bindValue(":exact", ui->euler_data->item(i,2)->text());
                            query_euler.bindValue(":error", ui->euler_data->item(i,3)->text());


                            query_runge.bindValue(":id", id);
                            query_runge.bindValue(":x", ui->runge_data->item(i,0)->text());
                            query_runge.bindValue(":y", ui->runge_data->item(i,1)->text());
                            query_runge.bindValue(":exact", ui->runge_data->item(i,2)->text());
                            query_runge.bindValue(":error", ui->runge_data->item(i,3)->text());

                            if(!query_euler.exec()){
                                 QMessageBox::critical(NULL, QObject::tr("Ошибка записи данных"), "Ошибка записи данных в БД <br><br>Информация о ошибке:<br>" +
                                                             query_euler.lastError().text());
                                  db_close();
                                 break;

                            }

                            if(!query_runge.exec()){
                                 QMessageBox::critical(NULL, QObject::tr("Ошибка записи данных"), "Ошибка записи данных в БД <br><br>Информация о ошибке:<br>" +
                                                             query_runge.lastError().text());
                                 db_close();
                                 break;

                            }


                        }

                    } else {

                        for(int i = 2; i < ui->euler_data->rowCount(); i++){

                            query_euler.bindValue(":id", id);
                            query_euler.bindValue(":x",  ui->euler_data->item(i,0)->text());
                            query_euler.bindValue(":y", ui->euler_data->item(i,1)->text());
                            query_euler.bindValue(":exact", 0);
                            query_euler.bindValue(":error", 0);


                            query_runge.bindValue(":id", id);
                            query_runge.bindValue(":x", ui->runge_data->item(i,0)->text());
                            query_runge.bindValue(":y", ui->runge_data->item(i,1)->text());
                            query_runge.bindValue(":exact", 0);
                            query_runge.bindValue(":error", 0);

                            if(!query_euler.exec()){
                                 QMessageBox::critical(NULL, QObject::tr("Ошибка записи данных"), "Ошибка записи данных в БД <br><br>Информация о ошибке:<br>" +
                                                             query_euler.lastError().text());
                                 db_close();
                                 break;

                            }

                            if(!query_runge.exec()){
                                 QMessageBox::critical(NULL, QObject::tr("Ошибка записи данных"), "Ошибка записи данных в БД <br><br>Информация о ошибке:<br>" +
                                                             query_runge.lastError().text());
                                 db_close();
                                 break;

                            }
                        }
                    }
                   qDebug() <<  query_euler.lastError().isValid();
                    if(!query_euler.lastError().isValid() && !query_runge.lastError().isValid()){

                        if(ui->combo_equ->isEnabled()){
                            ui->combo_equ->setItemText(ui->combo_equ->currentIndex(), ui->combo_equ->currentText()+" ---> в БД");
                        }

                            QMessageBox::information(NULL, QObject::tr("Успех"),"Уравнение внесено в БД");

                    }

                } else
                       QMessageBox::critical(NULL, QObject::tr("Ошибка"),"Возможно такое же уравнение с такими параметрами уже есть в БД... <br><br> Информация о ошибке:<br>" +
                                                  query_equ.lastError().text());


    }

}


void MainWindow::on_pg_connect_clicked()
{

    if(!db.open())
          db_create();


    if (db.open()){

        ui->status_db->setText("Сервер подключен ✅️");
        ui->db_driver->setText(db.driverName());
        ui->write_to_bd->setVisible(true);
        ui->write_to_bd->setEnabled(true);
        ui->label_12->setEnabled(true);
        ui->combo_equ_db->setEnabled(true);
        ui->clear_bd->setEnabled(true);
        ui->euler_data_db->setEnabled(true);
        ui->runge_data_db->setEnabled(true);
        ui->graph_layout_db->setEnabled(true);
        ui->reset_graph_db->setEnabled(true);
        ui->pg_connect->setEnabled(false);
        update_combo_equ();


      } else {
          ui->status_db->setText("Сервер отключен ❌");
          ui->db_driver->setText("");


      }

}



void MainWindow::on_write_to_bd_clicked() {

     if (db.open()){
        data_to_bd();
        ui->write_to_bd->setEnabled(false);

     } else {

                     QMessageBox::critical(NULL, QObject::tr("Ошибка подключения"), "Информация о ошибке:<br>" +
                                                 db.lastError().databaseText());
                     db_close();

     }

}


void MainWindow::update_combo_equ() {

     ui->combo_equ_db->clear();

    if (db.open()){

        QSqlQuery query;
        if(query.exec("SELECT * FROM equation ORDER BY id DESC")){
            while(query.next()){

                QDateTime equ_time = QDateTime::fromString(query.value(6).toString(), Qt::ISODate);
                ui->combo_equ_db->addItem("Дата: " + equ_time.toString("yyyy-MM-dd hh:mm")+ " || " +
                                      "Уравнение: " + query.value(1).toString()+ " || " +
                                       "Отрезок: [" + query.value(2).toString()+ ";" +
                                       query.value(3).toString()+ "] || " +
                                       "y("+ query.value(2).toString()+")= " +query.value(4).toString()+ " || "  +
                                       "Точность: "+query.value(5).toString(),
                                       query.value(0).toInt());

            }


        } else
            QMessageBox::critical(NULL, QObject::tr("Ошибка чтения данных"), "Ошибка чтения данных<br><br>Информация о ошибке:<br>" + \
                                        query.lastError().text());
    }
}

void MainWindow::on_tabWidget_currentChanged(int index)
{
   if(index == 1){
      if(db.open()){

             update_combo_equ();


      } else if (ui->write_to_bd->isVisibleTo(ui->tabWidget->widget(0))){

                 QMessageBox::critical(NULL, QObject::tr("Ошибка подключения"), "Информация о ошибке:<br>" +
                                             db.lastError().databaseText());
                 db_close();
      }


   }
}

void MainWindow::on_combo_equ_db_activated(int index)
{

    if(db.open()){

        QSqlQuery query_euler;
                   query_euler.prepare("SELECT * FROM method_euler WHERE id = :id");

        int current_id = ui->combo_equ_db->itemData(index).toInt();

        query_euler.bindValue(":id", current_id);



        QSqlQuery query_runge;
                   query_runge.prepare("SELECT * FROM method_runge WHERE id = :id");

        query_runge.bindValue(":id", current_id);

        if(query_euler.exec() && query_runge.exec()){

            ui->euler_data_db->clear();
            ui->euler_data_db->clearContents();
            ui->runge_data_db->clear();
            ui->runge_data_db->clearContents();

            ui->euler_data_db->removeColumn(0);
            ui->euler_data_db->removeColumn(1);
            ui->euler_data_db->removeColumn(2);
            ui->euler_data_db->removeColumn(3);

            ui->runge_data_db->removeColumn(0);
            ui->runge_data_db->removeColumn(1);
            ui->runge_data_db->removeColumn(2);
            ui->runge_data_db->removeColumn(3);

            ui->euler_data_db->setColumnCount(4);
            ui->euler_data_db->setRowCount(query_euler.size()+2);

            QHeaderView *header = ui->euler_data_db->horizontalHeader();
            header->setSectionResizeMode(QHeaderView::Stretch);

            ui->euler_data_db->setHorizontalHeader(header);
            ui->euler_data_db->verticalHeader()->setVisible(false);
            ui->euler_data_db->horizontalHeader()->setVisible(false);
            ui->euler_data_db->resizeRowsToContents();



            QTableWidgetItem *headers = new QTableWidgetItem("Метод Эйлера");
            headers->setTextAlignment(Qt::AlignCenter);
            headers->setFont(QFont("Sans Serif", 10, QFont::Bold));

            ui->euler_data_db->setSpan(0,0,1,4);
            ui->euler_data_db->setItem(0, 0, headers);
            ui->euler_data_db->setItem(1, 0, new QTableWidgetItem("x"));
            ui->euler_data_db->setItem(1, 1, new QTableWidgetItem("y1"));
            ui->euler_data_db->setItem(1, 2, new QTableWidgetItem("Точное"));
            ui->euler_data_db->setItem(1, 3, new QTableWidgetItem("Погрешность"));


            ui->runge_data_db->setColumnCount(4);
            ui->runge_data_db->setRowCount(query_runge.size()+2);

            header = ui->runge_data_db->horizontalHeader();
            header->setSectionResizeMode(QHeaderView::Stretch);

            ui->runge_data_db->setHorizontalHeader(header);
            ui->runge_data_db->verticalHeader()->setVisible(false);
            ui->runge_data_db->horizontalHeader()->setVisible(false);
            ui->runge_data_db->resizeRowsToContents();

            headers = new QTableWidgetItem("Метод Рунге-Кутта(4)");
            headers->setTextAlignment(Qt::AlignCenter);
            headers->setFont(QFont("Sans Serif", 10, QFont::Bold));

            ui->runge_data_db->setSpan(0,0,1,4);
            ui->runge_data_db->setItem(0, 0, headers);
            ui->runge_data_db->setItem(1, 0, new QTableWidgetItem("x"));
            ui->runge_data_db->setItem(1, 1, new QTableWidgetItem("y2"));
            ui->runge_data_db->setItem(1, 2, new QTableWidgetItem("Точное"));
            ui->runge_data_db->setItem(1, 3, new QTableWidgetItem("Погрешность"));
            int r = 0;

            while((query_euler.next() && query_runge.next()) && (r < query_euler.size() && r < query_runge.size())){

                           ui->euler_data_db->setItem(r+2, 0, new QTableWidgetItem(QString::number(query_euler.value(1).toDouble(), 'f', 2)));
                           ui->euler_data_db->setItem(r+2, 1, new QTableWidgetItem(QString::number(query_euler.value(2).toDouble(), 'f', 8)));
                           ui->euler_data_db->setItem(r+2, 2, new QTableWidgetItem(QString::number(query_euler.value(3).toDouble(), 'f', 8)));
                           ui->euler_data_db->setItem(r+2, 3, new QTableWidgetItem(QString::number(query_euler.value(4).toDouble(), 'f', 8)));

                           ui->runge_data_db->setItem(r+2, 0, new QTableWidgetItem(QString::number(query_runge.value(1).toDouble(), 'f', 2)));
                           ui->runge_data_db->setItem(r+2, 1, new QTableWidgetItem(QString::number(query_runge.value(2).toDouble(), 'f', 8)));
                           ui->runge_data_db->setItem(r+2, 2, new QTableWidgetItem(QString::number(query_runge.value(3).toDouble(), 'f', 8)));
                           ui->runge_data_db->setItem(r+2, 3, new QTableWidgetItem(QString::number(query_runge.value(4).toDouble(), 'f', 8)));

                           r++;

             }

             data_bd_to_graph();

        } else
            QMessageBox::critical(NULL, QObject::tr("Ошибка чтения данных"), "Ошибка чтения данных<br><br>Информация о ошибке:<br>"
                                        + query_euler.lastError().text() +"<br>"+ query_runge.lastError().text());




    } else {

        QMessageBox::critical(NULL, QObject::tr("Ошибка подключения"), "Ошибка чтения данных<br><br>Информация о ошибке:<br>"
                                    + db.lastError().databaseText());
        db_close();


  }
}



void MainWindow::data_bd_to_graph(){

    QLineSeries *euler_db = new QLineSeries();
    QLineSeries *runge_db = new QLineSeries();
    QPen pen;
    pen.setWidthF(2);

    euler_db->setName("y1");
    euler_db->setPen(pen);
    euler_db->setColor(Qt::GlobalColor::red);

    runge_db ->setName("y2");
    runge_db ->setPen(pen);
    runge_db ->setColor(Qt::GlobalColor::blue);

    for(int i = 2; i < ui->euler_data_db->rowCount(); i++){
        euler_db->append(ui->euler_data_db->item(i,0)->text().toDouble(), ui->euler_data_db->item(i,1)->text().toDouble());
        runge_db ->append(ui->runge_data_db->item(i,0)->text().toDouble(), ui->runge_data_db->item(i,1)->text().toDouble());
    }

    delete chart_from_db;
    chart_from_db = new QChart();
    QChartView *chartView = new QChartView(chart_from_db);
    chart_from_db->addSeries(euler_db);
    chart_from_db->addSeries(runge_db );
    chart_from_db->createDefaultAxes();
    chart_from_db->setTitle("Графики по данным из БД");
    chart_from_db->legend()->setAlignment(Qt::AlignBottom);
    chart_from_db->layout()->setContentsMargins(0, 0, 0, 0);
    chart_from_db->setBackgroundRoundness(0);
    chartView->setRenderHint(QPainter::Antialiasing);
    chartView->setRubberBand(QChartView::HorizontalRubberBand);
    ui->graph_layout_db->removeItem(ui->graph_layout_db->itemAt(0));
    ui->graph_layout_db->addWidget(chartView);


}

void MainWindow::on_clear_bd_clicked() {

   if(db.open()){

       QSqlQuery query;

       if(query.exec("DELETE FROM equation;") &&
          query.exec("DELETE FROM method_euler;") &&
          query.exec("DELETE FROM method_runge;") &&
          query.exec("ALTER SEQUENCE equation_id_seq RESTART;")){

       ui->combo_equ_db->clear();

       ui->euler_data_db->clear();
       ui->euler_data_db->clearContents();
       ui->runge_data_db->clear();
       ui->runge_data_db->clearContents();

       ui->euler_data_db->removeColumn(0);
       ui->euler_data_db->removeColumn(1);
       ui->euler_data_db->removeColumn(2);
       ui->euler_data_db->removeColumn(3);

       ui->runge_data_db->removeColumn(0);
       ui->runge_data_db->removeColumn(1);
       ui->runge_data_db->removeColumn(2);
       ui->runge_data_db->removeColumn(3);
       if(chart_from_db != nullptr)
            chart_from_db->setVisible(false);
       for (int i = 0; i < ui->combo_equ->count(); i++)
             ui->combo_equ->setItemText(i, ui->combo_equ->itemText(i).remove(" ---> в БД"));

       } else QMessageBox::critical(NULL, QObject::tr("Ошибка удаления данных"), "Ошибка удаления данных<br><br>Информация о ошибке:<br>" +
                                          query.lastError().text());



   } else {

       QMessageBox::critical(NULL, QObject::tr("Ошибка подключения"), "Информация о ошибке:<br>" +
                                   db.lastError().databaseText());
       db_close();


}
}

void MainWindow::on_pg_disconnect_clicked() {

   if (db.open()){
          db_close();
   }
}


void MainWindow::db_close() {

    db.close();
    QSqlDatabase::removeDatabase( QSqlDatabase::defaultConnection );

    ui->status_db->setText("Сервер отключен ❌");
    ui->db_driver->setText("");
    ui->combo_equ_db->clear();
    ui->euler_data_db->clear();
    ui->runge_data_db->clear();
    ui->write_to_bd->setVisible(false);
    ui->label_12->setEnabled(false);
    ui->combo_equ_db->setEnabled(false);
    ui->clear_bd->setEnabled(false);
    ui->euler_data_db->setEnabled(false);
    ui->runge_data_db->setEnabled(false);

    if(chart_from_db != nullptr)
        chart_from_db->setVisible(false);

    ui->reset_graph_db->setEnabled(false);

    ui->pg_connect->setEnabled(true);

    for (int i = 0; i < ui->combo_equ->count(); i++)
         ui->combo_equ->setItemText(i, ui->combo_equ->itemText(i).remove(" ---> в БД"));

}
