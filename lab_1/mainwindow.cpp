#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <cstdlib>
#include <ctime>

#define START_SIZE 10
#define STEP_SIZE 2


void MainWindow::on_randomButton_clicked()
{
    double x = rand() % (int)ui->graphicsView->width();
    double y = rand() % (int)ui->graphicsView->height();

    ui->xDot->setValue(x);
    ui->yDot->setValue(y);

    on_AddDot_clicked();
}

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    scene = new QGraphicsScene(this);
    scene->setSceneRect(0,0,ui->graphicsView->width(),ui->graphicsView->height());

    srand(time(nullptr));
    m_updatingTable = false;
    ui->graphicsView->setScene(scene);
    ui->graphicsView->scale(1, -1);

    ui->xDot->setMaximum(ui->graphicsView->width());
    ui->yDot->setMaximum(ui->graphicsView->height());

    ui->CenterX->setMaximum(ui->graphicsView->width());
    ui->CenterX->setMinimum(0);

    ui->CenterY->setMaximum(ui->graphicsView->height());
    ui->CenterY->setMinimum(-10);

    ui->mashtabKoef->setMinimum(-10);
    ui->mashtabKoef->setMaximum(10);

    setupDotsTable();

    dots_arr = new Dot_t[START_SIZE];
    size_arr = 0;
    capacity_arr = START_SIZE;


}

void MainWindow::setupDotsTable()
{
    ui->DotTable->setColumnCount(3);
    QStringList headers;
    headers << "№" << "X" << "Y";
    ui->DotTable->setHorizontalHeaderLabels(headers);
    ui->DotTable->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->DotTable->setSelectionBehavior(QAbstractItemView::SelectRows);
    connect(ui->DotTable, &QTableWidget::cellChanged,
            this, &MainWindow::on_DotTable_cellChanged);


}

void MainWindow::AddPointToTable(double x, double y)
{
    if (size_arr >= capacity_arr)
    {
        int new_capacity = capacity_arr * STEP_SIZE;
        Dot_t* new_dots = new Dot_t[new_capacity];

        for (int i = 0; i < size_arr; i++) {
            new_dots[i] = dots_arr[i];
        }

        delete[] dots_arr;
        dots_arr = new_dots;
        capacity_arr = new_capacity;
    }


    dots_arr[size_arr].x = x;
    dots_arr[size_arr].y = y;
    size_arr++;


    int rows = size_arr - 1;

    ui->DotTable->insertRow(rows);
    QTableWidgetItem *numRow = new QTableWidgetItem(QString::number(rows+1));
    numRow->setFlags(numRow->flags() & ~Qt::ItemIsEditable);
    ui->DotTable->setItem(rows, 0, numRow);

    ui->DotTable->setItem(rows, 1, new QTableWidgetItem(QString::number(x, 'f', 2)));
    ui->DotTable->setItem(rows, 2, new QTableWidgetItem(QString::number(y, 'f', 2)));

    Draw_dot(x, y);
}



void MainWindow::Draw_dot(double x, double y)
{

    scene->addEllipse(x, y, 6, 6,
                      QPen(Qt::red),
                      QBrush(Qt::red));

    QString text = QString("(%1, %2)").arg(x).arg(y);
    QGraphicsTextItem *label = scene->addText(text);
    label->setPos(x + 5, y + 5);
    label->setDefaultTextColor(Qt::darkRed);

    QTransform transform;
    transform.scale(1, -1);
    label->setTransform(transform);
}

void MainWindow::on_deleteButton_clicked()
{
    if (size_arr == 0) {
        QMessageBox::warning(this, "Ошибка", "Таблица пуста");
        return;
    }

    int currentRow = ui->DotTable->currentRow();

    if (currentRow == -1) {
        QMessageBox::warning(this, "Ошибка", "Выберите точку для удаления");
        return;
    }

    for (int i = currentRow; i < size_arr - 1; i++)
    {
        dots_arr[i] = dots_arr[i+1];
    }
    size_arr--;


    ui->DotTable->removeRow(currentRow);

    for (int i = currentRow; i < ui->DotTable->rowCount(); i++) {
        ui->DotTable->item(i, 0)->setText(QString::number(i + 1));
    }

    refreshScene();
}

void MainWindow::on_DotTable_cellChanged(int row, int column)
{
    if (column == 0) return;
    if (m_updatingTable) return;
    QTableWidgetItem *xItem = ui->DotTable->item(row, 1);
    QTableWidgetItem *yItem = ui->DotTable->item(row, 2);

    if (xItem && yItem) {
        QString xStr = xItem->text().replace(',', '.');
        QString yStr = yItem->text().replace(',', '.');

        bool okX, okY;
        double x = xStr.toDouble(&okX);
        double y = yStr.toDouble(&okY);

        if (!okX || !okY) {
            QMessageBox::warning(this, "Ошибка", "Некорректное число!");
            xItem->setText(QString::number(dots_arr[row].x));
            yItem->setText(QString::number(dots_arr[row].y));
            return;
        }

        if (x > ui->graphicsView->width() || y > ui->graphicsView->height()) {
            QMessageBox::warning(this, "Ошибка", "Точка выходит за границы!");
            xItem->setText(QString::number(dots_arr[row].x));
            yItem->setText(QString::number(dots_arr[row].y));
            return;
        }

        dots_arr[row].x = x;
        dots_arr[row].y = y;
        refreshScene();
    }
}


