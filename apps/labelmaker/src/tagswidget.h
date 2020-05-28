#pragma once
#ifndef _TAGSWIDGET_H_093489
#define _TAGSWIDGET_H_093489

#include "qflowlayout.h"

class TagsWidget: public QWidget {
    Q_OBJECT

private:
    QFlowLayout* tags_layout_;
    std::vector<QString> tags_vec_;

public:
    explicit TagsWidget(QWidget* parent = nullptr);
    ~TagsWidget();

    void init_elements();
};

#endif
