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
#include "Date.h"
using namespace std;

namespace aid
{
	Date::Date()
	{
		m_year = 0;
		m_month = 0;
		m_DOM = 0;
		m_comparator = 0;
		m_error_state = NO_ERROR;
	}

	Date::Date(int year, int month, int day)
	{
		bool yearValid = (year >= min_year && year <= max_year);
		int daysInMonth = mdays(month, year);
		bool daysInMonthValid = day >= 1 && day <= daysInMonth;

		if (yearValid && daysInMonthValid)
		{
			m_year = year;
			m_month = month;
			m_DOM = day;
			m_error_state = NO_ERROR;
			m_comparator = year * 372 + month * 31 + day;
		}
		else
		{
			*this = Date();
		}
	}
	
	void Date::errCode(int errorCode)
	{
		m_error_state = errorCode;
	}

	int Date::errCode() const
	{
		return m_error_state;
	}

	bool Date::bad() const
	{
		return m_error_state == NO_ERROR;
	}

	bool Date::operator==(const Date& rhs) const
	{
	bool day = this->m_DOM == rhs.m_DOM;
		bool month = this->m_month == rhs.m_month;
		bool year = this->m_year == rhs.m_year;
		
		return (day && month && year);
	}

	bool Date::operator!=(const Date& rhs) const
	{
		return !(*this == rhs);
	}

	bool Date::operator<(const Date& rhs) const
	{
		bool yearCheck = this->m_year < rhs.m_year;
		bool monthCheck = this->m_month < rhs.m_month;
		bool dayCheck = this->m_DOM < rhs.m_DOM;

		if (yearCheck)
		{
			return true;
		}
		else if (monthCheck)
		{
			return true;
		}
		else if (dayCheck)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	bool Date::operator>(const Date& rhs) const
	{
		return !(*this < rhs);
	}

    bool Date::operator<=(const Date& rhs) const
	{
		return *this < rhs || *this == rhs;
	}

	bool Date::operator>=(const Date& rhs) const
	{
		return *this > rhs || *this == rhs;		
	}

	std::istream& Date::read(std::istream& istr)
	{
		char symbol;
		int year, month, day;
		istr.clear();
		istr >> year >> symbol >> month >> symbol >> day;
		
		*this = Date(year, month, day);

		if (istr.fail())
		{
			*this = Date();
			errCode(CIN_FAILED);
		}
		else if (year < min_year || year > max_year)
		{
			*this = Date();
			errCode(YEAR_ERROR);
		}
		else if (1 > month || month > 12)
		{
			*this = Date();
			errCode(MON_ERROR);
		}
		else if (day > mdays(month, year))
		{
			*this = Date();
			errCode(DAY_ERROR);
		}
        else if (m_comparator < min_date)
        {
            *this = Date();
            errCode(PAST_ERROR);
        }
	
		return istr;
	}

	std::ostream& Date::write(std::ostream& ostr) const
	{
		char symbol = '/';

		ostr << m_year << symbol;

		if (m_month < 10)
		{
			ostr << 0;
		}

		ostr << m_month << symbol;

		if (m_DOM < 10)
		{
			ostr << 0;
		}
		ostr << m_DOM;

		return ostr;
	}

	int Date::mdays(int mon, int year) const
	{
		int days[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31, -1};
		int month = mon >= 1 && mon <= 12 ? mon : 13;
		month--;
		return days[month] + int((month == 1) * ((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0));
	}

	std::istream& operator>>(std::istream& istr, Date& other)
	{
		other.read(istr);
        return istr;
    }

	std::ostream& operator<<(std::ostream& ostr, const Date& other)
	{
		other.write(ostr);
        return ostr;
    }
}