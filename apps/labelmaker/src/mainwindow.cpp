#include "pch.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "mainwidget.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);

    this->setWindowTitle("LabelMaker");

    register_custom_structs();
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

void MainWindow::register_custom_structs() {
    qRegisterMetaType<std::set<std::string>>("std::set<std::string>>");
}

void MainWindow::status_display_num_imgs_loaded(int index_selected, int num_imgs) {
    if (index_selected < 0) {
        statusBar()->showMessage(QString::number(num_imgs) + " files");
    } else {
        statusBar()->showMessage(QString::number(index_selected) + " of " + QString::number(num_imgs) + " files");
    }
}

