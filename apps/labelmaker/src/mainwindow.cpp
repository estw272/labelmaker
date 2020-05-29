#include "pch.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "mainwidget.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);

    this->setWindowTitle("LabelMaker");

    init_elements();
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::init_elements() {
    MainWidget* main_widget = new MainWidget();
    ui->main_widget_holder->addWidget(main_widget);

    connect(main_widget, &MainWidget::num_images_loaded, this, &MainWindow::status_display_num_imgs_loaded);
}

void MainWindow::status_display_num_imgs_loaded(int num_imgs) {
    statusBar()->showMessage(QString::number(num_imgs) + " files");
}
