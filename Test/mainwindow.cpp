#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <QMainWindow>
#include <QFileDialog>
#include <opencv/cv.h>
#include <opencv/highgui.h>
#include <QImage>
#include <QFile>
#include <QString>
#include <QTextStream>
#include <QMessageBox>
#include <QPainter>
#include <QLinearGradient>
// 介面setup & settings
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    //版面
    ui->setupUi(this);
    this->setWindowTitle(tr("photoshop"));
    this->setStyleSheet("background-color: rgb(246, 246, 246)");
    QPixmap paint ("C:/Users/admin/Desktop/painter.jpg");
    QPixmap numb ("C:/Users/admin/Desktop/numb.jpg");
    QPixmap exit ("C:/Users/admin/Desktop/exit.jpg");
    ui->icon->setPixmap(paint.scaled(ui->icon->width(),ui->icon->height(),Qt::KeepAspectRatio));
    ui->icon_exit->setPixmap(exit.scaled(ui->icon_exit->width(),ui->icon_exit->height(),Qt::KeepAspectRatio));
    ui->icon_confirm->setPixmap(numb.scaled(ui->icon_confirm->width(),ui->icon_confirm->height(),Qt::KeepAspectRatio));
    undoredo_enable();
    //slider設定
    ui->horizontalSlider_saturation->setValue(0);
    ui->horizontalSlider_saturation->setMaximum(100);
    ui->horizontalSlider_saturation->setMinimum(-100);
    ui->horizontalSlider_brightness->setValue(0);
    ui->horizontalSlider_brightness->setMaximum(100);
    ui->horizontalSlider_brightness->setMinimum(-100);
    ui->horizontalSlider_warm->setValue(0);
    ui->horizontalSlider_warm->setMaximum(100);
    ui->horizontalSlider_warm->setMinimum(-100);
    ui->horizontalSlider_cold->setValue(0);
    ui->horizontalSlider_cold->setMaximum(100);
    ui->horizontalSlider_cold->setMinimum(-100);
    ui->horizontalSlider_contrast->setValue(0);
    ui->horizontalSlider_contrast->setMaximum(100);
    ui->horizontalSlider_contrast->setMinimum(-100);
    //按鍵開關
    ui->grayscale->setEnabled(false);
    ui->grayscale2->setEnabled(false);
    ui->blur_g->setEnabled(false);
    ui->sharpen_cv->setEnabled(false);
    ui->equalization->setEnabled(false);
    ui->background->setEnabled(false);
    ui->contrast_color->setEnabled(false);
    ui->resize_d->setEnabled(false);
    ui->resize_i->setEnabled(false);
    ui->saturation->setEnabled(false);
    ui->horizontalSlider_saturation->setEnabled(false);
    ui->brightness->setEnabled(false);
    ui->horizontalSlider_brightness->setEnabled(false);
    ui->warm->setEnabled(false);
    ui->horizontalSlider_warm->setEnabled(false);
    ui->cold->setEnabled(false);
    ui->horizontalSlider_cold->setEnabled(false);
    ui->contrast->setEnabled(false);
    ui->horizontalSlider_contrast->setEnabled(false);
    ui->map_turn->setEnabled(false);
    ui->mirror->setEnabled(false);
    ui->save->setEnabled(false);
    ui->redo->setEnabled(false);
    ui->undo->setEnabled(false);
    ui->reset->setEnabled(false);
    //label 介面
    ui->LoadImage->setStyleSheet(" border-width: 3px; border-style: solid; border-color: red; background-color: white; color: black; ");
    ui->grayscale->setStyleSheet(" border-width: 3px; border-style: solid; border-color: orange; background-color: white; color: black; ");
    ui->grayscale2->setStyleSheet(" border-width: 3px; border-style: solid; border-color: yellow; background-color: white; color: black; ");
    ui->blur_g->setStyleSheet(" border-width: 3px; border-style: solid; border-color: green; background-color: white; color: black; ");
    ui->sharpen_cv->setStyleSheet(" border-width: 3px; border-style: solid; border-color: rgb(0, 170, 255); background-color: white; color: black; ");
    ui->equalization->setStyleSheet(" border-width: 3px; border-style: solid; border-color: blue; background-color: white; color: black; ");
    ui->threshold->setStyleSheet(" border-width: 3px; border-style: solid; border-color: purple; background-color: white; color: black; ");
    ui->background->setStyleSheet(" border-width: 3px; border-style: solid; border-color: red; background-color: white; color: black; ");
    ui->contrast_color->setStyleSheet(" border-width: 3px; border-style: solid; border-color: orange; background-color: white; color: black; ");
    ui->resize_d->setStyleSheet(" border-width: 3px; border-style: solid; border-color: yellow; background-color: white; color: black; ");
    ui->resize_i->setStyleSheet(" border-width: 3px; border-style: solid; border-color: green; background-color: white; color: black; ");
    ui->saturation->setStyleSheet(" border-width: 5px; border-style: solid; border-color: pink; background-color: white;");
    ui->brightness->setStyleSheet(" border-width: 5px; border-style: solid; border-color: pink; background-color: white;");
    ui->warm->setStyleSheet(" border-width: 5px; border-style: solid; border-color: violet; background-color: white;");
    ui->cold->setStyleSheet(" border-width: 5px; border-style: solid; border-color: violet; background-color: white;");
    ui->map_turn->setStyleSheet(" border-width: 3px; border-style: solid; border-color: rgb(0, 170, 255); background-color: white; color: black; ");
    ui->mirror->setStyleSheet(" border-width: 3px; border-style: solid; border-color: blue; background-color: white; color: black; ");
    ui->contrast->setStyleSheet(" border-width: 5px; border-style: solid; border-color: rgb(220, 17, 255); background-color: white;");
    ui->save->setStyleSheet(" border-width: 3px; border-style: solid; border-color: purple; background-color: white; color: black; ");
    ui->photo->setStyleSheet(" background-color: white;border-width: 20px; border-style: solid; border-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(255, 178, 102, 255), stop:0.55 rgba(235, 148, 61, 255), stop:0.98 rgba(0, 0, 0, 255), stop:1 rgba(0, 0, 0, 0)); ");
    ui->undo->setStyleSheet(" border-width: 3px; border-style: solid; border-color: black; background-color: white; color: black; ");
    ui->redo->setStyleSheet(" border-width: 3px; border-style: solid; border-color: black; background-color: white; color: black; ");
    ui->reset->setStyleSheet(" border-width: 3px; border-style: solid; border-color: black; background-color: white; color: black; ");
    ui->exit->setStyleSheet(" border-width: 5px; border-style: solid; border-color: qlineargradient(spread:repeat, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(255, 161, 30, 255), stop:0.5 rgba(110, 250, 60, 255), stop:1 rgba(96, 199, 193, 255)); background-color: white; color: qlineargradient(spread:repeat, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(255, 161, 30, 255), stop:0.5 rgba(110, 250, 60, 255), stop:1 rgba(96, 199, 193, 255));");
}
MainWindow::~MainWindow()
{
    delete ui;
    delete []*Image;
}
// Mat & Image 互換
cv::Mat MainWindow::QImagetoCvMat(QImage &image)
{
    cv::Mat cvImage;
    switch (image.format())
    {
    case QImage::Format_RGB888:
    {
        cvImage = cv::Mat(image.height(),image.width(),CV_8UC3,image.bits(), image.bytesPerLine());
        cv::cvtColor(cvImage, cvImage, CV_RGB2BGR);
        return cvImage;
    }
    case QImage::Format_Indexed8:
    {
        cvImage = cv::Mat(image.height(),image.width(),CV_8U,image.bits(),image.bytesPerLine());
        return cvImage;
    }
    default:
        break;
    }
    return cvImage;
}
QImage MainWindow::CvMattoQImage(const cv::Mat& mat)
{
    if(mat.type() == CV_8UC1)
    {
        QImage image(mat.cols, mat.rows, QImage::Format_Indexed8);
        image.setColorCount(256);
        for(int i = 0; i < 256; i++)
        {
            image.setColor(i, qRgb(i, i, i));
        }
        uchar *pSrc = mat.data;
        for(int row = 0; row < mat.rows; row ++)
        {
            uchar *pDest = image.scanLine(row);
            memcpy(pDest, pSrc, mat.cols);
            pSrc += mat.step;
        }
        return image;
    }
    else if(mat.type() == CV_8UC3)
    {
        const uchar *pSrc = (const uchar*)mat.data;
        QImage image(pSrc, mat.cols, mat.rows, mat.step, QImage::Format_RGB888);
        return image.rgbSwapped();
    }
    else if(mat.type() == CV_8UC4)
    {
        const uchar *pSrc = (const uchar*)mat.data;
        QImage image(pSrc, mat.cols, mat.rows, mat.step, QImage::Format_ARGB32);
        return image.copy();
    }
    else
    {
        return QImage();
    }
}
// undo&redo
void MainWindow::undoredo_enable(){
    if(current>0)
        ui->undo->setEnabled(true);
    else
        ui->undo->setEnabled(false);

    if(Image[current+1]!=NULL)
        ui->redo->setEnabled(true);
    else
        ui->redo->setEnabled(false);
}
void MainWindow::on_undo_clicked()
{
    current--;
    pixmap = QPixmap::fromImage(*Image[current]);
    ui->photo->setPixmap(pixmap.scaled(ui->photo->width(),ui->photo->height(),Qt::KeepAspectRatio));
    *Image[current]=pixmap.toImage();
    Image[current]->save(TextPath);
    undoredo_enable();
}
void MainWindow::on_redo_clicked()
{
    current++;
    pixmap = QPixmap::fromImage(*Image[current]);
    ui->photo->setPixmap(pixmap.scaled(ui->photo->width(),ui->photo->height(),Qt::KeepAspectRatio));
    *Image[current]=pixmap.toImage();
    Image[current]->save(TextPath);
    undoredo_enable();
}
// Mouse Event
// Image processing
QImage * MainWindow::brightness(int delta, QImage * origin){
    QImage *final = new QImage(origin->width(), origin->height(), QImage::Format_ARGB32);
    QColor oldColor;
    int r,g,b;
    for(int x=0; x<final->width(); x++){
        for(int y=0; y<final->height(); y++){
            oldColor = QColor(origin->pixel(x,y));
            r = oldColor.red()+delta;
            g = oldColor.green()+delta;
            b = oldColor.blue()+delta;
            r = qBound(0, r, 255);
            g = qBound(0, g, 255);
            b = qBound(0, b, 255);
            final->setPixel(x,y, qRgb(r,g,b));
        }
    }
    return final;
}
QImage * MainWindow::warm(int delta, QImage * origin){
    QImage *final = new QImage(origin->width(), origin->height(), QImage::Format_ARGB32);
    QColor oldColor;
    int r,g,b;
    for(int x=0; x<final->width(); x++){
        for(int y=0; y<final->height(); y++){
            oldColor = QColor(origin->pixel(x,y));
            r = oldColor.red()+delta;
            g = oldColor.green()+delta;
            b = oldColor.blue();
            r = qBound(0, b, 255);
            g = qBound(0, g, 255);
            final->setPixel(x,y, qRgb(r,g,b));
        }
    }
    return final;
}
QImage * MainWindow::cold(int delta, QImage * origin)
{
    QImage *final = new QImage(origin->width(), origin->height(), QImage::Format_ARGB32);
    QColor oldColor;
    int r,g,b;
    for(int x=0; x<final->width(); x++){
        for(int y=0; y<final->height(); y++){
            oldColor = QColor(origin->pixel(x,y));
            r = oldColor.red();
            g = oldColor.green();
            b = oldColor.blue()+delta;
            b = qBound(0, b, 255);
            final->setPixel(x,y, qRgb(r,g,b));
        }
    }
    return final;
}
QImage* MainWindow::grayscale2(QImage *origin)
{
    QImage *final = new QImage(origin->width(), origin->height(), QImage::Format_ARGB32);
    QColor oldColor;
    for(int x = 0; x<final->width(); x++){
        for(int y = 0; y<final->height(); y++){
            oldColor = QColor(origin->pixel(x,y));
            int average = (oldColor.red()+oldColor.green()+oldColor.blue())/3;
            final->setPixel(x,y,qRgb(average,average,average));
        }
    }
    return final;
}
QImage * MainWindow::saturation(int saturationvalue, QImage * origin)
{
    QImage * final = new QImage(origin->width(), origin->height(), QImage::Format_ARGB32);
    QColor oldColor;
    QColor newColor;
    int h,s,l;
    for(int x=0; x<final->width(); x++){
        for(int y=0; y<final->height(); y++){
            oldColor = QColor(origin->pixel(x,y));
            newColor = oldColor.toHsl();
            h = newColor.hue();
            s = newColor.saturation()+saturationvalue;
            l = newColor.lightness();
            s = qBound(0, s, 255);
            newColor.setHsl(h, s, l);
            final->setPixel(x, y, qRgb(newColor.red(), newColor.green(), newColor.blue()));
        }
    }
    return final;
}
QImage* MainWindow::contrast_exchange(QImage *origin)
{
    QImage *final = new QImage(origin->width(), origin->height(), QImage::Format_ARGB32);
    QColor oldColor;
    int value = 255;
    for(int x = 0; x<final->width(); x++){
        for(int y = 0; y<final->height(); y++){
            oldColor = QColor(origin->pixel(x,y));
            int r = value - oldColor.red();
            int g = value - oldColor.green();
            int b = value - oldColor.blue();
            final->setPixel(x,y,qRgb(r,g,b));
        }
    }
    return final;
}
// button design
void MainWindow::on_LoadImage_clicked()
{
   for(int i=0;i<50;i++){
       {Image[i]={NULL};}
       *Image=new QImage;
   }
   FilePath = QFileDialog::getOpenFileName(this,tr("Open File"),"/",tr("Images(*.png *.jpg)"));
   if (FilePath!=NULL){
       Image[0] -> load (FilePath);
       pixmap = QPixmap::fromImage(*Image[current]);
       ui->photo->setPixmap(pixmap.scaled(ui->photo->width(),ui->photo->height(),Qt::KeepAspectRatio));
       ui->grayscale->setEnabled(true);
       ui->grayscale2->setEnabled(true);
       ui->blur_g->setEnabled(true);
       ui->sharpen_cv->setEnabled(true);
       ui->equalization->setEnabled(true);
       ui->background->setEnabled(true);
       ui->contrast_color->setEnabled(true);
       ui->resize_d->setEnabled(true);
       ui->resize_i->setEnabled(true);
       ui->saturation->setEnabled(true);
       ui->brightness->setEnabled(true);
       ui->contrast->setEnabled(true);
       ui->warm->setEnabled(true);
       ui->cold->setEnabled(true);
       ui->map_turn->setEnabled(true);
       ui->mirror->setEnabled(true);
       ui->save->setEnabled(true);
       ui->undo->setEnabled(true);
       ui->redo->setEnabled(true);
       ui->reset->setEnabled(true);
   }
   else
       QMessageBox::warning(0,0,"no image found");
   *Image[current]=pixmap.toImage();
   Image[current]->save(TextPath);
   ui->LoadImage->setEnabled(false);
   undoredo_enable();
}
void MainWindow::on_grayscale_clicked()
{
    cv::Mat mat_gr = cv::imread(TextPath.toStdString(),0);
    QImage gray = CvMattoQImage(mat_gr);
    QImage *final = new QImage(gray);
    Image[current+1]=final;
    pixmap = QPixmap::fromImage(*Image[current+1]);
    ui->photo->setPixmap(pixmap.scaled(ui->photo->width(),ui->photo->height(),Qt::KeepAspectRatio));
    current++;
    *Image[current]=pixmap.toImage();
    Image[current]->save(TextPath);
    undoredo_enable();
}
void MainWindow::on_grayscale2_clicked()
{
    Image[current+1]=grayscale2(Image[current]);
    pixmap = QPixmap::fromImage(*Image[current+1]);
    ui->photo->setPixmap(pixmap.scaled(ui->photo->width(),ui->photo->height(),Qt::KeepAspectRatio));
    current++;
    *Image[current]=pixmap.toImage();
    Image[current]->save(TextPath);
    undoredo_enable();
}
void MainWindow::on_blur_g_clicked()
{
    cv::Mat blur_g = cv::imread(TextPath.toStdString());
    cv::GaussianBlur(blur_g,blur_g,cv::Size(9,9),0,0);
    QImage gaussian = CvMattoQImage(blur_g);
    QImage *final = new QImage(gaussian);
    Image[current+1] = final;
    pixmap = QPixmap::fromImage(*Image[current+1]);
    ui->photo->setPixmap(pixmap.scaled(ui->photo->width(),ui->photo->height(),Qt::KeepAspectRatio));
    current++;
    *Image[current]=pixmap.toImage();
    Image[current]->save(TextPath);
    undoredo_enable();
}
void MainWindow::on_sharpen_cv_clicked()
{
    cv::Mat sharpen = cv::imread(TextPath.toStdString());
    cv::Laplacian(sharpen,sharpen,sharpen.type());
    QImage sharpen_cv = CvMattoQImage(sharpen);
    QImage *final = new QImage(sharpen_cv);
    Image[current+1] = final;
    pixmap = QPixmap::fromImage(*Image[current+1]);
    ui->photo->setPixmap(pixmap.scaled(ui->photo->width(),ui->photo->height(),Qt::KeepAspectRatio));
    current++;
    *Image[current]=pixmap.toImage();
    Image[current]->save(TextPath);
    undoredo_enable();
}
void MainWindow::on_equalization_clicked()
{
    cv::Mat equalization = cv::imread(TextPath.toStdString());
    cv::cvtColor(equalization,equalization,CV_BGR2GRAY);
    cv::equalizeHist(equalization,equalization);
    QImage equalize = CvMattoQImage(equalization);
    QImage *final = new QImage(equalize);
    Image[current+1] = final;
    pixmap = QPixmap::fromImage(*Image[current+1]);
    ui->photo->setPixmap(pixmap.scaled(ui->photo->width(),ui->photo->height(),Qt::KeepAspectRatio));
    current++;
    *Image[current]=pixmap.toImage();
    Image[current]->save(TextPath);
    undoredo_enable();
}
void MainWindow::on_threshold_clicked()
{
    double maxvalue = 255;
    double mid = 127;
    cv::Mat temp = cv::imread(TextPath.toStdString());
    cv::Mat temp2 ;
    cv::Mat threshold;
    enum
    {
        THRESH_BINARY = 1,
        THRESH_BINARY_INV = 2,
        THRESH_TRUNC = 3,
        THRESH_TOZERO = 4,
        THRESH_TOZERO_INV = 5,
        THRESH_MASK = 6,
        THRESH_OTSU = 7,
    };
    int random = (rand()%7);
    cv::cvtColor(temp,temp2,CV_BGR2GRAY);
    cv::threshold(temp2,threshold,mid,maxvalue,random);
    QImage random_threshold = CvMattoQImage(threshold);
    QImage *final = new QImage(random_threshold);
    Image[current+1] = final;
    pixmap = QPixmap::fromImage(*Image[current+1]);
    ui->photo->setPixmap(pixmap.scaled(ui->photo->width(),ui->photo->height(),Qt::KeepAspectRatio));
    current++;
    *Image[current]=pixmap.toImage();
    Image[current]->save(TextPath);
    undoredo_enable();
}
void MainWindow::on_background_clicked()
{
    cv::Mat temp = cv::imread(TextPath.toStdString());
    cv::Mat background;
    enum
    {
        COLORMAP_AUTUMN = 0,
        COLORMAP_BONE = 1,
        COLORMAP_JET = 2,
        COLORMAP_WINTER = 3,
        COLORMAP_RAINBOW = 4,
        COLORMAP_OCEAN = 5,
        COLORMAP_SUMMER = 6,
        COLORMAP_SPRING = 7,
        COLORMAP_COOL = 8,
        COLORMAP_HSV = 9,
        COLORMAP_PINK = 10,
        COLORMAP_HOT = 11
    };
    int random = (rand()%11);
    cv::applyColorMap(temp,background,random);
    QImage random_background = CvMattoQImage(background);
    QImage *final = new QImage(random_background);
    Image[current+1] = final;
    pixmap = QPixmap::fromImage(*Image[current+1]);
    ui->photo->setPixmap(pixmap.scaled(ui->photo->width(),ui->photo->height(),Qt::KeepAspectRatio));
    current++;
    *Image[current]=pixmap.toImage();
    Image[current]->save(TextPath);
    undoredo_enable();
}
void MainWindow::on_contrast_color_clicked()
{
    Image[current+1]=contrast_exchange(Image[current]);
    pixmap = QPixmap::fromImage(*Image[current+1]);
    ui->photo->setPixmap(pixmap.scaled(ui->photo->width(),ui->photo->height(),Qt::KeepAspectRatio));
    current++;
    *Image[current]=pixmap.toImage();
    Image[current]->save(TextPath);
    undoredo_enable();
}
void MainWindow::on_resize_d_clicked()
{
    cv::Mat temp = cv::imread(TextPath.toStdString());
    cv::Mat resize;
    cv::resize(temp,resize,cv::Size(0,0),0.5,0.5,CV_INTER_AREA);
    QImage small = CvMattoQImage(resize);
    QImage *final = new QImage(small);
    Image[current+1] = final;
    pixmap = QPixmap::fromImage(*Image[current+1]);
    ui->photo->setPixmap(pixmap.scaled(ui->photo->width(),ui->photo->height(),Qt::KeepAspectRatio));
    current++;
    *Image[current]=pixmap.toImage();
    Image[current]->save(TextPath);
    undoredo_enable();
}
void MainWindow::on_resize_i_clicked()
{
    cv::Mat temp = cv::imread(TextPath.toStdString());
    cv::Mat resize;
    cv::resize(temp,resize,cv::Size(0,0),1.5,1.5,CV_INTER_LINEAR);
    QImage small = CvMattoQImage(resize);
    QImage *final = new QImage(small);
    Image[current+1] = final;
    pixmap = QPixmap::fromImage(*Image[current+1]);
    ui->photo->setPixmap(pixmap.scaled(ui->photo->width(),ui->photo->height(),Qt::KeepAspectRatio));
    current++;
    *Image[current]=pixmap.toImage();
    Image[current]->save(TextPath);
    undoredo_enable();
}
void MainWindow::on_saturation_clicked()
{
    ui->horizontalSlider_saturation->setEnabled(true);
}
void MainWindow::on_horizontalSlider_saturation_valueChanged(int value)
{
    saturationvalue=value;
    saturation(saturationvalue,Image[current]);
}
void MainWindow::on_horizontalSlider_saturation_sliderReleased()
{
    Image[current+1]=saturation(saturationvalue,Image[current]);
    pixmap = QPixmap::fromImage(*Image[current+1]);
    ui->photo->setPixmap(pixmap.scaled(ui->photo->width(),ui->photo->height(),Qt::KeepAspectRatio));
    current++;
    *Image[current]=pixmap.toImage();
    Image[current]->save(TextPath);
    ui->horizontalSlider_saturation->setEnabled(false);
    ui->horizontalSlider_saturation->setValue(0);
    undoredo_enable();
}
void MainWindow::on_brightness_clicked()
{
    ui->horizontalSlider_brightness->setEnabled(true);
}
void MainWindow::on_horizontalSlider_brightness_valueChanged(int value)
{
    double alpha = 1;
    double brightnessvalue = value;
    cv::Mat temp = cv::imread(TextPath.toStdString());
    cv::Mat brightness = cv::Mat::zeros(temp.size(), temp.type());
    for( int y = 0; y < temp.rows; y++ ){
        for( int x = 0; x < temp.cols; x++ ){
            for( int c = 0; c < 3; c++ ){
                brightness.at<cv::Vec3b>(y,x)[c] = cv::saturate_cast<uchar>( alpha*( temp.at<cv::Vec3b>(y,x)[c] )+brightnessvalue);
            }
        }
    }
    QImage brightnessadjust = CvMattoQImage(brightness);
    temporary = new QImage(brightnessadjust);
}
void MainWindow::on_horizontalSlider_brightness_sliderReleased()
{
    Image[current+1] = temporary;
    pixmap = QPixmap::fromImage(*Image[current+1]);
    ui->photo->setPixmap(pixmap.scaled(ui->photo->width(),ui->photo->height(),Qt::KeepAspectRatio));
    current++;
    *Image[current]=pixmap.toImage();
    Image[current]->save(TextPath);
    ui->horizontalSlider_brightness->setEnabled(false);
    undoredo_enable();
}
void MainWindow::on_warm_clicked()
{
    ui->horizontalSlider_warm->setEnabled(true);
}
void MainWindow::on_horizontalSlider_warm_valueChanged(int value)
{
    warmvalue=value;
    warm(warmvalue,Image[current]);
}
void MainWindow::on_horizontalSlider_warm_sliderReleased()
{
    Image[current+1]=warm(warmvalue,Image[current]);
    pixmap = QPixmap::fromImage(*Image[current+1]);
    ui->photo->setPixmap(pixmap.scaled(ui->photo->width(),ui->photo->height(),Qt::KeepAspectRatio));
    current++;
    *Image[current]=pixmap.toImage();
    Image[current]->save(TextPath);
    ui->horizontalSlider_warm->setEnabled(false);
    undoredo_enable();
}
void MainWindow::on_cold_clicked()
{
    ui->horizontalSlider_cold->setEnabled(true);
}
void MainWindow::on_horizontalSlider_cold_valueChanged(int value)
{
    coldvalue=value;
    cold(coldvalue,Image[current]);
}
void MainWindow::on_horizontalSlider_cold_sliderReleased()
{
    Image[current+1]=cold(coldvalue,Image[current]);
    pixmap = QPixmap::fromImage(*Image[current+1]);
    ui->photo->setPixmap(pixmap.scaled(ui->photo->width(),ui->photo->height(),Qt::KeepAspectRatio));
    current++;
    *Image[current]=pixmap.toImage();
    Image[current]->save(TextPath);
    ui->horizontalSlider_cold->setEnabled(false);
    undoredo_enable();
}
void MainWindow::on_contrast_clicked()
{
    ui->horizontalSlider_contrast->setEnabled(true);
}
void MainWindow::on_horizontalSlider_contrast_valueChanged(int value)
{
    double alpha ;
    double beta = 0;
    double contrastvalue = value;
    if (contrastvalue<1){
        alpha = 1+ (contrastvalue/100);
        beta = -contrastvalue;
    }
    else
        alpha = 1 + (contrastvalue/25);
    cv::Mat temp = cv::imread(TextPath.toStdString());
    cv::Mat contrast = cv::Mat::zeros(temp.size(), temp.type());
    for( int y = 0; y < temp.rows; y++ ){
        for( int x = 0; x < temp.cols; x++ ){
            for( int c = 0; c < 3; c++ ){
                contrast.at<cv::Vec3b>(y,x)[c] = cv::saturate_cast<uchar>( alpha*( temp.at<cv::Vec3b>(y,x)[c] )+beta);
            }
        }
    }
    QImage contrastadjust = CvMattoQImage(contrast);
    temporary = new QImage(contrastadjust);
}
void MainWindow::on_horizontalSlider_contrast_sliderReleased()
{
    Image[current+1] = temporary;
    pixmap = QPixmap::fromImage(*Image[current+1]);
    ui->photo->setPixmap(pixmap.scaled(ui->photo->width(),ui->photo->height(),Qt::KeepAspectRatio));
    current++;
    *Image[current]=pixmap.toImage();
    Image[current]->save(TextPath);
    ui->horizontalSlider_contrast->setEnabled(false);
    undoredo_enable();
}
void MainWindow::on_map_turn_clicked()
{
    cv::Mat temp = cv::imread(TextPath.toStdString());
    cv::Mat turn;
    cv::transpose(temp, turn);
    QImage turnimage = CvMattoQImage(turn);
    QImage *final = new QImage(turnimage);
    Image[current+1] = final;
    pixmap = QPixmap::fromImage(*Image[current+1]);
    ui->photo->setPixmap(pixmap.scaled(ui->photo->width(),ui->photo->height(),Qt::IgnoreAspectRatio));
    current++;
    *Image[current]=pixmap.toImage();
    Image[current]->save(TextPath);
    undoredo_enable();
}
void MainWindow::on_mirror_clicked()
{
    cv::Mat temp = cv::imread(TextPath.toStdString());
    cv::Mat mirror;
    cv::flip(temp, mirror,1);
    QImage turnimage = CvMattoQImage(mirror);
    QImage *final = new QImage(turnimage);
    Image[current+1] = final;
    pixmap = QPixmap::fromImage(*Image[current+1]);
    ui->photo->setPixmap(pixmap.scaled(ui->photo->width(),ui->photo->height(),Qt::IgnoreAspectRatio));
    current++;
    *Image[current]=pixmap.toImage();
    Image[current]->save(TextPath);
    undoredo_enable();
}
void MainWindow::on_save_clicked()
{
    if(Image[current]==NULL)
         QMessageBox::warning(0,0,"Image not found.");
    else{
        QString savepath=QFileDialog::getSaveFileName(this, tr("Save File"),"/",tr("PNG(*.png);;JPG(*.jpg)"));
        *Image[current]=pixmap.toImage();
        Image[current]->save(savepath);
    }
}
void MainWindow::on_exit_clicked()
{
    close();
}
void MainWindow::on_reset_clicked()
{
    current = 0;
    for(int i=0;i<50;i++){
        {Image[i]={NULL};}
        *Image=new QImage;
    }
    pixmap = QPixmap::fromImage(*Image[current]);
    ui->photo->setPixmap(pixmap.scaled(ui->photo->width(),ui->photo->height(),Qt::KeepAspectRatio));
    ui->grayscale->setEnabled(false);
    ui->grayscale2->setEnabled(false);
    ui->blur_g->setEnabled(false);
    ui->sharpen_cv->setEnabled(false);
    ui->equalization->setEnabled(false);
    ui->background->setEnabled(false);
    ui->contrast_color->setEnabled(false);
    ui->resize_d->setEnabled(false);
    ui->resize_i->setEnabled(false);
    ui->saturation->setEnabled(false);
    ui->horizontalSlider_saturation->setEnabled(false);
    ui->brightness->setEnabled(false);
    ui->horizontalSlider_brightness->setEnabled(false);
    ui->warm->setEnabled(false);
    ui->horizontalSlider_warm->setEnabled(false);
    ui->cold->setEnabled(false);
    ui->horizontalSlider_cold->setEnabled(false);
    ui->contrast->setEnabled(false);
    ui->horizontalSlider_contrast->setEnabled(false);
    ui->map_turn->setEnabled(false);
    ui->mirror->setEnabled(false);
    ui->save->setEnabled(false);
    ui->redo->setEnabled(false);
    ui->undo->setEnabled(false);
    ui->reset->setEnabled(false);
    ui->LoadImage->setEnabled(true);
}
//Mouse Event

