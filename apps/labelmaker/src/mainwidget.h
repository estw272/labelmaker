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
    QTableView* images_list_table_;

public:
    explicit MainWidget(QWidget *parent = nullptr);
    ~MainWidget();

private:
    void init_elements();

};

#endif // MAINWIDGET_H
