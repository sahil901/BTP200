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
#include "Kingdom.h"
#include "Kingdom.h" // intentional

#include <cstring>
using namespace std;
using namespace sict;

void read(sict::Kingdom&);

int main() {
	int count = 0; // the number of kingdoms in the array

	struct Kingdom * pKingdom = nullptr;

	cout << "==========\n"
		<< "Input data\n"
		<< "==========\n"
		<< "Enter the number of Kingdoms: ";
	cin >> count;
	cin.ignore();

	if (count < 1) return 1;

	pKingdom = new Kingdom[count];

	for (int i = 0; i < count; ++i) {
		cout << "Kingdom #" << i + 1 << ": " << endl;
		read(pKingdom[i]);
	}
	cout << "==========" << endl << endl;

	// testing that "display(...)" works
	cout << "------------------------------" << endl
		<< "The 1st kingdom entered is" << endl
		<< "------------------------------" << endl;
	display(pKingdom[0]);
	cout << "------------------------------" << endl << endl;

	// expand the array of Kingdoms by 1 element
	{
		// TODO: allocate dynamic memory for count + 1 Kingdoms
		struct Kingdom* newKingdom = new Kingdom[count + 1];
		// TODO: copy elements from original array into this newly allocated array
		for (int i = 0; i < count + 1; i++) {
			strcpy(newKingdom[i].m_name, pKingdom[i].m_name);
			newKingdom[i].m_population = pKingdom[i].m_population;
		}
		// TODO: deallocate the dynamic memory for the original array
		delete[] pKingdom;
		// TODO: copy the address of the newly allocated array into pKingdom pointer
		pKingdom = newKingdom;
		// add the new Kingdom
		cout << "==========\n"
			<< "Input data\n"
			<< "==========\n"
			<< "Kingdom #" << count + 1 << ": " << endl;
		// TODO: accept input for the new element in the array
		read(pKingdom[count]);
		count++;
		cout << "==========\n" << endl;
	}

	// testing that the overload of "display(...)" works
	display(pKingdom, count);

	// TODO: deallocate the dynamic memory here
	delete[] pKingdom;
	pKingdom = nullptr;

	return 0;
}

// read accepts data for a Kingdom from standard input
//
void read(Kingdom& kingdom) {
	cout << "Enter the name of the Kingdom: ";
	cin.get(kingdom.m_name, 32, '\n');
	cin.ignore(2000, '\n');
	cout << "Enter the number of people living in " << kingdom.m_name << ": ";
	cin >> kingdom.m_population;
	cin.ignore(2000, '\n');
}
