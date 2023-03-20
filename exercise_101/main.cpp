#include "demo.h"
#include <iostream>

int main(){
    char *x = new char[100];
    std::cin.getline(x, 100);

    Jupiter p(x);

    std::cout << p.getName() << std::endl;
}