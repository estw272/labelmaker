#pragma once
#ifndef _MAINPANELWIDGET_H_938394
#define _MAINPANELWIDGET_H_938394

#include "imagelisttablemodel.h"
#include "tagswidget.h"

class MainPanelWidget: public QWidget {
    Q_OBJECT

private:
    QVBoxLayout* main_layout_;
    TagsWidget* tags_widget_;

    QTableView* images_table_;
    ImageListTableModel* images_table_model_;
    QSortFilterProxyModel* images_table_model_proxy_;

public:
    explicit MainPanelWidget(QWidget* parent = nullptr);
    ~MainPanelWidget();

private:
    void init_elements();

public slots:
    void load_folder();
};

#endif
