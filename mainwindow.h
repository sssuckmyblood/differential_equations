#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtCharts>
#include <QLineSeries>
#include <QSqlDatabase>
#include <QSqlQuery>

#include <QSqlError>

#include "equation.h"

using namespace QtCharts;


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow;}

QT_END_NAMESPACE



class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();





private slots:

    void db_create();

    void db_close();

    void on_set_combo_equ_clicked();

    void on_set_line_equ_clicked();

    void on_calculate_clicked();


    void data_to_table(equation &);

    void data_to_graph();

    void data_to_bd();

    void on_a_valueChanged(double arg1);

    void on_b_valueChanged(double arg1);

    void on_y0_valueChanged(double arg1);

    void on_accuracy_valueChanged(double arg1);

    void keyPressEvent(QKeyEvent *event)  Q_DECL_OVERRIDE;

    void on_pgpass_enable_clicked();

    void on_pg_connect_clicked();

    void on_pg_disconnect_clicked();

    void on_write_to_bd_clicked();

    void update_combo_equ();


    void data_bd_to_graph();

    void on_clear_bd_clicked();

    void on_reset_graph_clicked();

    void on_reset_graph_db_clicked();

    void on_tabWidget_currentChanged(int index);

    void on_combo_equ_db_activated(int index);

    void on_combo_equ_activated(int index);

private:
    Ui::MainWindow *ui;
    QChart *chart = nullptr;
    QChart *chart_from_db = nullptr;


};


#endif // MAINWINDOW_H
