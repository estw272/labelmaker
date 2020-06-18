#include "pch.h"
#include "imagelisttablemodel.h"

ImageListTableModel::ImageListTableModel(QObject *parent) : QAbstractTableModel(parent) {

}

int ImageListTableModel::rowCount(const QModelIndex &parent) const {
    return static_cast<int>(data_container_.size());
}

int ImageListTableModel::columnCount(const QModelIndex &parent) const {
    return 1;
}

QVariant ImageListTableModel::data(const QModelIndex &index, int role) const {
    int row = index.row();
    int col = index.column();
    int data_index = row;

    switch (role) {
        case Qt::DisplayRole:
            if (col == 0) { return QString::fromStdString(data_container_.at(data_index).file_name_); }
            break;

        case Qt::BackgroundRole:
            if (data_container_.at(data_index).tags_.find("ignore") != data_container_.at(data_index).tags_.end()) {
                return QBrush(QColor(255, 214, 204));
            } else if (!data_container_.at(data_index).tags_.empty() &&
                        data_container_.at(data_index).tags_.size() < 4) {

                return QBrush(QColor(204, 204, 255));
            } else if (!data_container_.at(data_index).tags_.empty()) {
                return QBrush(QColor(179, 255, 179));
            }
            break;
    }

    return QVariant();
}

QVariant ImageListTableModel::headerData(int section, Qt::Orientation orientation, int role) const {
    if (role == Qt::DisplayRole && orientation == Qt::Horizontal) {
        switch (section) {
            case 0:
                return QString("File");
                break;
        }
    }
    return QVariant();
}

void ImageListTableModel::update_data(std::vector<ImageInfo> &new_data) {
    std::lock_guard lk(data_mutex_);

    this->beginResetModel();
    data_container_.swap(new_data);
    this->endResetModel();
}

const std::vector<ImageInfo>& ImageListTableModel::data_ref() const {
    return data_container_;
}

ImageInfo& ImageListTableModel::get_data_ref(std::string& filename) {
    for (auto& item: data_container_) {
        if (item.file_name_ == filename) {
            return item;
        }
    }

    return data_container_.at(0);
}
