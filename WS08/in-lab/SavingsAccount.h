/*
Name: Sahil Patel
Seneca Student ID: 159-065-176
Seneca Email: spatel392@myseneca.ca
Date of completion: Summer 2019
Prof Name: Reid Kerr & Nargis Khan
Class Section: NAA
Decleration: I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/

#ifndef _SICT_SAVINGSACCOUNT_H
#define _SICT_SAVINGSACCOUNT_H
#include "Account.h"
#include <iostream>

namespace sict
{
    class SavingsAccount : public Account
    {
        double m_Interest;
        
        public:
            SavingsAccount(double, double);
            void monthEnd();
            void display(std::ostream&) const;
    };
}

#endif