#pragma once
#ifndef _TAG_H_908238
#define _TAG_H_908238

class Tag: public QPushButton {
    Q_OBJECT

private:
    bool selected_;

public:
    Tag(const QString& text, QWidget* parent = nullptr);

    void toggle();
    void reset();

private:
    void set_enabled();
    void set_disabled();
};

#endif
