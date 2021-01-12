/*
Name: Sahil Patel
Seneca Student ID: 159-065-176
Seneca Email: spatel392@myseneca.ca
Date of completion: Summer 2019
Prof Name: Reid Kerr & Nargis Khan
Class Section: NAA
Decleration: I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/

#ifndef _SICT_ACCOUNT_H
#define _SICT_ACCOUNT_H
#include "iAccount.h"

namespace sict
{
    class Account : public iAccount
    {
        double m_balance;

        public:
            Account(double);
            bool credit(double);
            bool debit(double);
        protected:
            double balance() const;
    };
    iAccount* CreateAccount(const char*, double);
}

#endif