void MainWindow::refreshScene()
{
    scene->clear();

    for (int i = 0; i < size_arr; i++) {
        Draw_dot(dots_arr[i].x, dots_arr[i].y);
    }
}



void MainWindow::on_AddDot_clicked()
{
    double x = ui->xDot->value();
    double y = ui->yDot->value();

    if (x > ui->graphicsView->width() || y > ui->graphicsView->height())
    {
        QMessageBox::critical(this, "Ошибка", "Точка выходит за границы области рисования!");
        return;
    }

    AddPointToTable(x, y);

}


void MainWindow::on_scaleButton_clicked()
{
    if (!size_arr)
    {
        QMessageBox::warning(this,"Ошибка", "Масштабировать нечего, точки не заданы");
        return;
    }

    double koef = ui->mashtabKoef->value();
    double center_x = ui->CenterX->value();
    double center_y = ui->CenterY->value();
    m_updatingTable = true;

    for (int i = 0; i < size_arr; i++) {
        double oldX = dots_arr[i].x;
        double oldY = dots_arr[i].y;


        double newX = center_x + koef * (oldX - center_x);
        double newY = center_y + koef * (oldY - center_y);

        dots_arr[i].x = newX;
        dots_arr[i].y = newY;
    }

    for (int i = 0; i < size_arr; i++) {
        if (ui->DotTable->item(i, 1) && ui->DotTable->item(i, 2)) {
            ui->DotTable->item(i, 1)->setText(QString::number(dots_arr[i].x, 'f', 2));
            ui->DotTable->item(i, 2)->setText(QString::number(dots_arr[i].y, 'f', 2));
        }
    }

    m_updatingTable = false;

    refreshScene();

}


SplitResult MainWindow::findBestSplit()
{
    SplitResult best;
    best.diff = size_arr + 1;

    for (int i = 0; i < size_arr; i++) {
        for (int j = i + 1; j < size_arr; j++) {


            if (dots_arr[i].x == dots_arr[j].x && dots_arr[i].y == dots_arr[j].y)
                continue;

            int above = 0;
            int below = 0;

            for (int k = 0; k < size_arr; k++) {
                if (k == i || k == j) continue;

                double side = pointSide(dots_arr[i], dots_arr[j], dots_arr[k]);

                if (side > 0)
                    above++;
                else if (side < 0)
                    below++;
            }


            int diff = abs(above - below);

            if (diff < best.diff) {
                best.diff = diff;
                best.point1_idx = i;
                best.point2_idx = j;
                best.count_above = above;
                best.count_below = below;
            }
        }
    }

    return best;
}

void MainWindow::on_solveButton_clicked()
{
    if (size_arr < 4) {
        QMessageBox::warning(this, "Ошибка", "Нужно минимум 4 точки");
        return;
    }

    SplitResult best = findBestSplit();

    drawLine(best.point1_idx, best.point2_idx);

    QString msg = QString(
                      "Прямая через точки %1(%2, %3) и %4(%5, %6)\n"
                      "Разделила точки на два множества:\n"
                      "Сверху: %7 точек\n"
                      "Снизу: %8 точек\n"
                      "Разность: %9"
                      ).arg(best.point1_idx + 1)
                      .arg(dots_arr[best.point1_idx].x, 0, 'f', 2)
                      .arg(dots_arr[best.point1_idx].y, 0, 'f', 2)
                      .arg(best.point2_idx + 1)
                      .arg(dots_arr[best.point2_idx].x, 0, 'f', 2)
                      .arg(dots_arr[best.point2_idx].y, 0, 'f', 2)
                      .arg(best.count_above)
                      .arg(best.count_below)
                      .arg(best.diff);

    QMessageBox::information(this, "Результат разбиения", msg);
}

double MainWindow::pointSide(Dot_t A, Dot_t B, Dot_t P)
{
    return (B.x - A.x) * (P.y - A.y) - (B.y - A.y) * (P.x - A.x);
}

void MainWindow::drawLine(int idx1, int idx2)
{
    Dot_t A = dots_arr[idx1];
    Dot_t B = dots_arr[idx2];

    if (A.x == B.x && A.y == B.y) return;

    QRectF rect = scene->sceneRect();

    if (B.x != A.x)
    {
        double k = (B.y - A.y) / (B.x - A.x);
        double b = A.y - k * A.x;

        double y_left = k * rect.left() + b;
        double y_right = k * rect.right() + b;


        scene->addLine(rect.left(), y_left, rect.right(), y_right,
                       QPen(Qt::black, 2));
    } else {

        scene->addLine(A.x, rect.top(), A.x, rect.bottom(),
                       QPen(Qt::black, 2));
    }
}

void MainWindow::on_cleanButton_clicked()
{

    delete[] dots_arr;

    dots_arr = new Dot_t[START_SIZE];
    size_arr = 0;
    capacity_arr = START_SIZE;

    ui->DotTable->setRowCount(0);

    scene->clear();

    ui->xDot->setValue(0);
    ui->yDot->setValue(0);
    ui->CenterX->setValue(0);
    ui->CenterY->setValue(0);
    ui->mashtabKoef->setValue(1);
}

MainWindow::~MainWindow()
{
    delete[] dots_arr;
    delete ui;
}

