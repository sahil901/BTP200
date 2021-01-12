/*
Name: Sahil Patel
Seneca Student ID: 159-065-176
Seneca Email: spatel392@myseneca.ca
Date of completion: Summer 2019
Prof Name: Reid Kerr & Nargis Khan
Class Section: NAA
Decleration: I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/

#ifndef _SICT_DATA_H
#define _SICT_DATA_H

#include <iostream>
#include <cstring>

namespace sict {
	// These numbers define 
	// a) the range of data we expect to see in this workshop
	//    0 to 1 billion
	//    use them in the min and max function
	// b) the output column width for a single data field

	const int LARGEST_NUMBER  = 1000000000; // 1,000,000,000
	const int SMALLEST_NUMBER = 0;          
	const int COLUMN_WIDTH    = 15;

	// max returns the largest item in data
	//
	template <typename T>
	T max(const T* data, int n)
	{
		T max = SMALLEST_NUMBER;
		for (int i = 0; i < n; i++)
		{
			if (data[i] > max)
			{
				max = data[i];
			}
		}
		return max;
	}

	// min returns the smallest item in data
	//

	template <typename T>
	T min(const T* data, int n)
	{
		T min = LARGEST_NUMBER;
		for (int i = 0; i < n; i++)
		{
			if (data[i] < min)
			{
				min = data[i];
			}
		}
		return min;
	}

        
	// sum returns the sum of n items in data
	//    
   
	template <typename T>
	T sum(const T* data, int n)
	{
		T sum = 0;

		for (int i = 0 ; i < n; i++)
		{
			sum += data[i];
		}
		return sum;
	}

	// average returns the average of n items in data
	//

	template <typename T>
	double average(const T* data, int n)
	{
		double average, sum2 = sum(data, n);
		average = sum2 / n;
		return average;
	}

	// read extracts n items from input and stores them in data
	// - the items are comma separated
	// - this function assumes that a comma exists at the next field to be read
	// - for example: ,data1, data2,data3, ...., datan
	//

	template<typename T>
	bool read(std::istream& input, T* data, int n)
	{
		for (int i = 0; i < n; i++)
		{
			input.ignore();
			input >> data[i];
		}
		if (!input.fail())
		{
			return true;
		}
		return false;
	}

	// display inserts n items of data into std::cout
	//

	template<typename T>
	void display(const char* name, const T* data, int n)
	{
		std::cout.width(COLUMN_WIDTH + 5);
		std::cout << std::right << name;

		for (int i = 0; i < n; i++)
		{
			std::cout.width(COLUMN_WIDTH);
			std::cout << data[i];
		}
		std::cout << std::endl;
	}

	template<typename T>
	bool readRow(std::istream& input, const char* name, T* data, int n)
	{
		char rowname[2000];
		bool ok = !input.bad();

		// row format is 
		// name,1,2,3,4,5,6

		if (ok) {
			// read the name  first

			input.get(rowname, 2000, ',');
			// note: get will read a string upto the , character
			// it will leave the , character in the input buffer 

			// check that the caller is reading the correct row (name)
			// - if the user is reading the wrong row, return an error
			if (std::strcmp(rowname, name) != 0) {
				// wrong row
				std::cout << "Cannot parse row for " << name << std::endl;
				input.ignore(2000, '\n');
				ok = false;
			}
		}

		if (ok)
			// read the data array
			ok = read(input, data, n);

		// finish the line
		input.ignore(2000, '\n');
		return ok;
	}
	void answers(const int*, const int*, const int*, const double*, const int*, const int n);
}

#endif