// rational.h by Bill Weinman <http://bw.org/>
// updated 2018-09-24 for CppSTL 2018
#ifndef _RATIONAL
#define _RATIONAL

#include <string>

class Rational {
    int _n = 0;
    int _d = 1;
public:
    Rational ( int numerator = 0, int denominator = 1 ) : _n(numerator), _d(denominator) {};
    Rational ( const Rational & rhs ) : _n(rhs._n), _d(rhs._d) {};    // copy constructor
    ~Rational ();
    inline int numerator() const { return _n; };
    inline int denominator() const { return _d; };
    Rational & operator = ( const Rational & );
    Rational operator + ( const Rational & ) const;
    Rational operator - ( const Rational & ) const;
    Rational operator * ( const Rational & ) const;
    Rational operator / ( const Rational & ) const;
    Rational & operator += ( const Rational & );
    operator std::string () const;
    operator double () const;
    int operator < ( const Rational & ) const;
    int operator > ( const Rational & ) const;
    int operator <= ( const Rational & ) const;
    int operator >= ( const Rational & ) const;
    int operator == ( const Rational & ) const;
};

#endif // _RATIONAL
