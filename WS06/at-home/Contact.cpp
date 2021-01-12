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
#include "Contact.h"

using namespace std;

namespace sict {

bool Contact::validatePhone(const long long phoneNum)
{
	string phoneNumString = to_string(phoneNum);
	bool invalid = phoneNum <= 0 || phoneNumString.length() < 11 || phoneNumString.length() > 12 || phoneNumString[phoneNumString.length() - 7] == '0' || phoneNumString[phoneNumString.length() - 10] == '0';
	return !invalid;
}

bool Contact::isEmpty() const
{
	return m_contact[0] == '\0';
}

Contact::Contact()
{
	m_contact[0] = '\0';
	maxPhoneNum = 0;
	m_phoneNum = nullptr;
}

Contact::Contact(const char *name, const long long *phoneNums, const int phoneNum)
{
	if (name != nullptr && name[0] != '\0' && strlen(name) != 0)
	{
		strcpy(m_contact, name);
	
			m_phoneNum = new long long[phoneNum];
			maxPhoneNum = 0;
			for (int i = 0; i < phoneNum; i++)
			{
				if (validatePhone(phoneNums[i]))
				{
					maxPhoneNum += 1;
					m_phoneNum[maxPhoneNum - 1] = phoneNums[i];
				}
				else
				{
					m_phoneNum[i] = 0;
				}
			}
	}
	else 
	{
		*this = Contact();
	}
}

void Contact::display() const
{
	string countryCode;
	string areaCode;
	string numberCode1;
	string numberCode2;
	string phoneNumString;
	int phoneNumStringLength;
	if (!isEmpty())
	{

		cout << m_contact << endl;
		for (int phone = 0; phone < maxPhoneNum; phone++)
		{
			phoneNumString = to_string(m_phoneNum[phone]);
			phoneNumStringLength = phoneNumString.length();
			countryCode = phoneNumString.substr(0, (phoneNumStringLength - (areaCodeLength + numberLength)));
			areaCode = phoneNumString.substr(phoneNumStringLength - (areaCodeLength + numberLength), areaCodeLength);
			numberCode1 = phoneNumString.substr(phoneNumStringLength - numberLength, numberCode1Length);
			numberCode2 = phoneNumString.substr(phoneNumStringLength - numberCode2Length, numberCode2Length);

			cout << "(+" + countryCode + ")" + " " + areaCode + " " + numberCode1 + "-" + numberCode2 << endl;
		}
	}
	else
	{
		cout << "Empty contact!" << endl;
	}
}

Contact::~Contact()
{
	if (m_phoneNum != nullptr)
	{
		delete[] m_phoneNum;
    	}
        m_phoneNum = nullptr;
    }

Contact::Contact(const Contact& other)
{
	m_phoneNum = nullptr;
	*this = other;
}

Contact& Contact::operator=(const Contact& other)
{
	if (this != &other)
	{
		strcpy(m_contact, other.m_contact);
		maxPhoneNum = other.maxPhoneNum;
		delete[] m_phoneNum;

		if (other.m_phoneNum != nullptr) 
		{
			m_phoneNum = new long long[maxPhoneNum];
				for (int i = 0; i < maxPhoneNum; i++)
					{
						m_phoneNum[i] = other.m_phoneNum[i];
					}
				}
			else 
			{
				m_phoneNum = nullptr;
			}
		}
		return *this;
	}
	
Contact& Contact::operator+=(long long phoneNum)
{
	
	bool valid = validatePhone(phoneNum);

	if (valid)
	{
		maxPhoneNum++;

		long long* newPhone = new long long[maxPhoneNum];

			for (int i = 0; i < maxPhoneNum - 1; ++i)
			{
				newPhone[i] = m_phoneNum[i];
			}
		newPhone[maxPhoneNum - 1] = phoneNum;
		delete[] m_phoneNum;
		m_phoneNum = newPhone;
	}
	return *this;
}

}
