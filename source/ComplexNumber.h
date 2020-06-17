//
// Created by Gm7Na on 15.06.2020.
//

#ifndef TEMPLATES_COMPLEXNUMBER_H
#define TEMPLATES_COMPLEXNUMBER_H
# include <iostream>
#include <array>

template <typename T1, typename T2 = T1>
class ComplexNumber {
public:
    explicit ComplexNumber(const T1 & real_number_ = 0, const T2 & imag_number_ = 0);
    ComplexNumber<T1, T2> & operator=(const ComplexNumber & complexNumber_);
    ~ComplexNumber();
    T1 getReal() const;
    T2 getImag() const;
    void setReal(T1 real_number);
    void setImag(T2 imag_number);
private:
    T1 _real;
    T2 _imag;
};

template<typename T1, typename T2>
T1 ComplexNumber<T1, T2>::getReal() const {
    return _real;
}

template<typename T1, typename T2>
void ComplexNumber<T1, T2>::setReal(T1 real_number) {
    _real = real_number;
}

template<typename T1, typename T2>
void ComplexNumber<T1, T2>::setImag(T2 imag_number) {
    _imag = imag_number;
}

template<typename T1, typename T2>
T2 ComplexNumber<T1, T2>::getImag() const {
    return _imag;
}


template<typename T1, typename T2>
ComplexNumber<T1, T2>::~ComplexNumber() {
    std::cout << "Destructor!" << std::endl;
}

template<typename T1, typename T2>
ComplexNumber<T1, T2>::ComplexNumber(const T1 &real_number_, const T2 &imag_number_)
        : _real(real_number_), _imag(imag_number_)
{
    std::cout << "Constructor!" << std::endl;
}



template<typename T1, typename T2>
ComplexNumber<T1, T2> &ComplexNumber<T1, T2>::operator=(const ComplexNumber<T1, T2> & complexNumber_){
    _real = complexNumber_.getReal();
    _imag = complexNumber_.getImag();
    return *this;
};


template<typename T1, typename T2>
std::ostream & operator<<(std::ostream & out, ComplexNumber<T1, T2> const & complexNumber){

    out << "The complex number is: " << complexNumber.getReal() <<" + i * "
    << complexNumber.getImag()<< std::endl;
    return out;
}
template<typename T1, typename T2, typename T3, typename T4>
ComplexNumber<T3, T4> operator+(ComplexNumber<T1, T2> const & c1, ComplexNumber<T3,T4> const & c2){
    ComplexNumber<T3, T4> c3;
    c3.setImag(c1.getImag()+c2.getImag());
    c3.setReal(c1.getReal()+c2.getReal());
    return c3;
}

template <typename T1, typename T2, std::size_t _size>
class ConstSizeVector{
public:
        explicit ConstSizeVector(std::array<ComplexNumber<T1, T2>, _size> vector);
        size_t getSize() const;

        ComplexNumber<T1, T2> &operator[](size_t i);

private:
        std::array<ComplexNumber<T1, T2>, _size> _vector_complex;

    };




template<typename T1, typename T2, std::size_t size>
 size_t ConstSizeVector<T1, T2, size>::getSize() const {
    return size;
}

template<typename T1, typename T2, std::size_t _size>
ConstSizeVector<T1, T2, _size>::ConstSizeVector(std::array<ComplexNumber<T1, T2>, _size> vector) :
_vector_complex(vector) {
    std::cout << "Constructor of ConstSizeVector used!" << std::endl;
}

template<typename T1, typename T2, std::size_t _size>
ComplexNumber<T1, T2> & ConstSizeVector<T1, T2, _size>::operator[](size_t i) {
        return this[i];
}


#endif //TEMPLATES_COMPLEXNUMBER_H