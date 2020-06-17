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

template <typename T,  std::size_t _size>
class ConstSizeVector{
public:
        explicit ConstSizeVector(std::array<T, _size> vector = {});
        size_t getSize() const;

       T &operator[](size_t i);
       const T &operator[](size_t i)const;

private:
        std::array<T, _size> _vector;
    };

template<typename T, std::size_t _size>
ConstSizeVector<T, _size>::ConstSizeVector(std::array<T, _size> vector) :
_vector(vector)
{
    std::cout << "Constructor of ConstSizeVector used!" << std::endl;
}


template<typename T, std::size_t _size>
 size_t ConstSizeVector<T, _size>::getSize() const {
    return _size;
}



template<typename T, std::size_t _size>
T & ConstSizeVector<T, _size>::operator[](size_t i) {
        return _vector[i];
}
// const Function for concat function which needs two const vectors
template<typename T, std::size_t _size>
const T & ConstSizeVector<T, _size>::operator[](size_t i) const{
    return _vector[i];
}

// function which connects two vectors into a new one

template <typename T, size_t n, size_t m>
ConstSizeVector<T, n+m> concat(const ConstSizeVector<T, n> & v1, const ConstSizeVector<T, m> & v2){
    ConstSizeVector<T, n+m> newVector;
    for(size_t element1 = 0; element1 < n; element1++){
        newVector[element1]=v1[element1];
    }
    for(size_t element2 = 0; element2 < m; element2++){
        newVector[element2+n]=v2[element2];
    }
    return newVector;
}
#endif //TEMPLATES_COMPLEXNUMBER_H