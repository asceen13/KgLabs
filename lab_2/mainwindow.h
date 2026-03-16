#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QMessageBox>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

struct Dot_t {
    double x;
    double y;
    int connect;
};

struct HistoryState {
    Dot_t* dots;
    int size;
};

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_scale_button_clicked();
    void on_offset_button_clicked();
    void on_comeback_button_clicked();
    void on_rotate_button_clicked();

private:
    Ui::MainWindow *ui;
    QGraphicsScene *scene;

    Dot_t* dots_arr;
    int size_arr;
    Dot_t * old_dots;

    int flag_back;

    double Xmin, Xmax, Ymin, Ymax;
    double Xcenter, Ycenter;

    void loadShapeFromFile(const QString& filename);
    void DrawFigure();
    void Scale(double x_koef, double y_koef, double scale_center_x, double scale_center_y);
    void Rotate(double rotate_angle, double center_x, double center_y);
    void OffsetDots(double x, double y);
};

#endif // MAINWINDOW_H
