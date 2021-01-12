/*
Name: Sahil Patel
Seneca Student ID: 159-065-176
Seneca Email: spatel392@myseneca.ca
Date of completion: Summer 2019
Prof Name: Reid Kerr & Nargis Khan
Class Section: NAA
Decleration: I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/

#include "Kingdom.h"
#include <iostream>
using namespace std;

namespace sict {

/*
    This function simply displays the data of the Kingdom object in the order mentioned in the workshop docx
    @param: Kingdom reference
*/
    void display(const Kingdom& other) {
        cout << other.m_name << ", population" << other.m_population << endl; 
    }
}