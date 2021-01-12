/*
Name: Sahil Patel
Seneca Student ID: 159-065-176
Seneca Email: spatel392@myseneca.ca
Date of completion: Summer 2019
Prof Name: Reid Kerr & Nargis Khan
Class Section: NAA
Decleration: I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/

#ifndef _AID_DATE_H
#define _AID_DATE_H

#include <iostream>

#define NO_ERROR 0
#define CIN_FAILED 1
#define DAY_ERROR 2
#define MON_ERROR 3
#define YEAR_ERROR 4
#define PAST_ERROR 5

namespace aid {

const int min_year = 2018;
const int max_year = 2038;
const int min_date = 751098;

class Date {

    int m_year;
    int m_month;
    int m_DOM;
    int m_comparator;
    int m_error_state;

    void errCode(int);
    int mdays(int, int) const;

    public:
        Date();
        Date(int, int, int);
        bool operator==(const Date& rhs) const;
        bool operator!=(const Date& rhs) const;
        bool operator<(const Date& rhs) const;
        bool operator>(const Date& rhs) const;
        bool operator<=(const Date& rhs) const;
        bool operator>=(const Date& rhs) const;
        int errCode() const;
        bool bad() const;
        std::istream& read(std::istream& istr);
        std::ostream& write(std::ostream& ostr) const;
};

std::istream& operator>>(std::istream& istr, Date& other);
std::ostream& operator<<(std::ostream& ostr, const Date& other);

}

#endif  