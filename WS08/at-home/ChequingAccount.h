/*
Name: Sahil Patel
Seneca Student ID: 159-065-176
Seneca Email: spatel392@myseneca.ca
Date of completion: Summer 2019
Prof Name: Reid Kerr & Nargis Khan
Class Section: NAA
Decleration: I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/


#ifndef SICT_CHEQUINGACCOUNT_H
#define SICT_CHEQUINGACCOUNT_H
#include <iostream>
#include "Account.h"

namespace sict 
{
    class ChequingAccount : public Account
    {
        double m_trans;
        double m_monthFee;

        public:
            ChequingAccount(double, double, double);
            bool credit(double);
            bool debit(double);
            void monthEnd();
            void display(std::ostream&) const;
    };

}


#endif