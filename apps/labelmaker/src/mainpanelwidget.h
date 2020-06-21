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
    void image_selection_changed(const QModelIndex& current, const QModelIndex& previous);
    void next_image();
    void prev_image();
    void toggle_tag(QString name, bool active);
    void save_state_to_file();

    TagsWidget* get_tags_widget() const;

signals:
    void num_images_loaded(int, int);
    void update_image_path(QString);
    void load_tags(std::set<std::string> tags);

};

#endif
