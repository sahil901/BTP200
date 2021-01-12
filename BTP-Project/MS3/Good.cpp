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
#include <iomanip>
#include <fstream>
#include "Good.h"
#include "Error.h"

using namespace std;
namespace aid 
{
    void Good::name(const char* name)
    {
        if (name != nullptr)
        {
            int length = strlen(name);

            m_name = new char[length];
            for (int i = 0; i < length; i++)
            {
                m_name[i] = name[i];
            }
            m_name[length] = '\0';
        }
    }

    const char* Good::name() const
    {
        return m_name;
    }
    const char* Good::sku() const
    {
        return m_SKU;
    }

    const char* Good::unit() const
    {
        return m_Unit;
    }

    bool Good::taxed() const
    {
        return m_taxStatus;
    }

    double Good::itemPrice() const 
    {
        return m_unitPrice;
    }

    double Good::itemCost() const
    {
        double tax = tax_rate * m_unitPrice;
        return m_unitPrice + tax;
    }

    void Good::message(const char* message)
    {
        m_errorState.message(message);
    }

    bool Good::isClear() const
    {
        return (m_errorState.message() == nullptr) ? true : false;
    }

    Good::Good(char type)
    {
        m_type = type;
        m_Unit[0] = '\0';
        m_SKU[0] = '\0';
        m_name = nullptr;
        m_onHand = 0;
        m_needed = 0;
        m_unitPrice = 0.0;
        m_taxStatus = false;
        m_errorState.message(nullptr);
    }

    Good::Good(const char* sku, const char* address, const char* unit, int onHand, bool taxable, double initPrice, int needed)
    {
        name(address);
        strcpy(m_SKU, sku);
        strcpy(m_Unit, unit);
        m_onHand = onHand;
        m_taxStatus = taxable;
        m_unitPrice = initPrice;
        m_needed = needed;
    }

    Good& Good::operator=(const Good& good)
    {
        if (this != &good)
        {
            m_type = good.m_type;
            strcpy(m_SKU, good.m_SKU);
            strcpy(m_Unit, good.m_Unit);

            m_onHand = good.m_onHand;
            m_needed = good.m_needed;
            m_unitPrice = good.m_unitPrice;
            m_taxStatus = good.m_taxStatus;
            
            delete[] m_name;
            if (good.m_name != nullptr)
            {
                int length = strlen(good.m_name);

                m_name = new char[length];
                for (int i = 0; i < length; i++)
                {
                    m_name[i] = good.m_name[i];
                }
                m_name[length] = '\0';
            }
            else 
            {
                m_name = nullptr;
            }
        }
        return *this;
    }

    Good::Good(const Good& good)
    {
        m_name = nullptr;
        *this = good;    
    }

    Good::~Good()
    {
        delete[] m_name;
    }

    bool Good::operator==(const char* sku) const
    {
        return (this->m_SKU == sku) ? true : false;
    }

    double Good::total_cost() const
    {
        double taxed = m_unitPrice * tax_rate;
        double withTax = m_unitPrice + taxed;

        return static_cast<double>(m_onHand * withTax);
    }

    void Good::quantity(int quantity) 
    {
        if (quantity > 0)
        {
            m_onHand = quantity;
        }
    }

    bool Good::isEmpty() const
    {
        return (m_name == nullptr) ? true : false;
    }

    int Good::qtyNeeded() const
    {
        return m_needed;
    }

    int Good::quantity() const
    {
        return m_onHand;
    }

    bool Good::operator>(const char* sku) const
    {
        return (strcmp(m_SKU, sku) > 0) ? true : false;
    }

    bool Good::operator>(const Good& good) const
    {
        return (strcmp(m_name, good.m_name) > 0) ? true : false;
    }

    int Good::operator+=(int unitAdded)
    {
        return (unitAdded > 0) ? m_onHand + unitAdded : m_onHand;
    }

    double operator+=(double& added, const Good& good)
    {
        return good.total_cost() + added;
    }

    std::ostream& operator<<(std::ostream& os, const Good& good)
    {
        return good.write(os, true);
    }

    std::istream& operator>>(std::istream& is, Good& good)
    {
        return good.read(is);
    }

    std::fstream& Good::store(std::fstream& file, bool newline) const
    {
        file << m_type << "," << m_SKU << "," << m_Unit << "," << m_name << "," << m_onHand << "," << m_needed << "," << m_unitPrice;
        
        if (newline)
        {
            file << std::endl;
        }

        return file;
    }
    
    std::fstream& Good::load(std::fstream& file)
    {
        Good temp;

        temp.m_name = new char[max_name_length + 1];

        file >> temp.m_type >> temp.m_SKU >> temp.m_Unit >> temp.m_onHand >> temp.m_needed >> temp.m_unitPrice >> temp.m_taxStatus;

        if (temp.m_name[0] == '\0' || temp.m_name == nullptr)
        {
            *this = temp;
        }
        
        delete[] temp.m_name;
        temp.m_name = nullptr;
        return file;
    }

    std::ostream& Good::write(std::ostream& os, bool linear) const
    {
        if (linear)
		{

			os << setw(max_sku_length) << left << m_SKU << '|'
			<< setw(20) << left << m_name << '|'
			<< setw(7) << right << fixed << setprecision(2);
            m_taxStatus ? os << itemCost() : os << itemPrice(); 
            os << '|'
			<< setw(4) << right << m_onHand << '|'
			<< setw(10) << left << m_Unit << '|'
			<< setw(4) << right << m_needed << '|';
		}
		else
		{
			os << "Sku: " << m_SKU << "|" << endl
			<< "Name: " << m_name << "|" << endl
			<< "Price: " << m_unitPrice << "|" << endl;
			if (m_taxStatus)
			{
				os << "Price after tax: " << itemCost() << "|" << endl;
			}
			else
			{
				os << "N/A"
				<< "|" << endl;
			}

			os << "Quantity On hand: " << m_onHand << "|" << endl
			<< "Quantity needeed: " << m_needed << "|" << endl;
		}

        return os;
    }

    std::istream& Good::read(std::istream& is)
    {
        char sku[max_sku_length + 1];
        char unit[max_unit_length + 1];
        char* name = new char[max_name_length + 1];
        char input;
        int onHand;
        int needed;
        double beforeTax;
        bool taxed;
        Error error;
        
        std::cout << " Sku: ";
        is >> sku;

        std::cout << " Name (no spaces): ";
        is >> name;

        std::cout << " Unit: ";
        is >> unit;

        std::cout << " Taxed? (y/n): ";
        is >> input;
        if (input == 'Y' || input == 'y')
        {
            taxed = true;
        }
        else if (input == 'N' || input == 'n')
        {
            taxed = false;
        }
        else 
        {
            is.setstate(std::ios::failbit);
            error.message("Only (Y)es or (N)o are acceptable");
        }

        if (!is.fail())
        {
            std::cout << " Price: ";
            is >> beforeTax;
            if(is.fail())
                error.message("Invalid Price Entry");
        
        }

        if(!is.fail())
        {
            std::cout << " Quantity on hand: ";
            is >> onHand;
            if(is.fail())
                error.message("Invalid Quantity Entry");
        }

        if (!is.fail())
        {
            std::cout << " Quantity needed: ";
            is >> needed;
            if(is.fail())
                error.message("Invalid Quantity Needed Entry");
        }

        if(!is.fail())
        {
            Good temp = Good(sku, name, unit, onHand, taxed, beforeTax, needed);
            *this = temp;
        }
        delete[] name;
        name = nullptr;
        return is;
    }
}