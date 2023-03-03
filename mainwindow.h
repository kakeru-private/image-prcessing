#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <mainwindow.h>
#include <QMainWindow>
#include <QPushButton>
#include<QFileDialog>
#include<QMessageBox>
#include<math.h>
#include<filesystem>
#include<opencv2/opencv.hpp>

#include<string>

using namespace std;


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void unreadError();
    void unreadableError();
    void unselectMethodError();
    QPixmap opcvToQpixmap(cv::Mat);

    void setPixmapImage(QPixmap);
    int mapclearmessage();

private slots:
    void on_openButton_released();

    void on_saveButton_released();

    void on_kakudai_released();


    void on_grayscale_released();

    void on_edge_released();

    void on_filtering_released();

    void on_nitika_released();

    void on_rotate_released();

    void on_srcshow_released();



    void on_clearButton_released();

    void on_toukeiButton_released();

    void on_changeSrcButton_released();

    void on_spinBox_2_valueChanged(int arg1);

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
