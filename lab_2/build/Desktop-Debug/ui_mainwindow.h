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
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGraphicsView *graphicsView;
    QDoubleSpinBox *center_x;
    QDoubleSpinBox *center_y;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_5;
    QDoubleSpinBox *Scale_koef_y;
    QLabel *label_6;
    QLabel *label_7;
    QDoubleSpinBox *Scale_koef_x;
    QLabel *label_4;
    QDoubleSpinBox *Offset_koef_x;
    QLabel *label_8;
    QDoubleSpinBox *Offset_koef_y;
    QLabel *label_9;
    QDoubleSpinBox *Rotate_angle;
    QLabel *label_10;
    QPushButton *scale_button;
    QPushButton *offset_button;
    QPushButton *rotate_button;
    QPushButton *comeback_button;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1442, 769);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        graphicsView = new QGraphicsView(centralwidget);
        graphicsView->setObjectName(QString::fromUtf8("graphicsView"));
        graphicsView->setGeometry(QRect(0, 0, 1251, 721));
        center_x = new QDoubleSpinBox(centralwidget);
        center_x->setObjectName(QString::fromUtf8("center_x"));
        center_x->setGeometry(QRect(1270, 590, 62, 23));
        center_y = new QDoubleSpinBox(centralwidget);
        center_y->setObjectName(QString::fromUtf8("center_y"));
        center_y->setGeometry(QRect(1350, 590, 62, 23));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(1290, 570, 58, 15));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(1360, 570, 58, 15));
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(1280, 540, 141, 16));
        label_5 = new QLabel(centralwidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(1300, 80, 58, 15));
        Scale_koef_y = new QDoubleSpinBox(centralwidget);
        Scale_koef_y->setObjectName(QString::fromUtf8("Scale_koef_y"));
        Scale_koef_y->setGeometry(QRect(1360, 100, 62, 23));
        Scale_koef_y->setSingleStep(0.250000000000000);
        label_6 = new QLabel(centralwidget);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(1260, 50, 181, 16));
        label_7 = new QLabel(centralwidget);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(1370, 80, 58, 15));
        Scale_koef_x = new QDoubleSpinBox(centralwidget);
        Scale_koef_x->setObjectName(QString::fromUtf8("Scale_koef_x"));
        Scale_koef_x->setGeometry(QRect(1280, 100, 62, 23));
        Scale_koef_x->setSingleStep(0.250000000000000);
        label_4 = new QLabel(centralwidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(1310, 150, 71, 16));
        Offset_koef_x = new QDoubleSpinBox(centralwidget);
        Offset_koef_x->setObjectName(QString::fromUtf8("Offset_koef_x"));
        Offset_koef_x->setGeometry(QRect(1280, 200, 62, 23));
        label_8 = new QLabel(centralwidget);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(1300, 180, 58, 15));
        Offset_koef_y = new QDoubleSpinBox(centralwidget);
        Offset_koef_y->setObjectName(QString::fromUtf8("Offset_koef_y"));
        Offset_koef_y->setGeometry(QRect(1360, 200, 62, 23));
        label_9 = new QLabel(centralwidget);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setGeometry(QRect(1370, 180, 58, 15));
        Rotate_angle = new QDoubleSpinBox(centralwidget);
        Rotate_angle->setObjectName(QString::fromUtf8("Rotate_angle"));
        Rotate_angle->setGeometry(QRect(1310, 280, 62, 23));
        label_10 = new QLabel(centralwidget);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setGeometry(QRect(1300, 260, 101, 16));
        scale_button = new QPushButton(centralwidget);
        scale_button->setObjectName(QString::fromUtf8("scale_button"));
        scale_button->setGeometry(QRect(1250, 320, 191, 23));
        offset_button = new QPushButton(centralwidget);
        offset_button->setObjectName(QString::fromUtf8("offset_button"));
        offset_button->setGeometry(QRect(1250, 350, 191, 23));
        rotate_button = new QPushButton(centralwidget);
        rotate_button->setObjectName(QString::fromUtf8("rotate_button"));
        rotate_button->setGeometry(QRect(1250, 380, 191, 23));
        comeback_button = new QPushButton(centralwidget);
        comeback_button->setObjectName(QString::fromUtf8("comeback_button"));
        comeback_button->setGeometry(QRect(1280, 440, 131, 23));
        comeback_button->setStyleSheet(QString::fromUtf8("font:rgb(237, 51, 59)"));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1442, 20));
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
        label->setText(QCoreApplication::translate("MainWindow", "X", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Y", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "\320\232\320\276\320\276\321\200\320\264\320\270\320\275\320\260\321\202\321\213 \320\246\320\265\320\275\321\202\321\200\320\260", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "X", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "\320\232\320\276\321\215\321\204\321\206\320\265\320\275\321\202 \320\234\320\260\321\201\321\210\321\202\320\260\320\261\320\270\321\200\320\276\320\262\320\260\320\275\320\270\321\217", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindow", "Y", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "\320\241\320\274\320\265\321\211\320\265\320\275\320\270\320\265", nullptr));
        label_8->setText(QCoreApplication::translate("MainWindow", "X", nullptr));
        label_9->setText(QCoreApplication::translate("MainWindow", "Y", nullptr));
        label_10->setText(QCoreApplication::translate("MainWindow", "\320\243\320\263\320\276\320\273 \320\277\320\276\320\262\320\276\321\200\320\276\321\202\320\260", nullptr));
        scale_button->setText(QCoreApplication::translate("MainWindow", "\320\237\321\200\320\270\320\274\320\265\320\275\320\270\321\202\321\214 \320\274\320\260\321\201\321\210\321\202\320\260\320\261\320\270\321\200\320\276\320\262\320\260\320\275\320\270\320\265", nullptr));
        offset_button->setText(QCoreApplication::translate("MainWindow", "\320\237\321\200\320\270\320\274\320\265\320\275\320\270\321\202\321\214 \321\201\320\274\320\265\321\211\320\265\320\275\320\270\320\265", nullptr));
        rotate_button->setText(QCoreApplication::translate("MainWindow", "\320\222\321\213\320\277\320\276\320\273\320\275\320\270\321\202\321\214 \320\277\320\276\320\262\320\276\321\200\320\276\321\202", nullptr));
        comeback_button->setText(QCoreApplication::translate("MainWindow", "\320\222\320\265\321\200\320\275\321\203\321\202\321\214\321\201\321\217 \320\275\320\260\320\267\320\260\320\264", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
