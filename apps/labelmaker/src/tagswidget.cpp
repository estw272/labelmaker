#include "pch.h"
#include "tagswidget.h"
#include "programstate.h"
#include "tag.h"

TagsWidget::TagsWidget(QWidget *parent) : QWidget(parent) {
    const auto tags = ProgramState::instance().get_tags();

    std::copy(tags.cbegin(), tags.cend(), std::back_inserter(tags_vec_));


    init_elements();
}

TagsWidget::~TagsWidget() {
}

void TagsWidget::init_elements() {
    tags_layout_ = new QFlowLayout();

    std::for_each(tags_vec_.cbegin(), tags_vec_.cend(), [&, this](auto item){
        Tag* tag = new Tag(item);
        tags_layout_->addWidget(tag);
    });

    this->setLayout(tags_layout_);
}

QFlowLayout *TagsWidget::get_flow_layout() const {
    return tags_layout_;
}
