#pragma once
#ifndef _PROGRAMSTATE_H_328984
#define _PROGRAMSTATE_H_328984

class ProgramState {
public:

private:
    std::set<QString> tags_;

public:
    ProgramState(const ProgramState&) = delete;
    ProgramState& operator=(const ProgramState&) = delete;
    ProgramState(ProgramState&&) = delete;
    ProgramState& operator=(ProgramState&&) = delete;

    static ProgramState& instance() {
        static ProgramState instance;
        return instance;
    }

private:
    ProgramState();
};

#endif
