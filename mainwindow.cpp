#include "mainwindow.h"
#include "ui_mainwindow.h"




#include <QSqlError>





MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent) , ui(new Ui::MainWindow)
{
    ui->setupUi(this);


    ui->line_equ->setEnabled(false);
    ui->label_2->setEnabled(false);
    ui->write_to_bd->setVisible(false);
    ui->pg_password->setEnabled(false);
    ui->label_9->setEnabled(false);
    ui->label_12->setEnabled(false);
    ui->combo_equ_db->setEnabled(false);
    ui->clear_bd->setEnabled(false);
    ui->euler_data_db->setEnabled(false);
    ui->runge_data_db->setEnabled(false);
    ui->graph_layout_db->setEnabled(false);
    ui->calculate->setVisible(false);
    ui->spinner->setVisible(false);
    ui->spinner->setEnabled(false);
    ui->tabWidget->setCurrentIndex(0);
    ui->combo_equ->activated(0);



}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::on_calculate_clicked()
{


     if(ui->line_equ->isEnabled()){
        equation equ;
        equ.set_custom(ui->a->value(),ui->b->value(),ui->y0->value(),ui->accuracy->value());
        ExpressionEstimator e;
        QString eq = ui->line_equ->text();
        eq.remove(0,2);

        if (eq == "")
            QMessageBox::critical(NULL,QObject::tr("Ошибка"),"Уравнение заданно неверно");

        else {

            eq.replace("x", "x0");
            eq.replace("y", "x1");
            QByteArray ba = eq.toLocal8Bit();
            char *str = ba.data();

            try {
                e.compile(str);

            } catch (...) {

              QMessageBox::critical(NULL,QObject::tr("Ошибка"),"Уравнение заданно неверно");


            }

            equ.method_euler_custom(e);
            equ.method_runge_custom(e);
            data_to_table(equ);
            ui->write_to_bd->setEnabled(true);
        }

     }


}

void MainWindow::on_combo_equ_activated(int index)
{
    if(ui->combo_equ->isEnabled()){


        equation equ;
        if(ui->a->value() < ui->b->value()){

         ui->y0_text->setText("y("+QString::number(ui->a->value(), 'g', 3)+")= ");

         equ.set(ui->combo_equ->currentIndex(), ui->a->value(),ui->b->value(),ui->y0->value(),ui->accuracy->value());

         equ.method_euler();
         equ.method_runge();


         data_to_table(equ);
         ui->write_to_bd->setEnabled(true);


        }

    }
}

