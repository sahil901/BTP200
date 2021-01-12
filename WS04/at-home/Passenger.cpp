/*
Name: Sahil Patel
Seneca Student ID: 159-065-176
Seneca Email: spatel392@myseneca.ca
Date of completion: Summer 2019
Prof Name: Reid Kerr & Nargis Khan
Class Section: NAA
Decleration: I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/

#include "Passenger.h"
#include <iostream>
#include <cstring>

using namespace std;

namespace sict {

// Sets an object's data to an empty state.

Passenger::Passenger() {
        p_Name[0] = '\0';
        p_Dest[0] = '\0';
        m_year = 0;
        m_month = 0;
        m_day = 0;
}
/*
Constructor with 5 parameters checks if name, destination, and date of travel is valid, otherwise sets to default values
@Param: Name, Destination, Year, Month, and Day
@Return: A new object with values set or a new object with empty safe state values
*/
Passenger::Passenger(const char* name, const char* destination, int year, int month, int day) {

    bool yearCheck = year >= 2019 && year <= 2021; 
    bool monthCheck = month >= 1 && month <= 12;
    bool dayCheck = day >= 1 && day <= 31;


    if (name == nullptr || destination == nullptr || !yearCheck || !monthCheck || !dayCheck ) {
        p_Name[0] = '\0';
        p_Dest[0] = '\0';
        m_year = 0;
        m_month = 0;
        m_day = 0;
    }
    else {
        for (int i = 0; i < 18; i++) {
            p_Name[i] = name[i];
            p_Dest[i] = destination[i];
        }
            p_Name[18] = '\0';
            p_Dest[18] = '\0';

            m_year = year;
            m_month = month;
            m_day = day;
    }
}

// Sets the objects data and validates the data. If the data is invalid, the object is set to an empty state.

Passenger::Passenger(const char* p_name, const char* p_dest) {

if (p_name == nullptr || p_dest == nullptr) {
    p_Name[0] = '\0';
    p_Dest[0] = '\0';
}
    else {
        for (int i = 0; i < 18; i++){
            p_Name[i] = p_name[i];
            p_Dest[i] = p_dest[i];
        }
        p_Name[18] = '\0';
        p_Dest[18] = '\0';

        m_year = 2019;
        m_month = 10;
        m_day = 1;
    }
}

// Checks for empty state. An object is empty if it's an empty string that can be referenced

bool Passenger::isEmpty() const {
    bool safe;

    if (p_Name[0] == '\0' || p_Dest[0] == '\0') {
        safe = true;
    } else {
        safe = false;
    }
        return safe;
}

// Displays information of the object if it's not in an empty state, otherwise, displays default message of No Passenger

void Passenger::display() const {

    if (isEmpty() || m_year == 0 || m_month == 0 || m_day == 0) {
        cout << "No passenger!" << endl;
    }
        else {  
	          if (m_month > 0 && m_month < 10) {
            	    cout << p_Name << " - " << p_Dest << " on " << m_year << "/0" << m_month << "/" << m_day << endl;
               }
               else if (m_day > 0 && m_day < 10) {
                   	cout << p_Name << " - " << p_Dest << " on " << m_year << "/" << m_month << "/0" << m_day << endl;
               } 
	    else if (m_day < 10 && m_month < 10) {
            	cout << p_Name << " - " << p_Dest << " on " << m_year << "/0" << m_month << "/0" << m_day << endl;
	    }
        else {
            	cout << p_Name << " - " << p_Dest << " on " << m_year << "/" << m_month << "/" << m_day << endl;
        }
    }
}

/*
Query function that returns the passenger's name
@Return: Address of passenger's name
*/

const char* Passenger::name() const {
    return p_Name;
}
/*
Verification function that checks whether 2 passengers can travel with each other
@Param: Passenger reference
@Return: Result of check operation
*/

bool Passenger::canTravelWith(const Passenger& person) const {

    bool verifyTravel;
        if (strcmp(p_Dest, person.p_Dest) == 0) {
            if (this->m_year == person.m_year && this->m_month == person.m_month && this->m_day == person.m_day) {
                verifyTravel = true;
            } 
            else {
                verifyTravel = false;
                }  
    }
    else {
        verifyTravel = false;
    }
    return verifyTravel;
    }
}