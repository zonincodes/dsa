#include <iostream>
#include <string>


struct Distance
{
    private:
        explicit Distance(long double val) : kilometers(val){};

        friend Distance operator"" _km(long double val);
        friend Distance operator"" _mi(long double val);
        long double kilometers{0};
    
    public:
        const static long double km_per_mile;

        long double get_kilometers() { return kilometers;}

        Distance operator+(Distance other){
            return Distance(get_kilometers() + other.get_kilometers());
        }

};

const long double Distance::km_per_mile = 1.609344L;

Distance operator"" _km(long double val)
{
    return Distance(val);
}

Distance operator"" _mi(long double val)
{
    return Distance(val * Distance::km_per_mile);
}

int main(){
    //  Must have a decimal point to bind to the operator we defined!
    Distance d{ 402.0_km}; // construct using kilometers
    std::cout << "Kilometers in d: " << d.get_kilometers() << std::endl;

    Distance d2{ 402.0_mi}; //construct using miles

    std::cout << "Kilometers in d2: " << d2.get_kilometers() << std::endl;

    //  add distances with difents units
    Distance d3 = 36.0_mi + 42.0_km;
    std::cout << "d3 value = " << d3.get_kilometers() << std::endl;
    return 0;
}