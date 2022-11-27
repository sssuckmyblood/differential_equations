/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QTabWidget *tabWidget;
    QWidget *tab;
    QGroupBox *groupBox;
    QLabel *label;
    QLineEdit *line_equ;
    QComboBox *combo_equ;
    QLabel *label_2;
    QRadioButton *set_combo_equ;
    QRadioButton *set_line_equ;
    QPushButton *calculate;
    QLabel *label_3;
    QDoubleSpinBox *a;
    QDoubleSpinBox *b;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *y0_text;
    QDoubleSpinBox *y0;
    QLabel *label_7;
    QDoubleSpinBox *accuracy;
    QPushButton *write_to_bd;
    QTableWidget *euler_data;
    QTableWidget *runge_data;
    QWidget *gridLayoutWidget;
    QGridLayout *graph_layout;
    QPushButton *reset_graph;
    QWidget *tab_2;
    QTableWidget *euler_data_db;
    QWidget *gridLayoutWidget_2;
    QGridLayout *graph_layout_db;
    QLabel *label_12;
    QComboBox *combo_equ_db;
    QTableWidget *runge_data_db;
    QPushButton *clear_bd;
    QPushButton *reset_graph_db;
    QWidget *tab_3;
    QGroupBox *groupBox_2;
    QLineEdit *pg_bd;
    QLabel *label_11;
    QLabel *label_9;
    QLineEdit *pg_password;
    QLineEdit *pg_user;
    QLineEdit *pg_ip;
    QLabel *label_6;
    QLabel *label_8;
    QSpinBox *pg_port;
    QLabel *label_10;
    QPushButton *pg_connect;
    QRadioButton *pgpass_enable;
    QPushButton *pg_disconnect;
    QLabel *label_13;
    QLabel *status_db;
    QLabel *label_15;
    QLabel *db_driver;
    QLabel *spinner;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1814, 700);
        MainWindow->setMinimumSize(QSize(1614, 670));
        MainWindow->setMaximumSize(QSize(1814, 700));
        QIcon icon;
        icon.addFile(QString::fromUtf8("favicon.ico"), QSize(), QIcon::Normal, QIcon::Off);
        MainWindow->setWindowIcon(icon);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        centralwidget->setMinimumSize(QSize(1614, 670));
        centralwidget->setMaximumSize(QSize(1814, 700));
        centralwidget->setAutoFillBackground(false);
        tabWidget = new QTabWidget(centralwidget);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabWidget->setGeometry(QRect(0, 0, 1814, 700));
        tabWidget->setMinimumSize(QSize(1814, 700));
        tabWidget->setMaximumSize(QSize(1814, 700));
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        groupBox = new QGroupBox(tab);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(80, 10, 1031, 141));
        label = new QLabel(groupBox);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(40, 38, 167, 18));
        QFont font;
        font.setFamily(QString::fromUtf8("Sans Serif"));
        font.setPointSize(9);
        label->setFont(font);
        line_equ = new QLineEdit(groupBox);
        line_equ->setObjectName(QString::fromUtf8("line_equ"));
        line_equ->setEnabled(true);
        line_equ->setGeometry(QRect(672, 34, 184, 28));
        combo_equ = new QComboBox(groupBox);
        combo_equ->addItem(QString());
        combo_equ->addItem(QString());
        combo_equ->addItem(QString());
        combo_equ->addItem(QString());
        combo_equ->addItem(QString());
        combo_equ->addItem(QString());
        combo_equ->setObjectName(QString::fromUtf8("combo_equ"));
        combo_equ->setGeometry(QRect(220, 35, 184, 28));
        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setEnabled(true);
        label_2->setGeometry(QRect(500, 40, 156, 18));
        label_2->setFont(font);
        set_combo_equ = new QRadioButton(groupBox);
        set_combo_equ->setObjectName(QString::fromUtf8("set_combo_equ"));
        set_combo_equ->setGeometry(QRect(11, 37, 17, 18));
        set_combo_equ->setChecked(true);
        set_line_equ = new QRadioButton(groupBox);
        set_line_equ->setObjectName(QString::fromUtf8("set_line_equ"));
        set_line_equ->setGeometry(QRect(470, 40, 17, 18));
        calculate = new QPushButton(groupBox);
        calculate->setObjectName(QString::fromUtf8("calculate"));
        calculate->setGeometry(QRect(877, 33, 111, 31));
        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(118, 87, 77, 18));
        label_3->setFont(font);
        a = new QDoubleSpinBox(groupBox);
        a->setObjectName(QString::fromUtf8("a"));
        a->setGeometry(QRect(201, 80, 81, 31));
        a->setMinimum(-100.000000000000000);
        a->setMaximum(100.000000000000000);
        a->setSingleStep(0.100000000000000);
        a->setValue(1.000000000000000);
        b = new QDoubleSpinBox(groupBox);
        b->setObjectName(QString::fromUtf8("b"));
        b->setGeometry(QRect(306, 79, 81, 31));
        b->setMinimum(-100.000000000000000);
        b->setMaximum(100.000000000000000);
        b->setSingleStep(0.100000000000000);
        b->setValue(2.000000000000000);
        label_4 = new QLabel(groupBox);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(290, 82, 6, 26));
        label_4->setFont(font);
        label_5 = new QLabel(groupBox);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(396, 80, 8, 26));
        label_5->setFont(font);
        y0_text = new QLabel(groupBox);
        y0_text->setObjectName(QString::fromUtf8("y0_text"));
        y0_text->setGeometry(QRect(422, 84, 51, 21));
        y0_text->setFont(font);
        y0 = new QDoubleSpinBox(groupBox);
        y0->setObjectName(QString::fromUtf8("y0"));
        y0->setGeometry(QRect(478, 80, 81, 31));
        y0->setMinimum(-100.000000000000000);
        y0->setMaximum(100.000000000000000);
        y0->setSingleStep(0.100000000000000);
        y0->setValue(2.000000000000000);
        label_7 = new QLabel(groupBox);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(580, 84, 87, 22));
        label_7->setFont(font);
        accuracy = new QDoubleSpinBox(groupBox);
        accuracy->setObjectName(QString::fromUtf8("accuracy"));
        accuracy->setGeometry(QRect(671, 80, 111, 31));
        accuracy->setDecimals(5);
        accuracy->setMinimum(0.000010000000000);
        accuracy->setMaximum(100.000000000000000);
        accuracy->setSingleStep(0.000010000000000);
        accuracy->setValue(0.100000000000000);
        write_to_bd = new QPushButton(groupBox);
        write_to_bd->setObjectName(QString::fromUtf8("write_to_bd"));
        write_to_bd->setGeometry(QRect(868, 80, 128, 30));
        euler_data = new QTableWidget(tab);
        euler_data->setObjectName(QString::fromUtf8("euler_data"));
        euler_data->setGeometry(QRect(10, 170, 542, 481));
        euler_data->horizontalHeader()->setMinimumSectionSize(32);
        euler_data->horizontalHeader()->setDefaultSectionSize(200);
        euler_data->horizontalHeader()->setStretchLastSection(false);
        runge_data = new QTableWidget(tab);
        runge_data->setObjectName(QString::fromUtf8("runge_data"));
        runge_data->setGeometry(QRect(580, 170, 542, 481));
        runge_data->horizontalHeader()->setMinimumSectionSize(32);
        runge_data->horizontalHeader()->setDefaultSectionSize(200);
        runge_data->horizontalHeader()->setStretchLastSection(false);
        gridLayoutWidget = new QWidget(tab);
        gridLayoutWidget->setObjectName(QString::fromUtf8("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(1140, 0, 661, 651));
        graph_layout = new QGridLayout(gridLayoutWidget);
        graph_layout->setObjectName(QString::fromUtf8("graph_layout"));
        graph_layout->setContentsMargins(0, 0, 0, 0);
        reset_graph = new QPushButton(tab);
        reset_graph->setObjectName(QString::fromUtf8("reset_graph"));
        reset_graph->setGeometry(QRect(1730, 0, 80, 24));
        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
        euler_data_db = new QTableWidget(tab_2);
        euler_data_db->setObjectName(QString::fromUtf8("euler_data_db"));
        euler_data_db->setGeometry(QRect(10, 60, 542, 581));
        euler_data_db->horizontalHeader()->setMinimumSectionSize(32);
        euler_data_db->horizontalHeader()->setDefaultSectionSize(200);
        euler_data_db->horizontalHeader()->setStretchLastSection(false);
        gridLayoutWidget_2 = new QWidget(tab_2);
        gridLayoutWidget_2->setObjectName(QString::fromUtf8("gridLayoutWidget_2"));
        gridLayoutWidget_2->setGeometry(QRect(1130, 0, 681, 671));
        graph_layout_db = new QGridLayout(gridLayoutWidget_2);
        graph_layout_db->setObjectName(QString::fromUtf8("graph_layout_db"));
        graph_layout_db->setContentsMargins(0, 0, 0, 0);
        label_12 = new QLabel(tab_2);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        label_12->setGeometry(QRect(30, 20, 100, 14));
        label_12->setFont(font);
        combo_equ_db = new QComboBox(tab_2);
        combo_equ_db->setObjectName(QString::fromUtf8("combo_equ_db"));
        combo_equ_db->setGeometry(QRect(150, 10, 821, 28));
        runge_data_db = new QTableWidget(tab_2);
        runge_data_db->setObjectName(QString::fromUtf8("runge_data_db"));
        runge_data_db->setGeometry(QRect(570, 60, 542, 581));
        runge_data_db->horizontalHeader()->setMinimumSectionSize(32);
        runge_data_db->horizontalHeader()->setDefaultSectionSize(200);
        runge_data_db->horizontalHeader()->setStretchLastSection(false);
        clear_bd = new QPushButton(tab_2);
        clear_bd->setObjectName(QString::fromUtf8("clear_bd"));
        clear_bd->setGeometry(QRect(990, 10, 111, 31));
        reset_graph_db = new QPushButton(tab_2);
        reset_graph_db->setObjectName(QString::fromUtf8("reset_graph_db"));
        reset_graph_db->setGeometry(QRect(1730, 0, 80, 24));
        tabWidget->addTab(tab_2, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName(QString::fromUtf8("tab_3"));
        groupBox_2 = new QGroupBox(tab_3);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setGeometry(QRect(288, 10, 1152, 288));
        QFont font1;
        font1.setKerning(true);
        groupBox_2->setFont(font1);
        groupBox_2->setAlignment(Qt::AlignCenter);
        pg_bd = new QLineEdit(groupBox_2);
        pg_bd->setObjectName(QString::fromUtf8("pg_bd"));
        pg_bd->setGeometry(QRect(510, 207, 184, 31));
        label_11 = new QLabel(groupBox_2);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setGeometry(QRect(720, 57, 44, 21));
        label_9 = new QLabel(groupBox_2);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setGeometry(QRect(270, 160, 64, 21));
        pg_password = new QLineEdit(groupBox_2);
        pg_password->setObjectName(QString::fromUtf8("pg_password"));
        pg_password->setGeometry(QRect(510, 154, 184, 31));
        pg_password->setEchoMode(QLineEdit::PasswordEchoOnEdit);
        pg_user = new QLineEdit(groupBox_2);
        pg_user->setObjectName(QString::fromUtf8("pg_user"));
        pg_user->setGeometry(QRect(510, 104, 184, 31));
        pg_ip = new QLineEdit(groupBox_2);
        pg_ip->setObjectName(QString::fromUtf8("pg_ip"));
        pg_ip->setGeometry(QRect(510, 53, 184, 31));
        label_6 = new QLabel(groupBox_2);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(270, 60, 157, 16));
        label_8 = new QLabel(groupBox_2);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(270, 110, 223, 21));
        pg_port = new QSpinBox(groupBox_2);
        pg_port->setObjectName(QString::fromUtf8("pg_port"));
        pg_port->setGeometry(QRect(790, 50, 92, 37));
        pg_port->setMinimum(1);
        pg_port->setMaximum(65535);
        pg_port->setValue(5432);
        label_10 = new QLabel(groupBox_2);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setGeometry(QRect(270, 210, 108, 21));
        pg_connect = new QPushButton(groupBox_2);
        pg_connect->setObjectName(QString::fromUtf8("pg_connect"));
        pg_connect->setGeometry(QRect(720, 210, 117, 30));
        pgpass_enable = new QRadioButton(groupBox_2);
        pgpass_enable->setObjectName(QString::fromUtf8("pgpass_enable"));
        pgpass_enable->setGeometry(QRect(240, 162, 17, 18));
        pg_disconnect = new QPushButton(groupBox_2);
        pg_disconnect->setObjectName(QString::fromUtf8("pg_disconnect"));
        pg_disconnect->setGeometry(QRect(860, 210, 117, 30));
        label_13 = new QLabel(groupBox_2);
        label_13->setObjectName(QString::fromUtf8("label_13"));
        label_13->setGeometry(QRect(720, 110, 39, 16));
        status_db = new QLabel(groupBox_2);
        status_db->setObjectName(QString::fromUtf8("status_db"));
        status_db->setGeometry(QRect(790, 110, 191, 21));
        label_15 = new QLabel(groupBox_2);
        label_15->setObjectName(QString::fromUtf8("label_15"));
        label_15->setGeometry(QRect(720, 160, 50, 16));
        db_driver = new QLabel(groupBox_2);
        db_driver->setObjectName(QString::fromUtf8("db_driver"));
        db_driver->setGeometry(QRect(790, 160, 201, 21));
        spinner = new QLabel(tab_3);
        spinner->setObjectName(QString::fromUtf8("spinner"));
        spinner->setGeometry(QRect(835, 278, 145, 145));
        spinner->setAlignment(Qt::AlignCenter);
        tabWidget->addTab(tab_3, QString());
        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(2);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "\320\224\320\270\321\204\321\204\320\265\321\200\320\265\320\275\321\206\320\270\320\260\320\273\321\214\320\275\321\213\320\265 \321\203\321\200\320\260\320\262\320\275\320\265\320\275\320\270\321\217", nullptr));
        groupBox->setTitle(QCoreApplication::translate("MainWindow", "\320\243\321\200\320\260\320\262\320\275\320\265\320\275\320\270\321\217", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "\320\222\321\213\320\261\320\265\321\200\320\270\321\202\320\265 \321\203\321\200\320\260\320\262\320\275\320\265\320\275\320\270\320\265", nullptr));
        combo_equ->setItemText(0, QCoreApplication::translate("MainWindow", "y'= -x-y+(y/x)", nullptr));
        combo_equ->setItemText(1, QCoreApplication::translate("MainWindow", "y'= (1-y^2)/(2*x)", nullptr));
        combo_equ->setItemText(2, QCoreApplication::translate("MainWindow", "y'= x^2-2y", nullptr));
        combo_equ->setItemText(3, QCoreApplication::translate("MainWindow", "y'= e^(-sin(x))-y*cos(x)", nullptr));
        combo_equ->setItemText(4, QCoreApplication::translate("MainWindow", "y'= -((y^2-y)/(x+1))", nullptr));
        combo_equ->setItemText(5, QCoreApplication::translate("MainWindow", "y'= y/(-1-x)", nullptr));

        label_2->setText(QCoreApplication::translate("MainWindow", "\320\222\320\262\320\265\320\264\320\270\321\202\320\265 \321\203\321\200\320\260\320\262\320\275\320\265\320\275\320\270\320\265", nullptr));
        set_combo_equ->setText(QString());
        set_line_equ->setText(QString());
        calculate->setText(QCoreApplication::translate("MainWindow", "\320\240\320\260\321\201\321\207\320\270\321\202\320\260\321\202\321\214", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "\320\236\321\202\321\200\320\265\320\267\320\276\320\272 [", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", ";", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "]", nullptr));
        y0_text->setText(QCoreApplication::translate("MainWindow", "y()=", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindow", "\320\242\320\276\321\207\320\275\320\276\321\201\321\202\321\214", nullptr));
        write_to_bd->setText(QCoreApplication::translate("MainWindow", "\320\227\320\260\320\277\320\270\321\201\320\260\321\202\321\214 \320\262 \320\221\320\224", nullptr));
        reset_graph->setText(QCoreApplication::translate("MainWindow", "\320\241\320\261\321\200\320\276\321\201\320\270\321\202\321\214", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab), QCoreApplication::translate("MainWindow", "\320\222\321\213\321\207\320\270\321\201\320\273\320\265\320\275\320\270\321\217", nullptr));
        label_12->setText(QCoreApplication::translate("MainWindow", "\320\222\321\213\320\261\320\265\321\200\320\270\321\202\320\265 \320\267\320\260\320\277\320\270\321\201\321\214", nullptr));
        clear_bd->setText(QCoreApplication::translate("MainWindow", "\320\236\321\207\320\270\321\201\321\202\320\270\321\202\321\214 \320\221\320\224", nullptr));
        reset_graph_db->setText(QCoreApplication::translate("MainWindow", "\320\241\320\261\321\200\320\276\321\201\320\270\321\202\321\214", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QCoreApplication::translate("MainWindow", "\320\221\320\224", nullptr));
        groupBox_2->setTitle(QCoreApplication::translate("MainWindow", "\320\237\320\260\321\200\320\260\320\274\320\265\321\202\321\200\321\213 \320\277\320\276\320\264\320\272\320\273\321\216\321\207\320\265\320\275\320\270\321\217", nullptr));
        pg_bd->setText(QCoreApplication::translate("MainWindow", "equation", nullptr));
        label_11->setText(QCoreApplication::translate("MainWindow", "\320\237\320\276\321\200\321\202", nullptr));
        label_9->setText(QCoreApplication::translate("MainWindow", "\320\237\320\260\321\200\320\276\320\273\321\214", nullptr));
        pg_user->setText(QCoreApplication::translate("MainWindow", "postgres", nullptr));
        pg_ip->setText(QCoreApplication::translate("MainWindow", "localhost", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "ip-\320\260\320\264\321\200\320\265\321\201 \321\201\320\265\321\200\320\262\320\265\321\200\320\260 PostgreSQL", nullptr));
        label_8->setText(QCoreApplication::translate("MainWindow", "\320\237\320\276\320\273\321\214\320\267\320\276\320\262\320\260\321\202\320\265\320\273\321\214 PostgreSQL", nullptr));
        label_10->setText(QCoreApplication::translate("MainWindow", "\320\221\320\260\320\267\320\260 \320\264\320\260\320\275\320\275\321\213\321\205", nullptr));
        pg_connect->setText(QCoreApplication::translate("MainWindow", "\320\237\320\276\320\264\320\272\320\273\321\216\321\207\320\270\321\202\321\214", nullptr));
        pgpass_enable->setText(QString());
        pg_disconnect->setText(QCoreApplication::translate("MainWindow", "\320\236\321\202\320\272\320\273\321\216\321\207\320\270\321\202\321\214", nullptr));
        label_13->setText(QCoreApplication::translate("MainWindow", "\320\241\321\202\320\260\321\202\321\203\321\201:", nullptr));
        status_db->setText(QCoreApplication::translate("MainWindow", "\320\236\321\204\321\204\320\273\320\260\320\271\320\275", nullptr));
        label_15->setText(QCoreApplication::translate("MainWindow", "\320\224\321\200\320\260\320\271\320\262\320\265\321\200:", nullptr));
        db_driver->setText(QString());
        spinner->setText(QString());
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QCoreApplication::translate("MainWindow", "\320\235\320\260\321\201\321\202\321\200\320\276\320\271\320\272\320\270 \320\221\320\224", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
