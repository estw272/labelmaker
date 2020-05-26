#pragma once
#ifndef _MAINPANELWIDGET_H_938394
#define _MAINPANELWIDGET_H_938394

class MainPanelWidget: public QWidget {
    Q_OBJECT

private:
    QVBoxLayout* main_layout_;
    QTableView* images_table_;

public:
    explicit MainPanelWidget(QWidget* parent = nullptr);
    ~MainPanelWidget();

private:
    void init_elements();
};

#endif
