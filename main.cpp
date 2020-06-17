#include <iostream>
#include "source/ComplexNumber.h"
#include <array>
int main() {
    ComplexNumber<int> c1(1, 2);
    ComplexNumber<double> c2(2.45, -1.86);
    ComplexNumber<double> c4(1.45, -1.56);
    std::cout << c2;
    std::cout << c1;
    ComplexNumber<double> c3;
    c1 = c1;
    c3 = c1+c2;

    std::cout <<c3;
    std::array<ComplexNumber<double>, 3> arr1 = {c2, c3, c4};
    ConstSizeVector<ComplexNumber<double>, 3> v1(arr1);


    std::cout << "The size of the vector is: " << v1.getSize() << std::endl;
    std::cout<< v1[1];
    // ConstSizeVector<ComplexNumber<double>, 6> v2 = concat(v1, v1);

    auto v2 = concat(v1, v1);
    std::array<int, 3> arr2 = {1, 2, 3};
    ConstSizeVector<int, 3> v3(arr2);
    auto v4 = concat(v3, v3);
    std::cout << v4[4]<< std::endl;

    for(size_t element = 0; element < 6; element++){
        std::cout<< v2[element];
    }
    return 0;
}
