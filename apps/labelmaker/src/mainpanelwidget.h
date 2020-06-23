#pragma once
#ifndef _MAINPANELWIDGET_H_938394
#define _MAINPANELWIDGET_H_938394

#include "imagelisttablemodel.h"
#include "tagswidget.h"
#include "imageinfo.h"

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
    std::set<ImageInfo> load_tags_from_file(std::wstring tags_file); // labels for each image
    void load_labels_from_file(std::wstring file_path); // labels list
    void set_labels(std::vector<QString>& labels_vec);

public slots:
    void load_folder();
    void image_selection_changed(const QModelIndex& current, const QModelIndex& previous);
    void next_image();
    void prev_image();
    void toggle_tag(QString name, bool active);
    void save_state_to_file();
    void save_labels_to_file();
    void export_to_csv();
    void set_new_labels();
    void forward_new_labels_set();

    TagsWidget* get_tags_widget() const;

signals:
    void num_images_loaded(int, int);
    void update_image_path(QString);
    void load_tags(std::set<std::string> tags);
    void labels_changed();
    void new_labels_set();
};

#endif
