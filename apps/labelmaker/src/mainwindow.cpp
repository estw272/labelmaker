#include "pch.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "mainwidget.h"
#include "programstate.h"

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
    connect(this, &MainWindow::save_state, main_widget, &MainWidget::forward_save_state);
}

void MainWindow::register_custom_structs() {
    qRegisterMetaType<std::set<std::string>>("std::set<std::string>>");
}

void MainWindow::status_display_num_imgs_loaded(int index_selected, int num_imgs) {
    QString filenum_display;
    if (index_selected < 0) {
//        statusBar()->showMessage(QString::number(num_imgs) + " files");
        filenum_display = QString::number(num_imgs) + " files";
    } else {
//        statusBar()->showMessage(QString::number(index_selected) + " of " + QString::number(num_imgs) + " files");
        filenum_display = QString::number(index_selected) + " of " + QString::number(num_imgs) + " files";
    }

    auto labels_count = ProgramState::instance().get_labels_count();
    int total_labels = 0;
    std::for_each(labels_count.cbegin(), labels_count.cend(), [&total_labels](auto item){
        total_labels += item.second;
    });
    QString count_display;
    for (const auto& [label, count]: labels_count) {
        double label_percentage = (total_labels == 0) ? 0 : (static_cast<double>(count) / total_labels) * 100;
        count_display += "'" + label + "'" + ": " + QString::number(count) +
                "(" + QString::number(label_percentage, 'f', 1) + "%), " ;
    }
    std::cout << total_labels << "\n";
    count_display = count_display.trimmed();
    count_display.truncate(count_display.size() - 1);

    statusBar()->showMessage(filenum_display + "   |   " + count_display);
}

void MainWindow::closeEvent(QCloseEvent* event) {
    emit save_state();
}
