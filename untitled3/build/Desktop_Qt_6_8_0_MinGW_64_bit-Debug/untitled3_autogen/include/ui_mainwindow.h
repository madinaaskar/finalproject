/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QLabel *label;
    QLineEdit *lineEditUsername;
    QPushButton *buttonRegister;
    QTableWidget *tableWidgetPasswords;
    QPushButton *buttonAdd;
    QPushButton *buttonDelete;
    QPushButton *buttonEdit;
    QPushButton *buttonGenerate;
    QLineEdit *lineEditGrade;
    QPushButton *addGradeButton;
    QLabel *labelAverage;
    QLabel *label_3;
    QTableWidget *tableWidgetGrades;
    QLabel *label_4;
    QLineEdit *lineEditPassword;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1383, 687);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setGeometry(QRect(40, 10, 141, 20));
        lineEditUsername = new QLineEdit(centralwidget);
        lineEditUsername->setObjectName("lineEditUsername");
        lineEditUsername->setGeometry(QRect(190, 10, 113, 28));
        buttonRegister = new QPushButton(centralwidget);
        buttonRegister->setObjectName("buttonRegister");
        buttonRegister->setGeometry(QRect(330, 10, 83, 29));
        tableWidgetPasswords = new QTableWidget(centralwidget);
        if (tableWidgetPasswords->columnCount() < 2)
            tableWidgetPasswords->setColumnCount(2);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidgetPasswords->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidgetPasswords->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        tableWidgetPasswords->setObjectName("tableWidgetPasswords");
        tableWidgetPasswords->setGeometry(QRect(40, 90, 256, 192));
        buttonAdd = new QPushButton(centralwidget);
        buttonAdd->setObjectName("buttonAdd");
        buttonAdd->setGeometry(QRect(640, 110, 81, 31));
        buttonDelete = new QPushButton(centralwidget);
        buttonDelete->setObjectName("buttonDelete");
        buttonDelete->setGeometry(QRect(640, 150, 83, 29));
        buttonEdit = new QPushButton(centralwidget);
        buttonEdit->setObjectName("buttonEdit");
        buttonEdit->setGeometry(QRect(640, 190, 83, 29));
        buttonGenerate = new QPushButton(centralwidget);
        buttonGenerate->setObjectName("buttonGenerate");
        buttonGenerate->setGeometry(QRect(330, 40, 83, 29));
        lineEditGrade = new QLineEdit(centralwidget);
        lineEditGrade->setObjectName("lineEditGrade");
        lineEditGrade->setGeometry(QRect(750, 80, 113, 28));
        addGradeButton = new QPushButton(centralwidget);
        addGradeButton->setObjectName("addGradeButton");
        addGradeButton->setGeometry(QRect(870, 80, 91, 29));
        labelAverage = new QLabel(centralwidget);
        labelAverage->setObjectName("labelAverage");
        labelAverage->setGeometry(QRect(840, 130, 211, 51));
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(640, 80, 191, 16));
        tableWidgetGrades = new QTableWidget(centralwidget);
        if (tableWidgetGrades->columnCount() < 2)
            tableWidgetGrades->setColumnCount(2);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableWidgetGrades->setHorizontalHeaderItem(0, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tableWidgetGrades->setHorizontalHeaderItem(1, __qtablewidgetitem3);
        tableWidgetGrades->setObjectName("tableWidgetGrades");
        tableWidgetGrades->setGeometry(QRect(360, 90, 256, 192));
        label_4 = new QLabel(centralwidget);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(40, 40, 141, 20));
        lineEditPassword = new QLineEdit(centralwidget);
        lineEditPassword->setObjectName("lineEditPassword");
        lineEditPassword->setGeometry(QRect(190, 40, 113, 28));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1383, 25));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Enter your nickname", nullptr));
        buttonRegister->setText(QCoreApplication::translate("MainWindow", "Register", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tableWidgetPasswords->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("MainWindow", "Nickname", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidgetPasswords->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("MainWindow", "Password", nullptr));
        buttonAdd->setText(QCoreApplication::translate("MainWindow", "Add", nullptr));
        buttonDelete->setText(QCoreApplication::translate("MainWindow", "Delete", nullptr));
        buttonEdit->setText(QCoreApplication::translate("MainWindow", "Edit", nullptr));
        buttonGenerate->setText(QCoreApplication::translate("MainWindow", "Generate", nullptr));
        addGradeButton->setText(QCoreApplication::translate("MainWindow", "Add Grade", nullptr));
        labelAverage->setText(QCoreApplication::translate("MainWindow", "Average Grade", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "Enter grade:", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidgetGrades->horizontalHeaderItem(0);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("MainWindow", "Subject", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidgetGrades->horizontalHeaderItem(1);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("MainWindow", "Grade", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "Enter your password: ", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
