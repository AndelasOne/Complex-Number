//
// Created by Gm7Na on 17.06.2020.
//

#include "gtest/gtest.h"
#include "ComplexNumber.h"

TEST(ComplexNumber, read_write){
    std::array<int, 3> arr1 = {1, 2, 3};
    std::array<int, 3> arr2 = {4,5 ,6};
    ConstSizeVector<int, 3> v1(arr1);
    ConstSizeVector<int, 3> v2(arr2);
    auto v3 = concat(v1, v2);
    ASSERT_EQ(v1[1], 2);
    ASSERT_EQ(v3[2], 4) << "Size: "<< v3.getSize();
}