/*
Name: Sahil Patel
Seneca Student ID: 159-065-176
Seneca Email: spatel392@myseneca.ca
Date of completion: Summer 2019
Prof Name: Reid Kerr & Nargis Khan
Class Section: NAA
Decleration: I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/

#ifndef _sict_KINGDOM_H
#define _sict_KINGDOM_H

namespace sict {

struct Kingdom {
    char m_name[33];
    int m_population;    
};

    void display(const Kingdom& other);

}

#endif