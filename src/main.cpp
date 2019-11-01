#include <iostream>

#include "ui/MainWindow.h"

int main(int argc, char *argv[]) {
    QApplication qApplication(argc, argv);
    MainWindow mainWindow;
    mainWindow.show();
    return qApplication.exec();
}
