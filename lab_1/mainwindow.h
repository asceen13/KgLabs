#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsTextItem>
#include <QTransform>
#include <QMessageBox>


QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

struct Dot_t{
    double x;
    double y;
};

struct SplitResult {
    int point1_idx;
    int point2_idx;
    int count_above;
    int count_below;
    int diff;
};

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_AddDot_clicked();
    void on_randomButton_clicked();
    void on_deleteButton_clicked();
    void on_DotTable_cellChanged(int row, int column);
    void on_scaleButton_clicked();
    void on_solveButton_clicked();
    void on_cleanButton_clicked();

private:
    Ui::MainWindow *ui;
    QGraphicsScene *scene;

    void setupDotsTable();
    void AddPointToTable(double x, double y);
    void Draw_dot(double x, double y);
    void refreshScene();
    SplitResult findBestSplit();
    double pointSide(Dot_t A, Dot_t B, Dot_t P);
    void drawLine(int idx1, int idx2);
    bool m_updatingTable;

    Dot_t* dots_arr;
    int size_arr;
    int capacity_arr;



};
#endif // MAINWINDOW_H
