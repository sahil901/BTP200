/*
Name: Sahil Patel
Seneca Student ID: 159-065-176
Seneca Email: spatel392@myseneca.ca
Date of completion: Summer 2019
Prof Name: Reid Kerr & Nargis Khan
Class Section: NAA
Decleration: I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/

#include <iostream>
#include <cstring>
#include "SavingsAccount.h"

namespace sict 
{
    const double rate = 0.05;

    iAccount* CreateAccount(const char* type, double balance)
    {
        iAccount* account = nullptr;

        if (type[0] == 'S')
        {
            account = new SavingsAccount(balance, rate); 
        }
        return account;
    }
}