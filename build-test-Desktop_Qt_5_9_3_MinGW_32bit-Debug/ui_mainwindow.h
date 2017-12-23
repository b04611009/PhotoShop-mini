/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionexit;
    QWidget *centralWidget;
    QPushButton *LoadImage;
    QLabel *photo;
    QLabel *Title;
    QLabel *icon;
    QPushButton *grayscale;
    QPushButton *grayscale2;
    QPushButton *blur_g;
    QPushButton *sharpen_cv;
    QPushButton *equalization;
    QPushButton *undo;
    QPushButton *redo;
    QPushButton *threshold;
    QPushButton *background;
    QLabel *icon_confirm;
    QLabel *word;
    QPushButton *contrast_color;
    QPushButton *resize_d;
    QPushButton *resize_i;
    QSlider *horizontalSlider_saturation;
    QPushButton *saturation;
    QPushButton *brightness;
    QSlider *horizontalSlider_brightness;
    QPushButton *warm;
    QSlider *horizontalSlider_warm;
    QPushButton *cold;
    QSlider *horizontalSlider_cold;
    QPushButton *contrast;
    QSlider *horizontalSlider_contrast;
    QPushButton *map_turn;
    QPushButton *mirror;
    QPushButton *save;
    QPushButton *exit;
    QPushButton *reset;
    QLabel *icon_exit;
    QMenuBar *menuBar;
    QMenu *menumenu;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1938, 968);
        MainWindow->setStyleSheet(QStringLiteral("border-color: qlineargradient(spread:repeat, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(255, 0, 0, 255), stop:0.166 rgba(255, 255, 0, 255), stop:0.333 rgba(0, 255, 0, 255), stop:0.5 rgba(0, 255, 255, 255), stop:0.666 rgba(0, 0, 255, 255), stop:0.833 rgba(255, 0, 255, 255), stop:1 rgba(255, 0, 0, 255))"));
        actionexit = new QAction(MainWindow);
        actionexit->setObjectName(QStringLiteral("actionexit"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        LoadImage = new QPushButton(centralWidget);
        LoadImage->setObjectName(QStringLiteral("LoadImage"));
        LoadImage->setGeometry(QRect(20, 820, 201, 71));
        QFont font;
        font.setFamily(QStringLiteral("Harlow Solid Italic"));
        font.setPointSize(18);
        font.setItalic(true);
        LoadImage->setFont(font);
        photo = new QLabel(centralWidget);
        photo->setObjectName(QStringLiteral("photo"));
        photo->setGeometry(QRect(460, 160, 831, 621));
        photo->setStyleSheet(QLatin1String("\n"
"border-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(255, 161, 30, 255), stop:0.5 rgba(110, 250, 60, 255), stop:1 rgba(96, 199, 193, 255));"));
        Title = new QLabel(centralWidget);
        Title->setObjectName(QStringLiteral("Title"));
        Title->setGeometry(QRect(30, 40, 521, 101));
        QFont font1;
        font1.setFamily(QStringLiteral("Harlow Solid Italic"));
        font1.setPointSize(36);
        font1.setBold(true);
        font1.setItalic(true);
        font1.setUnderline(true);
        font1.setWeight(75);
        Title->setFont(font1);
        Title->setStyleSheet(QStringLiteral("color :qlineargradient(spread:repeat, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(245, 224, 176, 255), stop:0.09 rgba(246, 189, 237, 255), stop:0.14 rgba(194, 207, 246, 255), stop:0.19 rgba(184, 160, 168, 255), stop:0.25 rgba(171, 186, 248, 255), stop:0.32 rgba(243, 248, 224, 255), stop:0.385 rgba(249, 162, 183, 255), stop:0.47 rgba(100, 115, 124, 255), stop:0.58 rgba(251, 205, 202, 255), stop:0.65 rgba(170, 128, 185, 255), stop:0.75 rgba(252, 222, 204, 255), stop:0.805 rgba(206, 122, 218, 255), stop:0.86 rgba(254, 223, 175, 255), stop:0.91 rgba(254, 236, 244, 255), stop:1 rgba(255, 191, 221, 255))"));
        icon = new QLabel(centralWidget);
        icon->setObjectName(QStringLiteral("icon"));
        icon->setGeometry(QRect(580, 40, 111, 101));
        grayscale = new QPushButton(centralWidget);
        grayscale->setObjectName(QStringLiteral("grayscale"));
        grayscale->setGeometry(QRect(19, 730, 201, 71));
        grayscale->setFont(font);
        grayscale2 = new QPushButton(centralWidget);
        grayscale2->setObjectName(QStringLiteral("grayscale2"));
        grayscale2->setGeometry(QRect(20, 640, 201, 71));
        grayscale2->setFont(font);
        blur_g = new QPushButton(centralWidget);
        blur_g->setObjectName(QStringLiteral("blur_g"));
        blur_g->setGeometry(QRect(20, 550, 201, 71));
        blur_g->setFont(font);
        sharpen_cv = new QPushButton(centralWidget);
        sharpen_cv->setObjectName(QStringLiteral("sharpen_cv"));
        sharpen_cv->setGeometry(QRect(20, 460, 201, 71));
        sharpen_cv->setFont(font);
        equalization = new QPushButton(centralWidget);
        equalization->setObjectName(QStringLiteral("equalization"));
        equalization->setGeometry(QRect(20, 370, 201, 71));
        equalization->setFont(font);
        undo = new QPushButton(centralWidget);
        undo->setObjectName(QStringLiteral("undo"));
        undo->setGeometry(QRect(760, 80, 101, 41));
        undo->setFont(font);
        redo = new QPushButton(centralWidget);
        redo->setObjectName(QStringLiteral("redo"));
        redo->setGeometry(QRect(900, 80, 101, 41));
        redo->setFont(font);
        threshold = new QPushButton(centralWidget);
        threshold->setObjectName(QStringLiteral("threshold"));
        threshold->setGeometry(QRect(20, 280, 201, 71));
        threshold->setFont(font);
        background = new QPushButton(centralWidget);
        background->setObjectName(QStringLiteral("background"));
        background->setGeometry(QRect(240, 280, 201, 71));
        background->setFont(font);
        icon_confirm = new QLabel(centralWidget);
        icon_confirm->setObjectName(QStringLiteral("icon_confirm"));
        icon_confirm->setGeometry(QRect(20, 170, 121, 91));
        word = new QLabel(centralWidget);
        word->setObjectName(QStringLiteral("word"));
        word->setGeometry(QRect(164, 170, 261, 91));
        QFont font2;
        font2.setFamily(QStringLiteral("Harlow Solid Italic"));
        font2.setPointSize(28);
        font2.setItalic(true);
        word->setFont(font2);
        word->setStyleSheet(QStringLiteral("color:qlineargradient(spread:repeat, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(0, 0, 0, 255), stop:1 rgba(255, 255, 255, 255))"));
        contrast_color = new QPushButton(centralWidget);
        contrast_color->setObjectName(QStringLiteral("contrast_color"));
        contrast_color->setGeometry(QRect(240, 370, 201, 71));
        contrast_color->setFont(font);
        resize_d = new QPushButton(centralWidget);
        resize_d->setObjectName(QStringLiteral("resize_d"));
        resize_d->setGeometry(QRect(240, 460, 201, 71));
        resize_d->setFont(font);
        resize_i = new QPushButton(centralWidget);
        resize_i->setObjectName(QStringLiteral("resize_i"));
        resize_i->setGeometry(QRect(240, 550, 201, 71));
        resize_i->setFont(font);
        horizontalSlider_saturation = new QSlider(centralWidget);
        horizontalSlider_saturation->setObjectName(QStringLiteral("horizontalSlider_saturation"));
        horizontalSlider_saturation->setGeometry(QRect(1319, 260, 201, 31));
        horizontalSlider_saturation->setOrientation(Qt::Horizontal);
        saturation = new QPushButton(centralWidget);
        saturation->setObjectName(QStringLiteral("saturation"));
        saturation->setGeometry(QRect(1320, 160, 201, 71));
        saturation->setFont(font);
        brightness = new QPushButton(centralWidget);
        brightness->setObjectName(QStringLiteral("brightness"));
        brightness->setGeometry(QRect(1590, 160, 201, 71));
        brightness->setFont(font);
        horizontalSlider_brightness = new QSlider(centralWidget);
        horizontalSlider_brightness->setObjectName(QStringLiteral("horizontalSlider_brightness"));
        horizontalSlider_brightness->setGeometry(QRect(1590, 260, 201, 31));
        horizontalSlider_brightness->setOrientation(Qt::Horizontal);
        warm = new QPushButton(centralWidget);
        warm->setObjectName(QStringLiteral("warm"));
        warm->setGeometry(QRect(1320, 340, 201, 71));
        warm->setFont(font);
        horizontalSlider_warm = new QSlider(centralWidget);
        horizontalSlider_warm->setObjectName(QStringLiteral("horizontalSlider_warm"));
        horizontalSlider_warm->setGeometry(QRect(1320, 440, 201, 31));
        horizontalSlider_warm->setOrientation(Qt::Horizontal);
        cold = new QPushButton(centralWidget);
        cold->setObjectName(QStringLiteral("cold"));
        cold->setGeometry(QRect(1590, 340, 201, 71));
        cold->setFont(font);
        horizontalSlider_cold = new QSlider(centralWidget);
        horizontalSlider_cold->setObjectName(QStringLiteral("horizontalSlider_cold"));
        horizontalSlider_cold->setGeometry(QRect(1590, 440, 201, 31));
        horizontalSlider_cold->setOrientation(Qt::Horizontal);
        contrast = new QPushButton(centralWidget);
        contrast->setObjectName(QStringLiteral("contrast"));
        contrast->setGeometry(QRect(1320, 520, 201, 71));
        contrast->setFont(font);
        horizontalSlider_contrast = new QSlider(centralWidget);
        horizontalSlider_contrast->setObjectName(QStringLiteral("horizontalSlider_contrast"));
        horizontalSlider_contrast->setGeometry(QRect(1320, 620, 201, 31));
        horizontalSlider_contrast->setOrientation(Qt::Horizontal);
        map_turn = new QPushButton(centralWidget);
        map_turn->setObjectName(QStringLiteral("map_turn"));
        map_turn->setGeometry(QRect(240, 640, 201, 71));
        map_turn->setFont(font);
        mirror = new QPushButton(centralWidget);
        mirror->setObjectName(QStringLiteral("mirror"));
        mirror->setGeometry(QRect(240, 730, 201, 71));
        mirror->setFont(font);
        save = new QPushButton(centralWidget);
        save->setObjectName(QStringLiteral("save"));
        save->setGeometry(QRect(240, 820, 201, 71));
        save->setFont(font);
        exit = new QPushButton(centralWidget);
        exit->setObjectName(QStringLiteral("exit"));
        exit->setGeometry(QRect(1670, 810, 201, 71));
        QFont font3;
        font3.setFamily(QStringLiteral("Harlow Solid Italic"));
        font3.setPointSize(20);
        font3.setItalic(true);
        exit->setFont(font3);
        exit->setStyleSheet(QStringLiteral(""));
        reset = new QPushButton(centralWidget);
        reset->setObjectName(QStringLiteral("reset"));
        reset->setGeometry(QRect(1040, 80, 101, 41));
        reset->setFont(font);
        icon_exit = new QLabel(centralWidget);
        icon_exit->setObjectName(QStringLiteral("icon_exit"));
        icon_exit->setGeometry(QRect(1460, 780, 181, 131));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1938, 17));
        menumenu = new QMenu(menuBar);
        menumenu->setObjectName(QStringLiteral("menumenu"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menumenu->menuAction());
        menumenu->addAction(actionexit);

        retranslateUi(MainWindow);
        QObject::connect(actionexit, SIGNAL(triggered()), MainWindow, SLOT(close()));

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", Q_NULLPTR));
        actionexit->setText(QApplication::translate("MainWindow", "exit", Q_NULLPTR));
        LoadImage->setText(QApplication::translate("MainWindow", "Load Image", Q_NULLPTR));
        photo->setText(QString());
        Title->setText(QApplication::translate("MainWindow", " P h o t o S h o p ", Q_NULLPTR));
        icon->setText(QString());
        grayscale->setText(QApplication::translate("MainWindow", "grayscale_cv", Q_NULLPTR));
        grayscale2->setText(QApplication::translate("MainWindow", "grayscale_qt", Q_NULLPTR));
        blur_g->setText(QApplication::translate("MainWindow", "blur_gaussian", Q_NULLPTR));
        sharpen_cv->setText(QApplication::translate("MainWindow", "sharpen_cv", Q_NULLPTR));
        equalization->setText(QApplication::translate("MainWindow", "equalization", Q_NULLPTR));
        undo->setText(QApplication::translate("MainWindow", "undo", Q_NULLPTR));
        redo->setText(QApplication::translate("MainWindow", "redo", Q_NULLPTR));
        threshold->setText(QApplication::translate("MainWindow", "threshold", Q_NULLPTR));
        background->setText(QApplication::translate("MainWindow", "background", Q_NULLPTR));
        icon_confirm->setText(QString());
        word->setText(QApplication::translate("MainWindow", "basic effects", Q_NULLPTR));
        contrast_color->setText(QApplication::translate("MainWindow", "contrast_color", Q_NULLPTR));
        resize_d->setText(QApplication::translate("MainWindow", "dpi_deprove", Q_NULLPTR));
        resize_i->setText(QApplication::translate("MainWindow", "dpi_improve", Q_NULLPTR));
        saturation->setText(QApplication::translate("MainWindow", "satuation", Q_NULLPTR));
        brightness->setText(QApplication::translate("MainWindow", "brightness", Q_NULLPTR));
        warm->setText(QApplication::translate("MainWindow", "warm", Q_NULLPTR));
        cold->setText(QApplication::translate("MainWindow", "cold", Q_NULLPTR));
        contrast->setText(QApplication::translate("MainWindow", "contrast", Q_NULLPTR));
        map_turn->setText(QApplication::translate("MainWindow", "map_turn", Q_NULLPTR));
        mirror->setText(QApplication::translate("MainWindow", "mirror", Q_NULLPTR));
        save->setText(QApplication::translate("MainWindow", "Save Image", Q_NULLPTR));
        exit->setText(QApplication::translate("MainWindow", "Exit", Q_NULLPTR));
        reset->setText(QApplication::translate("MainWindow", "reset", Q_NULLPTR));
        icon_exit->setText(QString());
        menumenu->setTitle(QApplication::translate("MainWindow", "menu", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
