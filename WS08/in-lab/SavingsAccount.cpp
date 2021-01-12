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
#include <iomanip>
#include "Account.h"
#include "SavingsAccount.h"

namespace sict
{
    SavingsAccount::SavingsAccount(double balance, double interest) : Account (balance)
    {
        if (interest > 0)
        {
            m_Interest = interest;
        }
        else
        {
            m_Interest = 0.0;
        }
        
    }
    void SavingsAccount::monthEnd() 
    {
        double monthEnd = balance() * m_Interest;
        credit(monthEnd);
    }
    void SavingsAccount::display(std::ostream& os) const
    {
        os << "Account type: Savings" << std::endl;
        os << "Balance: $" << std::fixed << std::setprecision(2) << balance() << std::endl;;
        os << "Interest Rate (%): " << std::fixed << std::setprecision(2) << m_Interest * 100 << std::endl;
    }
    
}