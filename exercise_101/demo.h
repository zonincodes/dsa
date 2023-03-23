#ifndef DEMO_H
#define DEMO_H

#include <iostream>
#include <string>
using namespace std;
class Jupiter{
    public:
        Jupiter();
        Jupiter(char *x);

        string getName();
    private:
        char *name;
    
};

#endif