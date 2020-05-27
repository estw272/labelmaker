#pragma once
#ifndef _IMAGELISTTABLEMODEL_H_829382
#define _IMAGELISTTABLEMODEL_H_829382

class ImageListTableModel: public QAbstractTableModel {
    Q_OBJECT

public:

public:
    explicit ImageListTableModel(QObject* parent = nullptr);

    int rowCount(const QModelIndex& parent = QModelIndex()) const override;
    int columnCount(const QModelIndex& parent = QModelIndex()) const override;
    QVariant data(const QModelIndex& index, int role = Qt::DisplayRole) const override;
    QVariant headerData(int section, Qt::Orientation orientation, int role) const override;
};

#endif
