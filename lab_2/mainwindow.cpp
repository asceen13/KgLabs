#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QTextStream>
#include <qfile.h>
#include <qfiledialog.h>
#include <QDebug>
#include <QGraphicsTextItem>
#include <cstring>
#include <cmath>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    scene = new QGraphicsScene(this);
    scene->setSceneRect(0,0,ui->graphicsView->width(),ui->graphicsView->height());

    ui->graphicsView->setScene(scene);
    ui->graphicsView->scale(1, -1);

    ui->center_x->setRange(0, ui->graphicsView->width());
    ui->center_y->setRange(0, ui->graphicsView->height());

    ui->Offset_koef_x->setRange(-200, 200);
    ui->Offset_koef_y->setRange(-200, 200);

    ui->Rotate_angle->setRange(0, 10000);

    ui->Scale_koef_x->setRange(-2.0, 2.0);
    ui->Scale_koef_y->setRange(-2.0, 2.0);

    dots_arr = new Dot_t[1];
    size_arr = 0;

    old_dots = new Dot_t[1];

    flag_back = 0;


    loadShapeFromFile("/home/asc/kg/lab_2/watch.txt");

    OffsetDots(280.5, 140.5);
    DrawFigure();

}


void MainWindow::loadShapeFromFile(const QString& filename)
{
    QFile file(filename);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QMessageBox::warning(this, "Ошибка", "Не удалось открыть файл");
        return;
    }

    QTextStream in(&file);

    int count;
    in >> count;

    delete[] dots_arr;
    dots_arr = new Dot_t[count];
    size_arr = count;

    old_dots = new Dot_t[count];



    for (int i = 0; i < count; i++) {
        int connect;
        double x, y;
        in >> connect >> x >> y;

        dots_arr[i].x = x;
        dots_arr[i].y = y;
        dots_arr[i].connect = connect;

    }


    file.close();
}

void MainWindow::DrawFigure(void)
{
    scene->clear();


    double Xmax = dots_arr[0].x;
    double Ymax = dots_arr[0].y;
    double Xmin = dots_arr[0].x;
    double Ymin = dots_arr[0].y;

    for (int i = 1; i < size_arr; i++)
    {
        if (dots_arr[i].connect == 1)
        {
            scene->addLine(dots_arr[i-1].x, dots_arr[i-1].y,dots_arr[i].x, dots_arr[i].y, QPen(Qt::black,2));
        }
    if (dots_arr[i].x < Xmin)
        Xmin = dots_arr[i].x;
    if (dots_arr[i].x > Xmax)
        Xmax = dots_arr[i].x;
    if (dots_arr[i].y < Ymin)
        Ymin = dots_arr[i].y;
    if (dots_arr[i].y > Ymax)
        Ymax = dots_arr[i].y;
    }

    double XCenter = (Xmax + Xmin)/ 2;
    double YCenter = (Ymax + Ymin)/2;

    scene->addEllipse(XCenter, YCenter, 6, 6, QPen(Qt::red), QBrush(Qt::red));

    QString CenterCoord = QString("(%1, %2)").arg(XCenter).arg(YCenter);
    QGraphicsTextItem *center = scene->addText(CenterCoord, QFont("Arial",10));
    center->setDefaultTextColor(Qt::blue);

    QTransform transform;
    transform.scale(1, -1);
    center->setTransform(transform);

    center->setPos(XCenter+10, YCenter +30);


}

void MainWindow::OffsetDots(double x, double y)
{
    for (int i = 0; i < size_arr; i++)
    {
        dots_arr[i].x+= x;
        dots_arr[i].y+= y;
    }
}



MainWindow::~MainWindow()
{
    delete[] dots_arr;
    delete ui;
}

void MainWindow::on_scale_button_clicked()
{
    flag_back = 0;
    memcpy(old_dots, dots_arr, sizeof(Dot_t) * size_arr);

    double x_koef = ui->Scale_koef_x->value();
    double y_koef = ui->Scale_koef_y->value();

    double scale_center_x = ui->center_x->value();
    double scale_center_y = ui->center_y->value();
    Scale(x_koef, y_koef, scale_center_x, scale_center_y);
    DrawFigure();

}

void MainWindow::Scale(double x_koef, double y_koef, double scale_center_x, double scale_center_y)
{
    for (int i = 0; i < size_arr; i++)
    {
        double oldX = dots_arr[i].x;
        double oldY = dots_arr[i].y;


        double newX = scale_center_x + x_koef*(oldX - scale_center_x);
        double newY = scale_center_y + y_koef * (oldY - scale_center_y);

        dots_arr[i].x = newX;
        dots_arr[i].y = newY;
    }
}



void MainWindow::on_offset_button_clicked()
{
    flag_back = 0;
    memcpy(old_dots, dots_arr, sizeof(Dot_t) * size_arr);

    double offset_x = ui->Offset_koef_x->value();
    double offset_y = ui->Offset_koef_y->value();

    OffsetDots(offset_x, offset_y);
    DrawFigure();
}




void MainWindow::on_comeback_button_clicked()
{
    if (flag_back == 1)
    {
        QMessageBox::warning(this, "Ошибка", "Шаг назад уже был применен, откатываться некуда.");
    }
    else
    {
        memcpy(dots_arr, old_dots, sizeof(Dot_t) * size_arr);
        DrawFigure();
        flag_back = 1;
    }
    return;
}


void MainWindow::on_rotate_button_clicked()
{
    flag_back = 0;
    memcpy(old_dots, dots_arr, sizeof(Dot_t) * size_arr);

    double scale_center_x = ui->center_x->value();
    double scale_center_y = ui->center_y->value();

    double rotate_ange = ui->Rotate_angle->value();

    Rotate(rotate_ange, scale_center_x, scale_center_y);
    DrawFigure();

}

void MainWindow::Rotate(double rotate_angle, double center_x, double center_y)
{

    double angle_rad = rotate_angle * M_PI / 180.0;

    double cos_theta = cos(angle_rad);
    double sin_theta = sin(angle_rad);

    for (int i = 0; i < size_arr; i++)
    {
        double x_old = dots_arr[i].x;
        double y_old = dots_arr[i].y;

        dots_arr[i].x = center_x + (x_old - center_x) * cos_theta
                        + (y_old - center_y) * sin_theta;

        dots_arr[i].y = center_y - (x_old - center_x) * sin_theta
                        + (y_old - center_y) * cos_theta;
    }
    return;
}
