/*
Name: Sahil Patel
Seneca Student ID: 159-065-176
Seneca Email: spatel392@myseneca.ca
Date of completion: Summer 2019
Prof Name: Reid Kerr & Nargis Khan
Class Section: NAA
Decleration: I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/

#ifndef _AID_ERROR_H
#define _AID_ERROR_H
#include <iostream>

namespace aid 

{

    class Error
    {
        char* m_error;

        public:
            explicit Error(const char* errorMessage = nullptr);
            ~Error();
            void clear();
            bool isClear() const;
            void message(const char* str);
            const char* message() const;
            Error(const Error& error) = delete;
            Error& operator=(const Error& error) = delete;
    };
    
    std::ostream& operator<<(std::ostream& os, const Error& error);

}

#endif