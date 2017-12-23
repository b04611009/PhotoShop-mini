#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFileDialog>
#include <QImage>
#include <QString>
#include <QFile>
#include <QTextStream>
#include <QMessageBox>
#include <QBitmap>
#include <QPicture>
#include <QPixmap>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    QImage *sure;
    cv::Mat QImagetoCvMat(QImage &image);
    QImage CvMattoQImage(const cv::Mat& mat);
    QImage * cold(int delta, QImage * origin);
    QImage * warm(int delta, QImage * origin);
    QImage * grayscale2(QImage *origin);
    QImage * saturation(int delta, QImage * origin);
    QImage * brightness(int delta, QImage * origin);
    QImage * contrast_exchange(QImage *origin);
    QString FilePath ;
    void undoredo_enable();
    //Mouse Event



private slots:
    void on_LoadImage_clicked();

    void on_grayscale_clicked();

    void on_grayscale2_clicked();

    void on_blur_g_clicked();

    void on_sharpen_cv_clicked();

    void on_equalization_clicked();

    void on_undo_clicked();

    void on_redo_clicked();

    void on_threshold_clicked();

    void on_background_clicked();

    void on_contrast_color_clicked();

    void on_resize_d_clicked();

    void on_resize_i_clicked();

    void on_horizontalSlider_saturation_valueChanged(int value);

    void on_saturation_clicked();

    void on_horizontalSlider_saturation_sliderReleased();

    void on_brightness_clicked();

    void on_horizontalSlider_brightness_valueChanged(int value);

    void on_horizontalSlider_brightness_sliderReleased();

    void on_warm_clicked();

    void on_horizontalSlider_warm_valueChanged(int value);

    void on_horizontalSlider_warm_sliderReleased();

    void on_cold_clicked();

    void on_horizontalSlider_cold_valueChanged(int value);

    void on_horizontalSlider_cold_sliderReleased();

    void on_contrast_clicked();

    void on_horizontalSlider_contrast_valueChanged(int value);

    void on_horizontalSlider_contrast_sliderReleased();

    void on_map_turn_clicked();

    void on_mirror_clicked();

    void on_save_clicked();

    void on_exit_clicked();

    void on_reset_clicked();

private:
    Ui::MainWindow *ui;
    QImage *temporary;
    QImage *Image[50];
    QPixmap pixmap;
    std::string name;
    int current=0;
    int saturationvalue=0;
    int brightnessvalue=0;
    int contrastvalue=0;
    int warmvalue=0;
    int coldvalue=0;
    QString TextPath = ("C:/Users/admin/Desktop/tempImage/test.jpg");
    //Mouse Event

};

#endif // MAINWINDOW_H
