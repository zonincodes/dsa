#ifndef DEMO_H
#define DEMO_H

#include <iostream>

class Jupiter{
    public:
        Jupiter();
        Jupiter(char *x);

        char getName();
    private:
        char *name;
    
};

#endif