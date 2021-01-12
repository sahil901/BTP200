/*
Name: Sahil Patel
Seneca Student ID: 159-065-176
Seneca Email: spatel392@myseneca.ca
Date of completion: Summer 2019
Prof Name: Reid Kerr & Nargis Khan
Class Section: NAA
Decleration: I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/

#ifndef AID_PERISHABLE_H
#define AID_PERISHABLE_H
#include <iostream>
#include "Good.h"
#include "Date.h"

namespace aid
{
    class Perishable : public Good
    {
        Date date_expiry;

        public:
            Perishable();
            std::fstream& store(std::fstream& file, bool newLine = true) const;
            std::fstream& load(std::fstream& file);
            std::ostream& write(std::ostream& os, bool linear) const;
            std::istream& read(std::istream& is);
            const Date& expiry() const;
    };
    iGood* CreateProduct(char tag);
}

#endif