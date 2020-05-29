#ifndef MAINWIDGET_H
#define MAINWIDGET_H

#include <QWidget>

namespace Ui {
class MainWidget;
}

class MainWidget : public QWidget {
    Q_OBJECT

private:
    Ui::MainWidget *ui;

    QVBoxLayout* main_layout_;

public:
    explicit MainWidget(QWidget *parent = nullptr);
    ~MainWidget();

private:
    void init_elements();

public slots:
    void forward_num_images_loaded(int index_selected, int num_imgs);

signals:
    void num_images_loaded(int, int);

};

#endif // MAINWIDGET_H
