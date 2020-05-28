#include "pch.h"
#include "programstate.h"

ProgramState::ProgramState() {
    //#TODO: implement adding tags
    tags_.push_back("ignore");
    tags_.push_back("seal");
    tags_.push_back("signature");
    tags_.push_back("name");
    tags_.push_back("date");
}

std::vector<QString> ProgramState::get_tags() const {
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