void MainWindow::data_to_table(equation& equ){

    ui->euler_data->clear();
    ui->euler_data->clearContents();
    ui->runge_data->clear();
    ui->runge_data->clearContents();

    ui->euler_data->removeColumn(0);
    ui->euler_data->removeColumn(1);
    ui->euler_data->removeColumn(2);
    ui->euler_data->removeColumn(3);

    ui->runge_data->removeColumn(0);
    ui->runge_data->removeColumn(1);
    ui->runge_data->removeColumn(2);
    ui->runge_data->removeColumn(3);

    ui->euler_data->setColumnCount(4);
    ui->euler_data->setRowCount(equ.size+2);

    QHeaderView *header = ui->euler_data->horizontalHeader();
    header->setSectionResizeMode(QHeaderView::Stretch);

    ui->euler_data->setHorizontalHeader(header);
    ui->euler_data->verticalHeader()->setVisible(false);
    ui->euler_data->horizontalHeader()->setVisible(false);
    ui->euler_data->resizeRowsToContents();

    QTableWidgetItem *headers = new QTableWidgetItem("Метод Эйлера");
    headers->setTextAlignment(Qt::AlignCenter);
    headers->setFont(QFont("Sans Serif", 10, QFont::Bold));
    ui->euler_data->setSpan(0,0,1,4);
    ui->euler_data->setItem(0, 0, headers);
    ui->euler_data->setItem(1, 0, new QTableWidgetItem("x"));
    ui->euler_data->setItem(1, 1, new QTableWidgetItem("y1"));
    ui->euler_data->setItem(1, 2, new QTableWidgetItem("Точное"));
    ui->euler_data->setItem(1, 3, new QTableWidgetItem("Погрешность"));

    ui->runge_data->setColumnCount(4);
    ui->runge_data->setRowCount(equ.size+2);

    header = ui->runge_data->horizontalHeader();
    header->setSectionResizeMode(QHeaderView::Stretch);

    ui->runge_data->setHorizontalHeader(header);
    ui->runge_data->verticalHeader()->setVisible(false);
    ui->runge_data->horizontalHeader()->setVisible(false);
    ui->runge_data->resizeRowsToContents();

    headers = new QTableWidgetItem("Метод Рунге-Кутта(4)");
    headers->setTextAlignment(Qt::AlignCenter);
    headers->setFont(QFont("Sans Serif", 10, QFont::Bold));

    ui->runge_data->setSpan(0,0,1,4);
    ui->runge_data->setItem(0, 0, headers);
    ui->runge_data->setItem(1, 0, new QTableWidgetItem("x"));
    ui->runge_data->setItem(1, 1, new QTableWidgetItem("y2"));
    ui->runge_data->setItem(1, 2, new QTableWidgetItem("Точное"));
    ui->runge_data->setItem(1, 3, new QTableWidgetItem("Погрешность"));


     if(ui->combo_equ->isEnabled()){
        for (int r=0; r<equ.size; r++){

              ui->euler_data->setItem(r+2, 0, new QTableWidgetItem(QString::number(equ.x[r], 'f', 2)));
              ui->euler_data->setItem(r+2, 1, new QTableWidgetItem(QString::number(equ.result_euler[r], 'f', 8)));
              ui->euler_data->setItem(r+2, 2, new QTableWidgetItem(QString::number(equ.result_analytical[r], 'f', 8)));
              ui->euler_data->setItem(r+2, 3, new QTableWidgetItem(QString::number(equ.error_euler[r], 'f', 8)));

              ui->runge_data->setItem(r+2, 0, new QTableWidgetItem(QString::number(equ.x[r], 'f', 2)));
              ui->runge_data->setItem(r+2, 1, new QTableWidgetItem(QString::number(equ.result_runge[r], 'f', 8)));
              ui->runge_data->setItem(r+2, 2, new QTableWidgetItem(QString::number(equ.result_analytical[r], 'f', 8)));
              ui->runge_data->setItem(r+2, 3, new QTableWidgetItem(QString::number(equ.error_runge[r], 'f', 8)));
        }

       } else {
         for (int r=0; r<equ.size; r++){

               ui->euler_data->setItem(r+2, 0, new QTableWidgetItem(QString::number(equ.x[r], 'f', 2)));
               ui->euler_data->setItem(r+2, 1, new QTableWidgetItem(QString::number(equ.result_euler[r], 'f', 8)));
               ui->euler_data->setItem(r+2, 2, new QTableWidgetItem(QString::number(0, 'f', 8)));
               ui->euler_data->setItem(r+2, 3, new QTableWidgetItem(QString::number(0, 'f', 8)));

               ui->runge_data->setItem(r+2, 0, new QTableWidgetItem(QString::number(equ.x[r], 'f', 2)));
               ui->runge_data->setItem(r+2, 1, new QTableWidgetItem(QString::number(equ.result_runge[r], 'f', 8)));
               ui->runge_data->setItem(r+2, 2, new QTableWidgetItem(QString::number(0, 'f', 8)));
               ui->runge_data->setItem(r+2, 3, new QTableWidgetItem(QString::number(0, 'f', 8)));
         }

     }

      data_to_graph();

}


void MainWindow::data_to_graph(){

   QLineSeries *euler_s = new QLineSeries();
   QLineSeries *runge_s = new QLineSeries();
   QPen pen;
   pen.setWidthF(2);

   euler_s->setName("y1");
   euler_s->setPen(pen);
   euler_s->setColor(Qt::GlobalColor::red);

   runge_s->setName("y2");
   runge_s->setPen(pen);
   runge_s->setColor(Qt::GlobalColor::blue);

   for(int i = 2; i < ui->euler_data->rowCount(); i++){
               euler_s->append(ui->euler_data->item(i,0)->text().toDouble(),  ui->euler_data->item(i,1)->text().toDouble());
               runge_s->append(ui->runge_data->item(i,0)->text().toDouble(),  ui->runge_data->item(i,1)->text().toDouble());
   }

   delete chart;
   chart = new QChart();
   chart->addSeries(euler_s);
   chart->addSeries(runge_s);
   chart->createDefaultAxes();
   chart->setTitle("Графики по результатам вычислений");
   chart->legend()->setAlignment(Qt::AlignBottom);
   chart->layout()->setContentsMargins(0, 0, 0, 0);
   chart->setBackgroundRoundness(0);
   QChartView *chartView = new QChartView(chart);
   chartView->setRenderHint(QPainter::Antialiasing);
   chartView->setRubberBand(QChartView::HorizontalRubberBand);
   ui->graph_layout->removeItem(ui->graph_layout->itemAt(0));
   ui->graph_layout->addWidget(chartView);


}



