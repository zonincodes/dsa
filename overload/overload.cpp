#include <iostream>
#include <string>
#include <cstring>
using namespace std;

class Demo {

    public:
        Demo(const char *tt){
            title = new char[strlen(tt) + 1];
            strcpy(title, tt);
        }

        private:
            char *title;

            ostream &printDemo(ostream &) const;
            // friend ostream &operator<< (ostream &out, const Demo &dm){
            //     return dm.printDemo(out);
            // }
};

ostream &Demo::printDemo(ostream &out) const 
{
    out << " * " << title << endl;
    return out;
}

ostream &operator<< (ostream &out, const Demo &bk)
{
    out << bk;
    return out;
}

int main(){
    Demo dm("Jennifer");
    cout << dm;
    return 0;
}