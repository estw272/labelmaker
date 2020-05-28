#include "pch.h"
#include "qflowlayout.h"

QFlowLayout::QFlowLayout(QWidget *parent, int margin, int hSpacing, int vSpacing) :
        QLayout(parent),
        hspace_(hSpacing),
        vspace_(vSpacing) {

    setContentsMargins(margin, margin, margin, margin);
}

QFlowLayout::QFlowLayout(int margin, int hSpacing, int vSpacing) : hspace_(hSpacing), vspace_(vSpacing) {
    setContentsMargins(margin, margin, margin, margin);
}

QFlowLayout::~QFlowLayout() {
    QLayoutItem* item;
    while ((item = takeAt(0))) {
        delete item;
    }
}

void QFlowLayout::addItem(QLayoutItem* item) {
    item_list_.append(item);
}

int QFlowLayout::horizontalSpacing() const {
    if (hspace_ >= 0) {
        return hspace_;
    } else {
        return smartSpacing(QStyle::PM_LayoutHorizontalSpacing);
    }
}

int QFlowLayout::verticalSpacing() const {
    if (vspace_ >= 0) {
        return vspace_;
    } else {
        return smartSpacing(QStyle::PM_LayoutVerticalSpacing);
    }
}

int QFlowLayout::count() const {
    return item_list_.size();
}

QLayoutItem* QFlowLayout::itemAt(int index) const {
    return item_list_.value(index);
}

QLayoutItem* QFlowLayout::takeAt(int index) {
    if (index >= 0 && index < item_list_.size()) {
        return item_list_.takeAt(index);
    }
    return nullptr;
}

Qt::Orientations QFlowLayout::expandingDirections() const {
    return { };
}

bool QFlowLayout::hasHeightForWidth() const {
    return true;
}

int QFlowLayout::heightForWidth(int width) const {
    int height = doLayout(QRect(0, 0, width, 0), true);
    return height;
}

void QFlowLayout::setGeometry(const QRect &rect) {
    QLayout::setGeometry(rect);
    doLayout(rect, false);
}

QSize QFlowLayout::sizeHint() const {
    return minimumSize();
}

QSize QFlowLayout::minimumSize() const {
    QSize size;
    for (const QLayoutItem* item : qAsConst(item_list_)) {
        size = size.expandedTo(item->minimumSize());
    }

    const QMargins margins = contentsMargins();
    size += QSize(margins.left() + margins.right(), margins.top() + margins.bottom());
    return size;
}

int QFlowLayout::doLayout(const QRect &rect, bool testOnly) const {
    int left, top, right, bottom;
    getContentsMargins(&left, &top, &right, &bottom);
    QRect effectiveRect = rect.adjusted(+left, +top, -right, -bottom);
    int x = effectiveRect.x();
    int y = effectiveRect.y();
    int lineHeight = 0;
    for (QLayoutItem* item : qAsConst(item_list_)) {
        const QWidget* wid = item->widget();
        int spaceX = horizontalSpacing();
        if (spaceX == -1)
            spaceX = wid->style()->layoutSpacing(
                    QSizePolicy::PushButton, QSizePolicy::PushButton, Qt::Horizontal);
        int spaceY = verticalSpacing();
        if (spaceY == -1)
            spaceY = wid->style()->layoutSpacing(
                    QSizePolicy::PushButton, QSizePolicy::PushButton, Qt::Vertical);
        int nextX = x + item->sizeHint().width() + spaceX;
        if (nextX - spaceX > effectiveRect.right() && lineHeight > 0) {
            x = effectiveRect.x();
            y = y + lineHeight + spaceY;
            nextX = x + item->sizeHint().width() + spaceX;
            lineHeight = 0;
        }

        if (!testOnly)
            item->setGeometry(QRect(QPoint(x, y), item->sizeHint()));

        x = nextX;
        lineHeight = qMax(lineHeight, item->sizeHint().height());
    }
    return y + lineHeight - rect.y() + bottom;
}

int QFlowLayout::smartSpacing(QStyle::PixelMetric pm) const {
    QObject* parent = this->parent();
    if (!parent) {
        return -1;
    } else if (parent->isWidgetType()) {
        QWidget* pw = static_cast<QWidget*>(parent);
        return pw->style()->pixelMetric(pm, nullptr, pw);
    } else {
        return static_cast<QLayout*>(parent)->spacing();
    }
}