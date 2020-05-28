#include "pch.h"
#include "tagswidget.h"
#include "programstate.h"

TagsWidget::TagsWidget(QWidget *parent) : QWidget(parent) {
    auto tags = ProgramState::instance().get_tags();
    std::copy(tags.cbegin(), tags.cend(), std::back_inserter(tags_vec_));

    init_elements();
}

TagsWidget::~TagsWidget() {
}

void TagsWidget::init_elements() {
    tags_layout_ = new QFlowLayout();

    std::for_each(tags_vec_.cbegin(), tags_vec_.cend(), [this](auto item){
        QPushButton* button = new QPushButton(item);
        button->setFlat(true);
//        button->setGeometry(QRect(0, 0, 150, 100));
        button->setStyleSheet("QPushButton {"
                              "color: grey;"
                              "border-top: 3px transparent;"
                              "border-bottom: 3px transparent;"
                              "border-right: 10px transparent;"
                              "border-left: 10px transparent;"
//                              "border: 1px solid grey;"
//                              "border-radius: 5px;"
//                              "font-size: 25px;"
                              "}");
        tags_layout_->addWidget(button);
    });

    this->setLayout(tags_layout_);
}
