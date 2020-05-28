#include "pch.h"
#include "imagelisttablemodel.h"

ImageListTableModel::ImageListTableModel(QObject *parent) : QAbstractTableModel(parent) {

}

int ImageListTableModel::rowCount(const QModelIndex &parent) const {
    return data_container_.size();
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
            if (col == 0) { return data_container_.at(data_index); }
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

void ImageListTableModel::update_data(std::vector<QString> &new_data) {
    std::lock_guard lk(data_mutex_);

    this->beginResetModel();
    data_container_.swap(new_data);
    this->endResetModel();
}
