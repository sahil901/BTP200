/*
Name: Sahil Patel
Seneca Student ID: 159-065-176
Seneca Email: spatel392@myseneca.ca
Date of completion: Summer 2019
Prof Name: Reid Kerr & Nargis Khan
Class Section: NAA
Decleration: I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/

#include "Fraction.h"
#include <iostream>

using namespace std;

namespace sict {
 
    Fraction::Fraction() {
      
        numerator = 0;
        denominator = 1;
    }
    
    Fraction::Fraction(int top, int bottom) {
        
        if (top <= 0 && bottom < 0) {
            *this = Fraction();
        }
        else {
            numerator = top;
            denominator = bottom;
            reduce();
        }
    }
    
    int Fraction::max() const {
        
        int max;

        if (numerator > denominator) {
            max = numerator;
        }
        else {
            max = denominator;
        }
        return max;
    }

    int Fraction::min() const {

        int min;

        if (numerator < denominator) {
            min = numerator;
        }
        else {
            min = denominator;
        }
        return min;
    }

    void Fraction::reduce() {

        int GCD = gcd();

        numerator /= GCD;
        denominator /= GCD;

    }
 
    int Fraction::gcd() const {
        int mn = min();  // min of numerator and denominator
        int mx = max();  // max of numerator and denominator
        int g_c_d = 1;
        bool found = false;

        for (int x = mn; !found && x > 0; --x) { // from mn decrement until divisor found
            if (mx % x == 0 && mn % x == 0) {
                found = true;
                g_c_d = x;
            }
        }
        return g_c_d;
    }

    bool Fraction::isEmpty() const {

        bool empty;

        if (numerator <= 0 && denominator > 0) {
            empty = true;
        }
        else {
            empty = false;
        }
        return empty;
    }

    void Fraction::display() const {
       
        if (isEmpty()) {
            cout << "no fraction stored";
        }
        else if (denominator == 1) {
            cout << numerator;
        }
        else {
            cout << numerator << "/" << denominator;
        }
    }

    Fraction Fraction::operator+(const Fraction& rhs) const {

        Fraction result;

        if (this->isEmpty() == false && rhs.isEmpty() == false) {
            result.numerator = (this->numerator * rhs.denominator) + (this->denominator * rhs.numerator); 
            result.denominator = (this->denominator * rhs.denominator);
        }
        else {
            result = Fraction();
        }
        return result;
    }
    
    Fraction Fraction::operator*(const Fraction& rhs) const {

        Fraction result;

        if (this->isEmpty() == false && rhs.isEmpty() == false) {
            result.numerator = this->numerator * rhs.numerator;
            result.denominator = this->denominator * rhs.denominator;
        }
        else {
            result = Fraction();
        }
        return result;
    }

    bool Fraction::operator==(const Fraction& rhs) const {

        bool check;

        if (this->isEmpty() == false && rhs.isEmpty() == false && this->numerator == rhs.numerator && this->denominator == rhs.denominator) {
            check = true;
        } else {
            check = false;
        }
        return check;
    }

    bool Fraction::operator!=(const Fraction& rhs) const {

        bool check;

        if (this->isEmpty() || rhs.isEmpty() || *this == rhs) {
            check = false;
        } else {
            check = true;
        }
        return check;
    }

    Fraction& Fraction::operator+=(const Fraction& rhs) {

        if (isEmpty() == false && rhs.isEmpty() == false) {
           *this = *this + rhs;
        } else {
            *this = Fraction();
        }
        reduce();
        return *this;
    }
}