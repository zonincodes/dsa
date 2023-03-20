#include <iostream>
#include "demo.h"
#include <string>
Jupiter::Jupiter(){
    name = nullptr;
}

Jupiter::Jupiter(char *x ){
    name = x;
}

char Jupiter::getName(){
    return *name;
}