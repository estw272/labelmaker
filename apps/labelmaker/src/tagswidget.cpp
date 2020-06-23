#include "pch.h"
#include "tagswidget.h"
#include "programstate.h"
#include "tag.h"

TagsWidget::TagsWidget(QWidget *parent) : QWidget(parent) {


    init_elements();
}

TagsWidget::~TagsWidget() {
}

void TagsWidget::init_elements() {
    tags_layout_ = new QFlowLayout();

//    std::for_each(tags_vec_.cbegin(), tags_vec_.cend(), [&, this](auto item){
//        Tag* tag = new Tag(item);
//        tags_layout_->addWidget(tag);
//
//        connect(tag, &Tag::tag_toggled, this, &TagsWidget::forward_tag_toggle);
//        connect(this, &TagsWidget::load_tags, tag, &Tag::toggle_display_tags);
//    });

    this->setLayout(tags_layout_);
}

QFlowLayout *TagsWidget::get_flow_layout() const {
    return tags_layout_;
}

void TagsWidget::forward_tag_toggle(QString name, bool active) {
    emit tag_toggled(name, active);
}

void TagsWidget::forward_load_tags(std::set<std::string> tags) {
    emit load_tags(tags);
}

void TagsWidget::add_tags() {
    tags_layout_->clear();

    const auto tags = ProgramState::instance().get_tags();
//    std::copy(tags.cbegin(), tags.cend(), std::back_inserter(tags_vec_));

    std::for_each(tags.cbegin(), tags.cend(), [&, this](auto item){
        Tag* tag = new Tag(item);
        tags_layout_->addWidget(tag);

        connect(tag, &Tag::tag_toggled, this, &TagsWidget::forward_tag_toggle);
        connect(this, &TagsWidget::load_tags, tag, &Tag::toggle_display_tags);
    });
    this->setLayout(tags_layout_);
    std::cout << tags_layout_->count() << "\n";
}
