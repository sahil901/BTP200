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
#include <string>
#include "Error.h"

using namespace std;

namespace aid 
{
      Error::Error(const char* errorMessage)
    {
        if (errorMessage == nullptr)
        {
            m_error = nullptr;
        }
        else
        {
            m_error = new char[strlen(errorMessage) + 1];
            strcpy(m_error, errorMessage);
        }
    }

    Error::~Error()
    {
        delete[] m_error;
        m_error = nullptr;
    }

    void Error::clear()
    {
        delete[] this->m_error;
        m_error = nullptr;
    }

    bool Error::isClear() const
    {
        return (m_error == nullptr || m_error[0] == '\0') ? true : false;
    }

    void Error::message(const char* str)
    {
        delete[] m_error;
        m_error = new char[strlen(str) + 1];
        strcpy(m_error, str);
    }

    const char* Error::message() const
    {
        return m_error;
    }

    std::ostream& operator<<(std::ostream& os, const Error& em)
    {
        if (!em.isClear())
        {
            os << em.message();
        }
        return os;
    }


}