#include "doctest.h"
#include <stdexcept>
#include "Fraction.hpp"
using namespace ariel;

TEST_CASE("check that the constructor throw exception if the denominator is zero") {
    CHECK_THROWS(Fraction (1,0));
}

TEST_CASE("check the equal operator") {
    Fraction frt1(1,2);
    Fraction frt2(1,2);
    CHECK(frt1 == frt2);
    // check to float from right and left
    CHECK(frt1 == 0.5);
    CHECK(0.5 == frt1);
}

TEST_CASE("check the ctor that get float") {
    float check = 0.5;
    Fraction frt1(1,2);
    Fraction frt2(check);
    CHECK(frt1 == frt2);
    Fraction frt3(-1,2);
    check = -0.5;
    Fraction frt4(check);
    CHECK(frt3 == frt4);
}

TEST_CASE("check the append operator") {
    Fraction frt1(1,2);
    Fraction frt2(1,2);
    Fraction frt3(1,1);
    CHECK(frt1 + frt2 == frt3);
    CHECK(frt1 + 0.5 == frt3);
    CHECK(0.5 + frt1 == frt3);
    // check append with minus
    Fraction frt4(-1,2);
    Fraction frt5(0,1);
    CHECK(frt4 + frt2 == frt5);
}

TEST_CASE("check the sub operator") {
    Fraction frt1(1,2);
    Fraction frt2(1,2);
    Fraction frt3(0,1);
    CHECK(frt1 - frt2 == frt3);
    CHECK(frt1 - 0.5 == frt3);
    CHECK(0.5 - frt2 == frt3);
    // check sub with minus 
    Fraction frt4(-1,2);
    Fraction frt5(-1,1);
    CHECK(frt4 - frt2 == frt5);
}

TEST_CASE("check the multiply operator") {
    Fraction frt1(1,2);
    Fraction frt2(1,2);
    Fraction frt3(1,4);
    CHECK(frt1*frt2 == frt3);
    CHECK(frt1*0.5 == frt3);
    CHECK(0.5*frt2 == frt3);
    //check mul with minus
    Fraction frt4(-1,2);
    Fraction frt5(-1,4);
    CHECK(frt4*frt2 == frt5);
    CHECK(frt4*frt4 == frt3);
}

TEST_CASE("check the divide operator") {
    Fraction frt1(1,2);
    Fraction frt2(1,2);
    Fraction frt3(1,1);
    CHECK(frt1/frt2 == frt3);
    CHECK(frt1/0.5 == frt3);
    CHECK(0.5/frt2 == frt3);
    // check divide with minus    
    Fraction frt4(-1,2);
    Fraction frt5(-1,1);
    CHECK(frt4/frt2 == frt5);
    CHECK(frt4/frt4 == frt3);
    // check exception if try to divide by zero
    Fraction frt6(0,1);
    CHECK_THROWS(frt1/frt6);
}

TEST_CASE("check the ++ opertaor prefix and profix") {
    Fraction frt(1,2);
    frt++;
    Fraction frt2(3,2);
    Fraction frt3(5,2);
    CHECK(frt == frt2);
    CHECK(++frt == frt2);
    CHECK(frt == frt3);
}

TEST_CASE("check the -- opertaor prefix and profix") {
    Fraction frt(5,2);
    Fraction frt2(3,2);
    Fraction frt3(1,2);
    frt--;
    CHECK(frt == frt2);
    Fraction frt4 = --frt;
    CHECK(frt4 == frt2);
    CHECK(frt == frt3);
}

TEST_CASE("check the not equal operator") {
    Fraction frt1(3,2);
    Fraction frt2(1,2);
    CHECK(frt1 != frt2);
    CHECK(frt1 != 0.5);
    CHECK(0.5 != frt1);
}

TEST_CASE("check the bigger than operator") {
    Fraction frt1(3,2);
    Fraction frt2(1,2);
    CHECK(frt1 > frt2);
    CHECK(frt1 > 0.5);
    CHECK(2 > frt1);
}

TEST_CASE("check the bigger than and equal operator") {
    Fraction frt1(1,2);
    Fraction frt2(1,2);
    CHECK(frt1 >= frt2);
    Fraction frt3(3,2);
    CHECK(frt3 >= frt2);
    CHECK(frt1 >= 0.5);
    CHECK(frt1 >= 0.25);
    CHECK(0.5 >= frt1);
    CHECK(2 >= frt1);
}

TEST_CASE("check the less than operator") {
    Fraction frt1(3,2);
    Fraction frt2(1,2);
    CHECK(frt2 < frt1);
    CHECK(frt1 < 2);
    CHECK(0.25 < frt1);
}

TEST_CASE("check the less than and equal operator") {
    Fraction frt1(1,2);
    Fraction frt2(1,2);
    CHECK(frt1 <= frt2);
    Fraction frt3(-1,2);
    CHECK(frt3 <= frt2);
    CHECK(frt1 <= 0.5);
    CHECK(frt1 <= 1);
    CHECK(0.5 <= frt1);
    CHECK(0.25 <= frt1);
}

TEST_CASE("check getNumerator") {
    Fraction frt1(1,2);
    CHECK(frt1.getNumerator() == 1);
    Fraction frt2(-1,2);
    CHECK(frt2.getNumerator() == -1);
    Fraction frt3(1,-2);
    CHECK(frt3.getNumerator() == -1);
    Fraction frt4(0,-2);
    CHECK(frt4.getNumerator() == 0);
}

TEST_CASE("check getDenominator") {
    Fraction frt1(1,2);
    CHECK(frt1.getDenominator() == 2);
    Fraction frt2(1,-2);
    CHECK(frt2.getDenominator() == 2);
}

TEST_CASE("check gcd") {
    Fraction frt1(2,4);
    int gcd1 = frt1.gcd(frt1.getNumerator(), frt1.getDenominator());
    CHECK(gcd1 == 2);
    Fraction frt2(-2,4);
    int gcd2 = frt2.gcd(frt2.getNumerator(), frt2.getDenominator());
    CHECK(gcd2 == 2);
    Fraction frt3(0,4);
    int gcd3 = frt3.gcd(frt3.getNumerator(), frt3.getDenominator());
    CHECK(gcd3 == 1); // in the ctor, if numerator equal to zero then den equal to 1
}