#include "demo.h"
Jupiter::Jupiter(){
    name = nullptr;
}

Jupiter::Jupiter(char *x ){
    name = x;
}

string Jupiter::getName(){
    return name;
}