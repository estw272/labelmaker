#include "pch.h"
#include "imagelisttablemodel.h"

ImageListTableModel::ImageListTableModel(QObject *parent) : QAbstractTableModel(parent) {

}

int ImageListTableModel::rowCount(const QModelIndex &parent) const {
    return 1;
}

int ImageListTableModel::columnCount(const QModelIndex &parent) const {
    return 0;
}

QVariant ImageListTableModel::data(const QModelIndex &index, int role) const {
    return QVariant();
}

QVariant ImageListTableModel::headerData(int section, Qt::Orientation orientation, int role) const {
    return QAbstractItemModel::headerData(section, orientation, role);
}
