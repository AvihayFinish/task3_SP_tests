#include "Fraction.hpp"
#include <cstdlib>
using namespace ariel;
using namespace std;

// constructors
Fraction::Fraction (int num, int den) {
    if (den == 0) {
        throw runtime_error("the denominator cannot be zero");
    }
    if (num < 0 && den < 0) {
        num = abs(num);
        den = abs(den);
    }
    else if (den < 0 && num > 0) {
        den = abs(den);
        num = -num;
    }
    if (num == 0) {
        den = 1;
    }
    this->num = num;
    this->den = den;
}

Fraction::Fraction (float num) {
    int numFl = 1000 * num; // for acurrate of 3 numbers after the point
    int denFl = 1000;
    int gcdFl = gcd(numFl, denFl);
    Fraction frt((numFl / gcdFl), (denFl / gcdFl));
    this->num = frt.getNumerator();
    this->den = frt.getDenominator();
}

Fraction Fraction::floatToFrac (float num) const {
    int numFl = 1000 * num; // for acurrate of 3 numbers after the point
    int denFl = 1000;
    int gcdFl = gcd(numFl, denFl);
    return Fraction((numFl / gcdFl), (denFl / gcdFl));
}

// append operators
Fraction Fraction::operator+ (Fraction& app) const {
    int num1 = (this->getNumerator() * app.getDenominator()) + (app.getNumerator() * this->getDenominator());
    int den1 = this->getDenominator() * app.getDenominator();
    int gcd1 = gcd(num1, den1);
    return Fraction((num1 / gcd1), (den1 / gcd1));
}

Fraction Fraction::operator+ (float app) {
    Fraction floatFra = Fraction(app);
    int num1 = (this->getNumerator() * floatFra.getDenominator()) + (floatFra.getNumerator() * this->getDenominator());
    int den1 = this->getDenominator() * floatFra.getDenominator();
    int gcd1 = gcd(num1, den1);
    return Fraction((num1 / gcd1), (den1 / gcd1));
}

Fraction ariel::operator+ (float app1, const Fraction& app2) {
    Fraction floatFra = Fraction(app1);
    int num1 = (app2.getNumerator() * floatFra.getDenominator()) + (floatFra.getNumerator() * app2.getDenominator());
    int den1 = app2.getDenominator() * floatFra.getDenominator();
    int gcd1 = app2.gcd(num1, den1);
    return Fraction((num1 / gcd1), (den1 / gcd1));
} 

// sub operators
Fraction Fraction::operator- (Fraction& sub) const {
    int num1 = (this->getNumerator() * sub.getDenominator()) - (sub.getNumerator() * this->getDenominator());
    int den1 = this->getDenominator() * sub.getDenominator();
    int gcd1 = gcd(num1, den1);
    return Fraction((num1 / gcd1), (den1 / gcd1));
}

Fraction Fraction::operator- (float sub) {
    Fraction floatFra = Fraction(sub);
    int num1 = (this->getNumerator() * floatFra.getDenominator()) - (floatFra.getNumerator() * this->getDenominator());
    int den1 = this->getDenominator() * floatFra.getDenominator();
    int gcd1 = gcd(num1, den1);
    return Fraction((num1 / gcd1), (den1 / gcd1));
}

Fraction ariel::operator- (float sub1, const Fraction& sub2) {
    Fraction floatFra = Fraction(sub1);
    int num1 = (sub2.getNumerator() * floatFra.getDenominator()) - (floatFra.getNumerator() * sub2.getDenominator());
    int den1 = sub2.getDenominator() * floatFra.getDenominator();
    int gcd1 = sub2.gcd(num1, den1);
    return Fraction((num1 / gcd1), (den1 / gcd1));
}

// multiply operators
Fraction Fraction::operator* (Fraction& mul) const {
    int num1 = this->getNumerator() * mul.getNumerator();
    int den1 = this->getDenominator() * mul.getDenominator();
    int gcd1 = gcd(num1, den1);
    return Fraction((num1 / gcd1), (den1 / gcd1));
}

Fraction Fraction::operator* (float mul) {
    Fraction floatFra = Fraction(mul);
    int num1 = this->getNumerator() * floatFra.getNumerator();
    int den1 = this->getDenominator() * floatFra.getDenominator();
    int gcd1 = gcd(num1, den1);
    return Fraction((num1 / gcd1), (den1 / gcd1));
}

Fraction ariel::operator* (float mul1, const Fraction& mul2) {
    Fraction floatFra = Fraction(mul1);
    int num1 = mul2.getNumerator() * floatFra.getNumerator();
    int den1 = mul2.getDenominator() * floatFra.getDenominator();
    int gcd1 = mul2.gcd(num1, den1);
    return Fraction((num1 / gcd1), (den1 / gcd1));
}   

// divide operators
Fraction Fraction::operator/ (Fraction& div) const {
    int num1 = this->getNumerator() * div.getDenominator();
    int den1 = this->getDenominator() * div.getNumerator();
    int gcd1 = gcd(num1, den1);
    return Fraction((num1 / gcd1), (den1 / gcd1));
}

Fraction Fraction::operator/ (float div) {
    Fraction floatFra = Fraction(div);
    int num1 = this->getNumerator() * floatFra.getDenominator();
    int den1 = this->getDenominator() * floatFra.getNumerator();
    int gcd1 = gcd(num1, den1);
    return Fraction((num1 / gcd1), (den1 / gcd1));
}

Fraction ariel::operator/ (float div1, const Fraction& div2) {
    Fraction floatFra = Fraction(div1);
    int num1 = div2.getNumerator() * floatFra.getDenominator();
    int den1 = div2.getDenominator() * floatFra.getNumerator();
    int gcd1 = div2.gcd(num1, den1);
    return Fraction((num1 / gcd1), (den1 / gcd1));
}

