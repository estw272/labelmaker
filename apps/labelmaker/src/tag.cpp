#include "pch.h"
#include "tag.h"

Tag::Tag(const QString& text, QWidget* parent) : QPushButton(text, parent), selected_(false) {
    this->setFlat(true);
    set_disabled();

    connect(this, &QPushButton::clicked, this, &Tag::toggle);
}

void Tag::toggle() {
    selected_ = !selected_;

    if (selected_) {
        set_enabled();
    } else {
        set_disabled();
    }
}

void Tag::reset() {
    set_disabled();
}

void Tag::set_enabled() {
    this->setStyleSheet("QPushButton {"
                        "color: black;"
                        "border-top: 3px transparent;"
                        "border-bottom: 3px transparent;"
                        "border-right: 10px transparent;"
                        "border-left: 10px transparent;"
                        "text-decoration: underline;"
                        //                              "border: 1px solid grey;"
                        //                              "border-radius: 5px;"
                        //                              "font-size: 25px;"
                        "}");
}

void Tag::set_disabled() {
    this->setStyleSheet("QPushButton {"
                        "color: grey;"
                        "border-top: 3px transparent;"
                        "border-bottom: 3px transparent;"
                        "border-right: 10px transparent;"
                        "border-left: 10px transparent;"
                        //                              "border: 1px solid grey;"
                        //                              "border-radius: 5px;"
                        //                              "font-size: 25px;"
                        "}");
}
