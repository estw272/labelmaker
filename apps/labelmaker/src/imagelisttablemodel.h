#pragma once
#ifndef _IMAGELISTTABLEMODEL_H_829382
#define _IMAGELISTTABLEMODEL_H_829382

#include "imageinfo.h"

class ImageListTableModel: public QAbstractTableModel {
    Q_OBJECT

private:
    std::vector<ImageInfo> data_container_;
    std::mutex data_mutex_;

public:
    explicit ImageListTableModel(QObject* parent = nullptr);

    int rowCount(const QModelIndex& parent = QModelIndex()) const override;
    int columnCount(const QModelIndex& parent = QModelIndex()) const override;
    QVariant data(const QModelIndex& index, int role = Qt::DisplayRole) const override;
    QVariant headerData(int section, Qt::Orientation orientation, int role) const override;

    void update_data(std::vector<ImageInfo>& new_data);
    const std::vector<ImageInfo>& data_ref() const;

    ImageInfo& get_data_ref(std::string& filename);
    std::vector<ImageInfo> get_data() const;

};

#endif
