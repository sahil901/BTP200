/*
Name: Sahil Patel
Seneca Student ID: 159-065-176
Seneca Email: spatel392@myseneca.ca
Date of completion: Summer 2019
Prof Name: Reid Kerr & Nargis Khan
Class Section: NAA
Decleration: I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/

#ifndef _SICT_CONTACT_H
#define _SICT_CONTACT_H

namespace sict {

const int MAX_CHAR = 20;
const int areaCodeLength = 3;
const int numberLength = 7;
const int numberCode1Length = 3;
const int numberCode2Length = 4;

class Contact {

    char m_contact[MAX_CHAR + 1];
    long long* m_phoneNum;
    int maxPhoneNum;

    bool validatePhone(const long long phoneNum);

public:
    Contact();
    Contact(const char* name, const long long* phoneNum, const int maxPhone);
    ~Contact();
    bool isEmpty() const;
    void display() const;
    };

}

#endif