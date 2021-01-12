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
#include "ChequingAccount.h"

namespace sict 
{
    const double rate = 0.05;
    const double transactionFee = 0.50;
    const double monthlyFee = 2.00;

    iAccount* CreateAccount(const char* type, double balance)
    {
        iAccount* account = nullptr;

        if (type[0] == 'S')
        {
            account = new SavingsAccount(balance, rate); 
        }
        else if (type[0] == 'C')
        {
            account = new ChequingAccount(balance, transactionFee, monthlyFee);
        }
        return account;
    }
}