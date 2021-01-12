/*
Name: Sahil Patel
Seneca Student ID: 159-065-176
Seneca Email: spatel392@myseneca.ca
Date of completion: Summer 2019
Prof Name: Reid Kerr & Nargis Khan
Class Section: NAA
Decleration: I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/

#ifndef _SICT_PASSENGER_H
#define _SICT_PASSENGER_H

namespace sict {

class Passenger {

    char p_Name[19];
    char p_Dest[19];

public:
    Passenger();
    Passenger(const char* p_name, const char* p_dest);
    bool isEmpty() const;
    void display() const;
    };  
}

#endif