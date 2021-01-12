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
        m_name = nullptr;

        if (name != nullptr)        
        {
            int length = strlen(name);

            char* temp = new char[length + 1];
            for (int i = 0; i < length; i++)
            {
                temp[i] = name[i];
            }
                temp[length] = '\0';
                m_name = temp;
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
    char Good::type() const
    {
        return m_type;
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
    }

    Good::Good(const char* sku, const char* address, const char* unit, int onHand, bool taxable, double initPrice, int needed)
    {
        if (sku != nullptr && address != nullptr && unit != nullptr)
        {
            strncpy(m_SKU, sku, strlen(sku));
            m_SKU[strlen(sku)] = '\0';

            name(address);
            
            strncpy(m_Unit, unit, strlen(unit));
            m_Unit[strlen(unit)] = '\0';
        }
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
            m_onHand = good.m_onHand;
            m_needed = good.m_needed;
            m_unitPrice = good.m_unitPrice;
            m_taxStatus = good.m_taxStatus;
        
            name(good.m_name);

            strncpy(m_SKU, good.m_SKU, strlen(good.m_SKU));
            m_SKU[strlen(good.m_SKU)] = '\0';

            strncpy(m_Unit, good.m_Unit, strlen(good.m_Unit));
            m_Unit[strlen(good.m_Unit)] = '\0';
            
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

    bool Good::operator>(const iGood& good) const
    {
        return (strcmp(m_name, good.name()) > 0) ? true : false;
    }

    int Good::operator+=(int unitAdded)
    {
        return (unitAdded > 0) ? m_onHand + unitAdded : m_onHand;
    }

    double operator+=(double& added, const iGood& good)
    {
        return good.total_cost() + added;
    }

    std::ostream& operator<<(std::ostream& os, const iGood& good)
    {
        return good.write(os, true);
    }

    std::istream& operator>>(std::istream& is, iGood& good)
    {
        return good.read(is);
    }

    std::fstream& Good::store(std::fstream& file, bool newline) const
    {
        file << m_type << "," << m_SKU << "," << m_name << "," << m_Unit << "," << m_taxStatus << "," << m_unitPrice << "," << m_onHand << "," << m_needed;
        
        if (newline)
        {
            file << std::endl;
        }

        return file;
    }
    
    std::fstream& Good::load(std::fstream& file)
    {
        char sku_[max_sku_length];
		char name_[max_name_length];
		char unit_[max_unit_length];
		double price;
		int qty, needed;
		char tax;
		bool taxable;

		if (file.is_open())
		{
			file.getline(sku_, max_sku_length, ',');
			sku_[strlen(sku_)] = '\0';

			file.getline(name_, max_name_length, ',');
			name_[strlen(name_)] = '\0';

			file.getline(unit_, max_unit_length, ',');
			unit_[strlen(unit_)] = '\0';

			file >> tax;

			if (tax == '1')
				taxable = true;
			else if (tax == '0')
				taxable = false;

			file.ignore();

			file >> price;
			file.ignore();

			file >> qty;
			file.ignore();

			file >> needed;
			file.ignore();
			
			*this = Good(sku_, name_, unit_, qty, taxable, price, needed);
		}
        return file;
    }

    std::ostream& Good::write(std::ostream& os, bool linear) const
    {   
        if (!(isClear()))
        {
            os << m_errorState.message();
        }

        else if (!isEmpty() && isClear())
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
			os << " Sku: " << m_SKU << endl
			<< " Name (no spaces): " << m_name << endl
			<< " Price: " << m_unitPrice << endl;
			if (m_taxStatus)
			{
				os << " Price after tax: " << itemCost() << endl;
			}
            else 
            {
                os << " Price after tax : N/A" << endl;
            }
		
			os << " Quantity on Hand: " << m_onHand  << " " << m_Unit << endl
			<< " Quantity needed: " << m_needed;
		    }
        }
        return os;
    }

    std::istream& Good::read(std::istream& is)
    {
        char taxed;
		char * address = new char[max_name_length + 1];
		int qty, need;
		double _price;

		if (!is.fail())
		{
			cout << " Sku: ";
			is >> m_SKU;
			cin.ignore();

			cout << " Name (no spaces): ";
			is >> address;
			name(address);

			cout << " Unit: ";
			is >> m_Unit;

			cout << " Taxed? (y/n): ";
			is >> taxed;

			if (!is.fail())
			{
				m_errorState.clear();

				if (taxed)
				{
					bool y_valid = taxed == 'y' || taxed == 'Y';
					bool n_valid = taxed == 'n' || taxed == 'N';

					if (y_valid)
						m_taxStatus = true;

					if (n_valid)
						m_taxStatus = false;

					if (!(y_valid || n_valid))
					{
						is.setstate(std::ios::failbit);
						m_errorState.message("Only (Y)es or (N)o are acceptable");
						return is;
					}
				}
			}
			else
			{
				is.setstate(std::ios::failbit);
				m_errorState.message("Only (Y)es or (N)o are acceptable");
				return is;
			}

			cout << " Price: ";
			is >> _price;

			if (is.fail())
			{
				m_errorState.clear();
				is.setstate(ios::failbit);
				m_errorState.message("Invalid Price Entry"); 
				return is;
			}
			else
				m_unitPrice = _price;

			cout << " Quantity on hand: ";
			is >> qty;
			

			if (is.fail())
			{
				m_errorState.clear();
				m_errorState.message("Invalid Quantity Entry");
				is.setstate(ios::failbit);
				return is;
			}
			else
				m_onHand = qty;

			cout << " Quantity needed: ";
			is >> need;
			cin.ignore();

			if (is.fail())
			{
				m_errorState.clear();
				m_errorState.message("Invalid Quantity Needed Entry");
				is.setstate(ios::failbit);
				return is;
			}
			else
				m_needed = need;

			if (!is.fail())
			{
				m_errorState.clear();
			}
		}

		return is;
    }
}