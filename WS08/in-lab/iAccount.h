/*
Name: Sahil Patel
Seneca Student ID: 159-065-176
Seneca Email: spatel392@myseneca.ca
Date of completion: Summer 2019
Prof Name: Reid Kerr & Nargis Khan
Class Section: NAA
Decleration: I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/

#ifndef _SICT_IACCOUNT_H
#define _SICT_IACCOUNT_H

namespace sict 
{
    class iAccount
    {
        public:
            virtual ~iAccount(){};
            virtual bool credit(double) = 0;
            virtual bool debit(double) = 0;
            virtual void monthEnd() = 0;
            virtual void display(std::ostream&) const = 0;
    };
    iAccount* CreateAccount(const char*, double);
}

#endif