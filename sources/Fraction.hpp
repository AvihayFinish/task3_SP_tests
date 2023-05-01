#pragma once
#include<iostream>

namespace ariel {

    class Fraction { 
    private:

        int num;
        int den;

    public:

        Fraction (int num, int den); // ctor
        Fraction (float num); // ctor

        // append
        Fraction operator+ (Fraction& app) const;
        Fraction operator+ (float app);
        friend Fraction operator+ (float app1, const Fraction& app2);

        // sub
        Fraction operator- (Fraction& sub) const;
        Fraction operator- (float sub);
        friend Fraction operator- (float sub1, const Fraction& sub2);

        // mul
        Fraction operator* (Fraction& mul) const;
        Fraction operator* (float mul);
        friend Fraction operator* (float mul1, const Fraction& mul2);

        // div
        Fraction operator/ (Fraction& div) const;
        Fraction operator/ (float div);
        friend Fraction operator/ (float div1, const Fraction& div2);

        // postfix and prefix
        Fraction& operator++ (int) {
            this->num += this->den;
            return *this;
        }
        Fraction operator++ () {
            Fraction copy(this->num, this->den);
            this->num += this->den;
            return copy; 
        }

        Fraction& operator-- (int){
            this->num -= this->den;
            return *this;
        }
        Fraction operator-- () {
            Fraction copy(this->num, this->den);
            this->num -= this->den;
            return copy;
        }

        // bool operators
        bool operator== (const Fraction& other) const;
        bool operator== (float other) const;
        friend bool operator== (float other1, const Fraction& other2);

        bool operator!= (const Fraction& other) const;
        bool operator!= (float other) const;
        friend bool operator!= (float other1, const Fraction& other2);

        bool operator>= (const Fraction& other) const;
        bool operator>= (float other) const;
        friend bool operator>= (float other1, const Fraction& other2);

        bool operator<= (const Fraction& other) const;
        bool operator<= (float other) const;
        friend bool operator<= (float other1, const Fraction& other2);

        bool operator< (const Fraction& other) const;
        bool operator< (float other) const;
        friend bool operator< (float other1, const Fraction& other2);

        bool operator> (const Fraction& other) const;
        bool operator> (float other) const;
        friend bool operator> (float other1, const Fraction& other2);
        
        friend std::ostream& operator<< (std::ostream& output, const Fraction& frt);
        std::istream& operator>> (std::istream& input);

        // another functions
        int gcd (int one, int two) const;
        int getNumerator () const {
            return this->num;
        }
        int getDenominator () const {
            return this->den;
        }
        Fraction floatToFrac (float num) const;
    };

    

}



