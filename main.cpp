#include <iostream>
#include "ComplexNumber.h"
int main() {
    ComplexNumber<int> c1(1, 2);
    ComplexNumber<double> c2(2.45, -1.86);
    std::cout << c2;
    std::cout << c1;
    ComplexNumber<double,double> c3;
    c1 = c1;
    c3 = c1+c2;

    std::cout <<c3;

    return 0;
}
