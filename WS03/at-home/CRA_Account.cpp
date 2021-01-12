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
#include "CRA_Account.h"

using namespace std;

/*
    Function isEmpty returns whether an object is empty or not
    @Param: Nothing
*/
namespace sict {

bool CRA_Account::isEmpty() const {
    return !m_sin;
}

/* 
    Function set simply sets the values of the names and SIN number after validating them
    @Param: Family and Given name as char pointers and the SIN number as an int
*/

void CRA_Account::set(const char* familyName, const char* givenName, int sin) {

    int n_sin = sin;

    if (n_sin >= min_sin && n_sin <= max_sin && familyName[0] != '\0' && givenName[0] != '\0')
    {
        int sum = 0;

        for (int i = 0; i < 5; ++i) {
                int temp = n_sin % 100, even = temp / 10 * 2;
				sum += temp % 10 + even / 10 + even % 10;
                n_sin /= 100;
        }
        if (sum % 10 == 0) {

        strncpy(m_familyName, familyName, max_name_length);
        m_familyName[max_name_length + 1] = '\0';

        strncpy(m_givenName, givenName, max_name_length);
        m_givenName[max_name_length + 1] = '\0';       

        m_sin = sin;
    }
        for (int i = 0; i < max_yrs; ++i) {
            m_balance_owed[i] = 0;
            m_years = 0;
        }

    } else {
        m_sin = 0;
    }       
}
/*
    Function set simply sets the tax return year as well as balanced owed if it's valid
    @Param: Year as an int and the balance as a double
*/

void CRA_Account::set(int year, double balance) {
    if (!isEmpty() && m_years < max_yrs) {
        m_tax_return_year[m_years] = year;
        m_balance_owed[m_years] = balance;
        m_years++;
    }
}
/*
    Function display simply displays all data given, or a statement that it's empty if nothing is inside 
    @Param: Nothing
*/

void CRA_Account::display() const {
		if (!isEmpty()) {
			cout << "Family Name: " << m_familyName << endl;
			cout << "Given Name : " << m_givenName << endl;
			cout << "CRA Account: " << m_sin << endl;
            cout.setf(ios::fixed);
            cout.precision(2);
			for (int i = 0; i < m_years; ++i) {
				cout << "Year (" << m_tax_return_year[i] << ") ";
				if (m_balance_owed[i] > 2.00) {
					cout << "balance owing: " << m_balance_owed[i] << endl;
				}
				else if (m_balance_owed[i] < -2.00) {
					cout << "refund due: " << -m_balance_owed[i] << endl;
				}
				else {
					cout << "No balance owing or refund due!" << endl;
				}
			}
		}
		else {
			cout << "Account object is empty!" << endl;
		}
    }
}
