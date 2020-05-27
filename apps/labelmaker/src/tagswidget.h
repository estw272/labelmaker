#pragma once
#ifndef _TAGSWIDGET_H_093489
#define _TAGSWIDGET_H_093489

class TagsWidget: public QWidget {
    Q_OBJECT

public:
    explicit TagsWidget(QWidget* parent = nullptr);
    ~TagsWidget();

    void init_elements();
};

#endif
