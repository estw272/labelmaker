#pragma once
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow {
    Q_OBJECT

private:
    Ui::MainWindow *ui;

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    void init_elements();
    void register_custom_structs();

public slots:
    void status_display_num_imgs_loaded(int index_selected, int num_imgs);
};

#endif // MAINWINDOW_H
