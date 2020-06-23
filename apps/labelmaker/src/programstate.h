#pragma once
#ifndef _PROGRAMSTATE_H_328984
#define _PROGRAMSTATE_H_328984

#include "imageinfo.h"

class ProgramState {
public:

private:
    std::vector<QString> tags_;
    std::wstring open_path_ {};

    std::vector<QKeySequence> hotkeys_;
    std::map<QString, int> labels_counter_;

public:
    ProgramState(const ProgramState&) = delete;
    ProgramState& operator=(const ProgramState&) = delete;
    ProgramState(ProgramState&&) = delete;
    ProgramState& operator=(ProgramState&&) = delete;

    static ProgramState& instance() {
        static ProgramState instance;
        return instance;
    }

    [[nodiscard]] const std::vector<QString> get_tags() const;
    [[nodiscard]] const std::vector<QKeySequence> get_hotkeys() const;

    void write_labels(std::vector<QString> labels);

    [[nodiscard]] QString get_open_path() const;
    void set_open_path(QString path);
    void set_open_path(std::wstring path);
    void increment_label_counter(QString label);
    void decrement_label_counter(QString label);
    void set_labels_counter(const std::vector<ImageInfo>& data);

    const std::map<QString, int> get_labels_count() const;

private:
    ProgramState();

    void reset_labels_counter();
};

#endif
