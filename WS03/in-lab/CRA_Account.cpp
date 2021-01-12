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

void CRA_Account::set(const char* familyName, const char* givenName, int sin) {

    if (sin >= min_sin && sin <= max_sin)
    {
        strncpy(m_familyName, familyName, max_name_length);
        m_familyName[max_name_length + 1] = '\0';

        strncpy(m_givenName, givenName, max_name_length);
        m_givenName[max_name_length + 1] = '\0';

        m_sin = sin;

    } else {
        m_sin = 0;
    }       
}

void CRA_Account::display() const {
    if (!isEmpty())
    {   
        cout << "Family Name: " << m_familyName << endl;
        cout << "Given Name: " << m_givenName << endl;
        cout << "CRA Account: " << m_sin << endl;
    }
    else 
    {
        cout << "Account object is empty!" << endl;
    }
}


}