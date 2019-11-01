#include <iostream>

#include "geometry/shapes.hpp"
#include "ui/Main.h"

int main(int argc, char *argv[]) {
    int i = 10;
    i++;
    geometry::Point p;
    
    std::cout << "Hello World" << std::endl;
    
    QApplication a(argc, argv);
    Main w;
    w.show();
    return a.exec();
}
