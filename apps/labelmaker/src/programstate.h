#pragma once
#ifndef _PROGRAMSTATE_H_328984
#define _PROGRAMSTATE_H_328984

class ProgramState {
public:

private:
    std::vector<QString> tags_;
    std::wstring open_path_{};

public:
    ProgramState(const ProgramState&) = delete;
    ProgramState& operator=(const ProgramState&) = delete;
    ProgramState(ProgramState&&) = delete;
    ProgramState& operator=(ProgramState&&) = delete;

    static ProgramState& instance() {
        static ProgramState instance;
        return instance;
    }

    std::vector<QString> get_tags() const;
    QString get_open_path() const;
    void set_open_path(QString path);
    void set_open_path(std::wstring path);

private:
    ProgramState();
};

#endif
