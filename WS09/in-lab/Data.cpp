/*
Name: Sahil Patel
Seneca Student ID: 159-065-176
Seneca Email: spatel392@myseneca.ca
Date of completion: Summer 2019
Prof Name: Reid Kerr & Nargis Khan
Class Section: NAA
Decleration: I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/

#include <iomanip>
#include "Data.h"

namespace sict {
	
	void answers(const int* year, const int* population, const int* violentCrime,
		const double* violentCrimeRate, const int* grandTheftAuto, const int n) {
	

		// Q1: print the population change in millions of people
		// - print answer correct to 2 decimal places.
		// e..g "6.31 million";
		// note that population is an integer, so dividing by 1000000 would yield "6"

		int popGrowth = population[n-1] - population[0];
		std::cout.precision(2) << std::cout.setf(std::ios::fixed);
		std::cout << "Population change from " << year[0] << " to " << year[n-1] << " is " 
		<< static_cast<double>(popGrowth) / 1000000 << " million" << std::endl;
		// Q2. print whether violent crime rate has gone up or down between 2000 and 2005

		std::cout << "Violent Crime trend is ";

		if (violentCrimeRate[n-1] < violentCrimeRate[0])
		{
			std::cout << "down" << std::endl;
		}
		else 
		{
			std::cout << "up" << std::endl;
		}


		// Q3 print the GTA number accurate to 0 decimal places

		std::cout << "There are " << average(grandTheftAuto, n) / 1000000 << " million Grand Theft Auto incidents on average a year" << std::endl;

		// Q4. Print the min and max violentCrime rates

		std::cout << "The Minimum Violent Crime rate was " << static_cast<int>(min(violentCrimeRate, n)) << std::endl;
		std::cout << "The Maximum Violent Crime rate was " << static_cast<int>(max(violentCrimeRate, n)) << std::endl;
	}
}