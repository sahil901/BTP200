/*
Name: Sahil Patel
Seneca Student ID: 159-065-176
Seneca Email: spatel392@myseneca.ca
Date of completion: Summer 2019
Prof Name: Reid Kerr & Nargis Khan
Class Section: NAA
Decleration: I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/

#ifndef _AID_GOOD_H
#define _AID_GOOD_H
#include <iostream>
#include <fstream>
#include "Error.h"
#include "iGood.h"

namespace aid 
{
    const int max_sku_length = 7;
    const int max_unit_length = 10;
    const int max_name_length = 75;
    const double tax_rate = 0.13;

    class Good : public iGood {
    
    // Private Variables
    char m_type; // Type of the Good
    char m_SKU[max_sku_length + 1]; // Good's SKU
    char m_Unit[max_unit_length + 1]; // Good's Unit
    char* m_name; // Good's Name
    int m_onHand; // What we have
    int m_needed; // What we need
    double m_unitPrice; // Price of Good Unit before applying any taxes
    bool m_taxStatus; // Can the good be taxed?
    Error m_errorState;

    protected:
        void name(const char*);
        const char* name() const;
        const char* sku() const;
        const char* unit() const;
        bool taxed() const;
        double itemPrice() const;
        double itemCost() const;
        void message(const char*);
        bool isClear() const;
        char type() const;

        public:
            Good(char type = 'N');
            Good(const char*, const char*, const char*, int = 0, bool = true, double = 0.0, int = 0);
            Good(const Good& good);
            Good& operator=(const Good& good);
            ~Good();
            std::fstream& store(std::fstream& file, bool newLine = true) const;
            std::fstream& load(std::fstream& file);
            std::ostream& write(std::ostream& os, bool linear) const;
            std::istream& read(std::istream& is);
            bool operator==(const char*) const;
            double total_cost() const; // Includes Taxes
            void quantity(int); // Increments onHand by number received 
            bool isEmpty() const;
            int qtyNeeded() const; // Returns m_needed
            int quantity() const; // Returns m_onHand
            bool operator>(const char*) const;
            bool operator>(const iGood&) const;
            int operator+=(int); // updates onHand 
    };
    // Helper Functions
    std::ostream& operator<<(std::ostream&, const iGood&);
    std::istream& operator>>(std::istream&, iGood&);
    double operator+=(double&, const iGood&);
}
#endif