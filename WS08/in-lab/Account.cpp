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
#include "Account.h"

namespace sict 
{
    Account::Account(double balance)
    {
        if (balance > 0.0)
        {
            m_balance = balance;
        }
        else 
        {
            m_balance = 0.0;
        }
    }
    bool Account::credit(double balance)
    {
        bool valid;

        if (balance > 0.0)
        {
            m_balance += balance;
            valid = true;
        }
        else 
        {
            valid = false;
        }
        return valid;
    } 
    bool Account::debit(double balance)
    {
        bool valid;
        
        if (balance > 0.0)
        {
            m_balance -= balance;
            valid = true;
        }
        else 
        {
            valid = false;
        }
        return valid;
    }
    double Account::balance() const
    {
        return m_balance;
    }
   
}