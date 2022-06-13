// rational.cpp by Bill Weinman <http://bw.org/>
// updated 2020-07-21
#include <iostream>
#include <string>

class Rational {
    int n = 0;
    int d = 1;
public:
    Rational ( int numerator = 0, int denominator = 1 ) : n(numerator), d(denominator) {};
    Rational ( const Rational & rhs ) : n(rhs.n), d(rhs.d) {};    // copy constructor
    ~Rational ();
    int numerator() const { return n; };
    int denominator() const { return d; };
    Rational & operator = ( const Rational & );
    Rational reduce() const;            // reduce fraction
    std::string string() const;         // return a formatted STL string
    std::string raw_string() const;     // return a non-reduced STL string
    Rational operator + ( const Rational & ) const;
    Rational operator - ( const Rational & ) const;
    Rational operator * ( const Rational & ) const;
    Rational operator / ( const Rational & ) const;
};

Rational & Rational::operator = ( const Rational & rhs ) {
    if( this != &rhs ) {
        n = rhs.numerator();
        d = rhs.denominator();
    }
    return *this;
}

Rational Rational::reduce() const {
    if(n == 0 || d <= 3) return *this;
    for(int div = d - 1; div; --div) {
        if(n % div == 0 && d % div == 0) {
            return Rational(n / div, d / div );
        }
    }
    return *this;
}

std::string Rational::string() const {
    if(d == 0) return "[NAN]";
    if(d == 1 || n == 0) return std::to_string(n);

    int abs_n = abs(n);     // absolute value
    if(abs_n > d) {
        int whole = n / d;
        int remainder = abs_n % d;
        if(remainder) return std::to_string(whole) + " " + Rational(remainder, d).string();
        else return std::to_string(whole);
    }
    else {
        return reduce().raw_string();
    }
}

std::string Rational::raw_string() const {
    return std::to_string(n) + "/" + std::to_string(d);
}

Rational Rational::operator + ( const Rational & rhs ) const {
    return Rational((n * rhs.d) + (d * rhs.n), d * rhs.d);
}

Rational Rational::operator - ( const Rational & rhs ) const {
    return Rational((n * rhs.d) - (d * rhs.n), d * rhs.d);
}

Rational Rational::operator * ( const Rational & rhs ) const {
    return Rational(n * rhs.n, d * rhs.d);
}

Rational Rational::operator / ( const Rational & rhs ) const {
    return Rational(n * rhs.d, d * rhs.n);
}

Rational::~Rational() {
    n = 0; d = 1;
}

// useful for std::cout
std::ostream & operator << (std::ostream & o, const Rational & r) {
    return o << r.raw_string();
}

int main() {
    
    Rational a = 7;        // 7/1
    std::cout << "a is: " << a << std::endl;

    Rational b(25, 15);    // 5/3
    std::cout << "b is: " << b << std::endl;

    Rational c = b;        // copy constructor
    std::cout << "c is: " << c << std::endl;

    Rational d;            // default constructor
    std::cout << "d is: " << d << std::endl;

    d = c;                // assignment operator
    std::cout << "d is: " << d << std::endl;

    Rational & e = d;     // reference
    d = e;                // assignment to self!
    std::cout << "e is: " << e << std::endl;

    std::cout << std::endl;
    std::cout << "d is " << d.string() << std::endl;

    std::cout << std::endl;
    std::cout << a << " + " << b << " = " << a + b << std::endl;
    std::cout << a << " - " << b << " = " << a - b << std::endl;
    std::cout << a << " * " << b << " = " << a * b << std::endl;
    std::cout << a << " / " << b << " = " << a / b << std::endl;

    return 0;
}
