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
#include "ChequingAccount.h"
#include "Account.h"

namespace sict 
{
    ChequingAccount::ChequingAccount(double balance, double transFee, double monthFee) : Account(balance)
    {
        if (transFee > 0.0)
        {
            m_trans = transFee;
        }
        else 
        {
            m_trans = 0.0;            
        }
        
        if (monthFee > 0.0)
        {
            m_monthFee = monthFee;
        }
        else
        {
            m_monthFee = 0.0;
        }
        
    }

    bool ChequingAccount::credit(double balance)
    {
        Account::debit(m_trans);
        
        return Account::credit(balance);
    }

    bool ChequingAccount::debit(double balance)
    {
        return Account::debit(balance + m_trans);
    }

    void ChequingAccount::monthEnd()
    {
         Account::debit(m_monthFee);
    }

    void ChequingAccount::display(std::ostream& os) const {
		os << "Account type: Chequing" << std::endl;
        os << "Balance: $" << std::fixed << std::setprecision(2) << balance() << std::endl;;
		os << "Per Transaction Fee: " << m_trans << std::endl;
		os << "Monthly Fee: " << m_monthFee << std::endl;
	}
}