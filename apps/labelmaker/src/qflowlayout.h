#pragma once
#ifndef _QFLOWLAYOUT_H_928392
#define _QFLOWLAYOUT_H_928392

class QFlowLayout : public QLayout {
private:
    QList<QLayoutItem *> item_list_;
    int hspace_;
    int vspace_;

public:
    explicit QFlowLayout(QWidget *parent, int margin = -1, int hSpacing = -1, int vSpacing = -1);
    explicit QFlowLayout(int margin = -1, int hSpacing = -1, int vSpacing = -1);
    ~QFlowLayout();

    void addItem(QLayoutItem *item) override;
    void clear();
    int horizontalSpacing() const;
    int verticalSpacing() const;
    Qt::Orientations expandingDirections() const override;
    bool hasHeightForWidth() const override;
    int heightForWidth(int) const override;
    int count() const override;
    QLayoutItem* itemAt(int index) const override;
    QSize minimumSize() const override;
    void setGeometry(const QRect &rect) override;
    QSize sizeHint() const override;
    QLayoutItem* takeAt(int index) override;
    size_t num_tags() const;

private:
    int doLayout(const QRect &rect, bool testOnly) const;
    int smartSpacing(QStyle::PixelMetric pm) const;
};

#endif