// boolian operators
bool Fraction::operator== (const Fraction& other) const {
    int gcdThis = gcd(this->getNumerator(), this->getDenominator());
    Fraction temp1((this->getNumerator() / gcdThis), (this->getDenominator() / gcdThis));
    int gcdOther = gcd(other.getNumerator(), other.getDenominator());
    Fraction temp2((other.getNumerator() / gcdOther), (other.getDenominator() / gcdOther));
    if (temp1.getNumerator() == temp2.getNumerator() && temp1.getDenominator() == temp2.getDenominator()) {
        return true;
    }
    return false;
}

bool Fraction::operator== (float other) const {
    int gcdThis = gcd(this->getNumerator(), this->getDenominator());
    Fraction temp1((this->getNumerator() / gcdThis), (this->getDenominator() / gcdThis));
    Fraction floatFra = Fraction(other);
    if (temp1.getNumerator() == floatFra.getNumerator() && temp1.getDenominator() == floatFra.getDenominator()) {
        return true;
    }
    return false;
}

bool ariel::operator== (float other, const Fraction& fra) {
    Fraction floatFra = Fraction(other);
    int gcdThis = fra.gcd(fra.getNumerator(), fra.getDenominator());
    Fraction temp1((fra.getNumerator() / gcdThis), (fra.getDenominator() / gcdThis));
    if (temp1.getNumerator() == floatFra.getNumerator() && temp1.getDenominator() == floatFra.getDenominator()) {
        return true;
    }
    return false;
}

bool Fraction::operator!= (const Fraction& other) const {
    int gcdThis = gcd(this->getNumerator(), this->getDenominator());
    Fraction temp1((this->getNumerator() / gcdThis), (this->getDenominator() / gcdThis));
    int gcdOther = gcd(other.getNumerator(), other.getDenominator());
    Fraction temp2((other.getNumerator() / gcdOther), (other.getDenominator() / gcdOther));
    if (temp1.getNumerator() != temp2.getNumerator() || temp1.getDenominator() != temp2.getDenominator()) {
        return true;
    }
    return false;
}

bool Fraction::operator!= (float other) const {
    int gcdThis = gcd(this->getNumerator(), this->getDenominator());
    Fraction temp1((this->getNumerator() / gcdThis), (this->getDenominator() / gcdThis));
    Fraction floatFra = Fraction(other);
    if (temp1.getNumerator() != floatFra.getNumerator() || temp1.getDenominator() != floatFra.getDenominator()) {
        return true;
    }
    return false;
}

bool ariel::operator!= (float other, const Fraction& fra) {
    int gcdThis = fra.gcd(fra.getNumerator(), fra.getDenominator());
    Fraction temp1((fra.getNumerator() / gcdThis), (fra.getDenominator() / gcdThis));
    Fraction floatFra = Fraction(other);
    if (temp1.getNumerator() != floatFra.getNumerator() || temp1.getDenominator() != floatFra.getDenominator()) {
        return true;
    }
    return false;
}

bool Fraction::operator>= (const Fraction& other) const {
    int commonDen = this->getDenominator() * other.getDenominator(); // create a common denominator
    Fraction temp1((this->getNumerator() * other.getDenominator()), commonDen);
    Fraction temp2((this->getNumerator() * other.getDenominator()), commonDen);
    return temp1.getDenominator() >= temp2.getDenominator(); // 
}

bool Fraction::operator>= (float other) const {
    int numOfFloat = other * 1000; // for acuurate of three numbers after the point
    int denOfFloat = 1000;
    Fraction temp1(numOfFloat, denOfFloat);
    Fraction temp2(this->getNumerator(), this->getDenominator());
    return temp2 >= temp1; // use the >= of fractios that I create before
}

bool ariel::operator>= (float other, const Fraction& fra) {
    return true;
}

bool Fraction::operator<= (const Fraction& other) const {
    int commonDen = this->getDenominator() * other.getDenominator();
    float fraThis = (this->getNumerator() * other.getDenominator()) / commonDen;
    float fraOther = (other.getNumerator() * this->getDenominator()) / commonDen;
    return fraThis <= fraOther;
}

bool Fraction::operator<= (float other) const {
    return true;
}

bool ariel::operator<= (float other, const Fraction& fra) {
    return true;
}

bool Fraction::operator< (const Fraction& other) const {
    int commonDen = this->getDenominator() * other.getDenominator();
    float fraThis = (this->getNumerator() * other.getDenominator()) / commonDen;
    float fraOther = (other.getNumerator() * this->getDenominator()) / commonDen;
    return fraThis < fraOther;
}

bool Fraction::operator< (float other) const {
    return true;
}

bool ariel::operator< (float other, const Fraction& fra) {
    return true;
}

bool Fraction::operator> (const Fraction& other) const {
    int commonDen = this->getDenominator() * other.getDenominator();
    float fraThis = (this->getNumerator() * other.getDenominator()) / commonDen;
    float fraOther = (other.getNumerator() * this->getDenominator()) / commonDen;
    return fraThis > fraOther;
}

bool Fraction::operator> (float other) const {
    return true;
}

bool ariel::operator> (float other, const Fraction& fra) {
    return true;
}

// stout and stdin operators
std::istream& Fraction::operator>> (std::istream& input) {
    return input;
}

std::ostream& ariel::operator<< (std::ostream& output, const Fraction& frt) {
return (output << frt.getNumerator() << "/" << frt.getDenominator());
}

// gcd function by euclidean algorithm
int Fraction::gcd (int one, int two) const {
    one = abs(one);
    two = abs(two);
    if (one < two) {
        int temp = one;
        one = two;
        two = temp;
    }
    if (two == 0) {
        return one;
    }
    else {
        return gcd(two, one % two);
    }
}