#include "pch.h"
#include "mainwindow.h"
#include "programstate.h"

int main(int argc, char* argv[]) {
    auto& ps = ProgramState::instance();

    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}