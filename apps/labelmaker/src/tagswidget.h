#pragma once
#ifndef _TAGSWIDGET_H_093489
#define _TAGSWIDGET_H_093489

#include "qflowlayout.h"

class TagsWidget: public QWidget {
    Q_OBJECT

private:
    QFlowLayout* tags_layout_;
    std::vector<QString> tags_vec_;
    std::vector<QShortcut*> key_sequences_;

public:
    explicit TagsWidget(QWidget* parent = nullptr);
    ~TagsWidget();

    void init_elements();
    QFlowLayout* get_flow_layout() const;

public slots:
    void forward_tag_toggle(QString name, bool active);
    void forward_load_tags(std::set<std::string> tags);

signals:
    void tag_toggled(QString name, bool active);
    void load_tags(std::set<std::string> tags);
};

#endif
