#include "pch.h"
#include "programstate.h"

ProgramState::ProgramState() {
    //#TODO: implement adding tags
//    tags_.push_back("ignore");
//    tags_.push_back("seal");
//    tags_.push_back("signature");
//    tags_.push_back("name");
//    tags_.push_back("date");

    hotkeys_.push_back(QKeySequence(Qt::Key_1));
    hotkeys_.push_back(QKeySequence(Qt::Key_2));
    hotkeys_.push_back(QKeySequence(Qt::Key_3));
    hotkeys_.push_back(QKeySequence(Qt::Key_4));
    hotkeys_.push_back(QKeySequence(Qt::Key_5));
    hotkeys_.push_back(QKeySequence(Qt::Key_6));
    hotkeys_.push_back(QKeySequence(Qt::Key_7));
    hotkeys_.push_back(QKeySequence(Qt::Key_8));
    hotkeys_.push_back(QKeySequence(Qt::Key_9));
    hotkeys_.push_back(QKeySequence(Qt::Key_0));
}

const std::vector<QString> ProgramState::get_tags() const {
    return tags_;
}

QString ProgramState::get_open_path() const {
    return QString::fromStdWString(open_path_);
}

void ProgramState::set_open_path(QString path) {
    open_path_ = path.toStdWString();
}

void ProgramState::set_open_path(std::wstring path) {
    open_path_ = path;
}

const std::vector<QKeySequence> ProgramState::get_hotkeys() const {
    return hotkeys_;
}

void ProgramState::write_labels(std::vector<QString> labels) {
    tags_.swap(labels);
    reset_labels_counter();
}

void ProgramState::reset_labels_counter() {
    labels_counter_.clear();
    for_each(tags_.cbegin(), tags_.cend(), [this](auto item){
        labels_counter_[item] = 0;
    });
}

const std::map<QString, int> ProgramState::get_labels_count() const {
    return labels_counter_;
}

void ProgramState::increment_label_counter(QString label) {
    if (labels_counter_.find(label) != labels_counter_.end()) {
        labels_counter_.at(label) += 1;
    }
}

void ProgramState::decrement_label_counter(QString label) {
    if (labels_counter_.find(label) != labels_counter_.end()) {
        labels_counter_.at(label) -= 1;
    }
}

void ProgramState::set_labels_counter(const std::vector<ImageInfo>& data) {
    if (!tags_.empty() && !data.empty()) {
        reset_labels_counter();

        std::for_each(data.cbegin(), data.cend(), [this](auto image_info){
            std::for_each(image_info.tags_.cbegin(), image_info.tags_.cend(), [this](auto tag){
                labels_counter_[QString::fromStdString(tag)] += 1;
            });
        });
    }
}
