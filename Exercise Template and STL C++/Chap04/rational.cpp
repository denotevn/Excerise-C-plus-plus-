// rational.cpp by Bill Weinman <http://bw.org/>
// updated 2018-09-24 for CppSTL 2018
#include "rational.h"

Rational::~Rational() {
    _n = 0; _d = 1;
}

Rational & Rational::operator = ( const Rational & rhs ) {
    if( this != &rhs ) {
        _n = rhs.numerator();
        _d = rhs.denominator();
    }
    return *this;
}

Rational Rational::operator + ( const Rational & rhs ) const {
    return Rational((_n * rhs._d) + (_d * rhs._n), _d * rhs._d);
}

Rational Rational::operator - ( const Rational & rhs ) const {
    return Rational((_n * rhs._d) - (_d * rhs._n), _d * rhs._d);
}

Rational Rational::operator * ( const Rational & rhs ) const {
    return Rational(_n * rhs._n, _d * rhs._d);
}

Rational Rational::operator / ( const Rational & rhs ) const {
    return Rational(_n * rhs._d, _d * rhs._n);
}

Rational & Rational::operator += ( const Rational & rhs ) {
    *this = Rational((_n * rhs._d) + (_d * rhs._n), _d * rhs._d);
    return *this;
}

Rational::operator std::string () const {
    if(_d == 1) return std::to_string(_n);
    else return std::to_string(_n) + "/" + std::to_string(_d);
}

Rational::operator double() const {
    return double(_n) / double(_d);
}

int Rational::operator < ( const Rational & rhs ) const {
    return double(*this) < double(rhs);
}

int Rational::operator > ( const Rational & rhs ) const {
    return double(*this) > double(rhs);
}

int Rational::operator <= ( const Rational & rhs ) const {
    return double(*this) <= double(rhs);
}

int Rational::operator >= ( const Rational & rhs ) const {
    return double(*this) >= double(rhs);
}

int Rational::operator == ( const Rational & rhs ) const {
    return double(*this) == double(rhs);
}
