/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.13
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
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
    QGraphicsView *graphicsView;
    QTableWidget *DotTable;
    QLabel *label;
    QDoubleSpinBox *xDot;
    QDoubleSpinBox *yDot;
    QLabel *label_2;
    QLabel *label_3;
    QPushButton *AddDot;
    QPushButton *randomButton;
    QPushButton *deleteButton;
    QDoubleSpinBox *mashtabKoef;
    QLabel *label_4;
    QDoubleSpinBox *CenterX;
    QDoubleSpinBox *CenterY;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_7;
    QPushButton *scaleButton;
    QPushButton *solveButton;
    QPushButton *cleanButton;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1283, 714);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        graphicsView = new QGraphicsView(centralwidget);
        graphicsView->setObjectName(QString::fromUtf8("graphicsView"));
        graphicsView->setGeometry(QRect(0, 0, 991, 661));
        DotTable = new QTableWidget(centralwidget);
        DotTable->setObjectName(QString::fromUtf8("DotTable"));
        DotTable->setGeometry(QRect(1000, 20, 256, 201));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(1070, 0, 141, 16));
        label->setStyleSheet(QString::fromUtf8("font: 800 italic 10pt \"Ubuntu Sans\";\n"
"color: rgb(237, 51, 59);\n"
""));
        xDot = new QDoubleSpinBox(centralwidget);
        xDot->setObjectName(QString::fromUtf8("xDot"));
        xDot->setGeometry(QRect(1020, 250, 101, 31));
        xDot->setMinimumSize(QSize(101, 0));
        yDot = new QDoubleSpinBox(centralwidget);
        yDot->setObjectName(QString::fromUtf8("yDot"));
        yDot->setGeometry(QRect(1140, 250, 101, 31));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(1060, 230, 21, 16));
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(1180, 230, 16, 16));
        AddDot = new QPushButton(centralwidget);
        AddDot->setObjectName(QString::fromUtf8("AddDot"));
        AddDot->setGeometry(QRect(1090, 290, 101, 23));
        randomButton = new QPushButton(centralwidget);
        randomButton->setObjectName(QString::fromUtf8("randomButton"));
        randomButton->setGeometry(QRect(1020, 330, 231, 23));
        deleteButton = new QPushButton(centralwidget);
        deleteButton->setObjectName(QString::fromUtf8("deleteButton"));
        deleteButton->setGeometry(QRect(1020, 370, 231, 23));
        mashtabKoef = new QDoubleSpinBox(centralwidget);
        mashtabKoef->setObjectName(QString::fromUtf8("mashtabKoef"));
        mashtabKoef->setGeometry(QRect(1020, 440, 151, 23));
        label_4 = new QLabel(centralwidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(1020, 420, 201, 16));
        label_4->setStyleSheet(QString::fromUtf8("font: 800 10pt \"Ubuntu\";\n"
"color: rgb(28, 113, 216)"));
        CenterX = new QDoubleSpinBox(centralwidget);
        CenterX->setObjectName(QString::fromUtf8("CenterX"));
        CenterX->setGeometry(QRect(1030, 520, 62, 23));
        CenterY = new QDoubleSpinBox(centralwidget);
        CenterY->setObjectName(QString::fromUtf8("CenterY"));
        CenterY->setGeometry(QRect(1140, 520, 62, 23));
        label_5 = new QLabel(centralwidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(1050, 470, 171, 31));
        label_5->setStyleSheet(QString::fromUtf8("font: 800 10pt \"Ubuntu Sans\";"));
        label_6 = new QLabel(centralwidget);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(1050, 500, 31, 16));
        label_7 = new QLabel(centralwidget);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(1160, 500, 58, 15));
        scaleButton = new QPushButton(centralwidget);
        scaleButton->setObjectName(QString::fromUtf8("scaleButton"));
        scaleButton->setGeometry(QRect(1060, 560, 131, 23));
        solveButton = new QPushButton(centralwidget);
        solveButton->setObjectName(QString::fromUtf8("solveButton"));
        solveButton->setGeometry(QRect(1040, 600, 181, 23));
        cleanButton = new QPushButton(centralwidget);
        cleanButton->setObjectName(QString::fromUtf8("cleanButton"));
        cleanButton->setGeometry(QRect(1040, 630, 181, 23));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1283, 20));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "\320\242\320\260\320\261\320\273\320\270\321\206\320\260 \321\201 \321\202\320\276\321\207\320\272\320\260\320\274\320\270", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "\320\245", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "\320\243", nullptr));
        AddDot->setText(QCoreApplication::translate("MainWindow", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214 \321\202\320\276\321\207\320\272\321\203", nullptr));
        randomButton->setText(QCoreApplication::translate("MainWindow", "\320\240\320\260\320\275\320\264\320\276\320\274\320\275\320\260\321\217 \321\202\320\276\321\207\320\272\320\260", nullptr));
        deleteButton->setText(QCoreApplication::translate("MainWindow", "\320\243\320\264\320\260\320\273\320\270\321\202\321\214 \321\202\320\276\321\207\320\272\321\203", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "\320\232\320\276\321\215\321\204\320\270\321\206\320\265\320\275\321\202 \320\234\320\260\321\201\321\210\321\202\320\260\320\261\320\270\321\200\320\276\320\262\320\260\320\275\320\270\321\217", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "\320\246\320\265\320\275\321\202\321\200 \320\234\320\260\321\201\321\210\321\202\320\260\320\261\320\270\321\200\320\276\320\262\320\275\320\270\321\217", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "\320\245", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindow", "\320\243", nullptr));
        scaleButton->setText(QCoreApplication::translate("MainWindow", "\320\234\320\260\321\201\321\210\321\202\320\260\320\261\320\270\321\200\320\276\320\262\320\260\321\202\321\214", nullptr));
        solveButton->setText(QCoreApplication::translate("MainWindow", "\320\240\320\265\321\210\320\265\320\275\320\270\320\265 \320\267\320\260\320\264\320\260\321\207\320\270", nullptr));
        cleanButton->setText(QCoreApplication::translate("MainWindow", "\320\236\321\207\320\270\321\201\321\202\320\270\321\202\321\214 \321\202\320\276\321\207\320\272\320\270", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