void MainWindow::on_a_valueChanged(double arg1) {
    if(ui->combo_equ->isEnabled())
         on_combo_equ_activated(ui->combo_equ->currentIndex());
}

void MainWindow::on_b_valueChanged(double arg1) {
    if(ui->combo_equ->isEnabled())
          on_combo_equ_activated(ui->combo_equ->currentIndex());
}

void MainWindow::on_y0_valueChanged(double arg1) {
    if(ui->combo_equ->isEnabled())
           on_combo_equ_activated(ui->combo_equ->currentIndex());
}

void MainWindow::on_accuracy_valueChanged(double arg1) {
    if(ui->combo_equ->isEnabled())
        on_combo_equ_activated(ui->combo_equ->currentIndex());
}

void MainWindow::on_set_combo_equ_clicked() {

    ui->combo_equ->setEnabled(true);
    ui->label->setEnabled(true);

    ui->line_equ->setEnabled(false);
    ui->label_2->setEnabled(false);
    ui->calculate->setVisible(false);




}

void MainWindow::on_set_line_equ_clicked() {

    ui->line_equ->setEnabled(true);
    ui->label_2->setEnabled(true);
    ui->calculate->setVisible(true);

    ui->combo_equ->setEnabled(false);
    ui->label->setEnabled(false);
}

void MainWindow::on_pgpass_enable_clicked() {

    if(!ui->pg_password->isEnabled()){

        ui->pg_password->setEnabled(true);
        ui->label_9->setEnabled(true);

    } else {

        ui->pg_password->setEnabled(false);
        ui->label_9->setEnabled(false);

    }

}



void MainWindow::keyPressEvent(QKeyEvent *event) {

    switch (event->key()) {

    case Qt::Key_Plus:

        if(ui->tabWidget->currentIndex() == 0)
            chart->zoomIn();
        else
            chart_from_db->zoomIn();
        break;

    case Qt::Key_Minus:

        if(ui->tabWidget->currentIndex() == 0)
            chart->zoomOut();
        else
            chart_from_db->zoomOut();
        break;

    case Qt::Key_PageUp:

        if(ui->tabWidget->currentIndex() == 0)
            chart->zoomIn();
        else
            chart_from_db->zoomIn();
        break;

    case Qt::Key_PageDown:

        if(ui->tabWidget->currentIndex() == 0)
            chart->zoomOut();
        else
            chart_from_db->zoomOut();
        break;

    case Qt::Key_A: //left

        if(ui->tabWidget->currentIndex() == 0)
            chart->scroll(-1, 0);
        else
            chart_from_db->scroll(-1, 0);
        break;

    case Qt::Key_D:  //right

        if(ui->tabWidget->currentIndex() == 0)
            chart->scroll(1, 0);
        else
            chart_from_db->scroll(1, 0);
        break;

    case Qt::Key_W:  //up

        if(ui->tabWidget->currentIndex() == 0)
            chart->scroll(0, 1);
        else
            chart_from_db->scroll(0, 1);
        break;

    case Qt::Key_S:  // down

        if(ui->tabWidget->currentIndex() == 0)
            chart->scroll(0, -1);
        else
            chart_from_db->scroll(0, -1);
        break;

    case Qt::Key_Left:

        if(ui->tabWidget->currentIndex() == 0)
            chart->scroll(-1, 0);
        else
            chart_from_db->scroll(-1, 0);
        break;

    case Qt::Key_Right:

        if(ui->tabWidget->currentIndex() == 0)
            chart->scroll(1, 0);
        else
            chart_from_db->scroll(1, 0);
        break;

    case Qt::Key_Up:

        if(ui->tabWidget->currentIndex() == 0)
            chart->scroll(0, 1);
        else
            chart_from_db->scroll(0, 1);
        break;

    case Qt::Key_Down:

        if(ui->tabWidget->currentIndex() == 0)
            chart->scroll(0, -1);
        else
            chart_from_db->scroll(0, -1);
        break;


    }
}



void MainWindow::on_reset_graph_clicked() {
    data_to_graph();
}


void MainWindow::on_reset_graph_db_clicked() {
   data_bd_to_graph();
}






