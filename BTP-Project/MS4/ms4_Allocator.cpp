// Final Project - Milestone 4
// Version 3.7
// ms4_Allocator.cpp
// Date	2018/06/22
// Authors	Fardad Soleimanloo, Chris Szalwinski, Cornel
//
// For your final test before submission:
//      DO NOT MODIFY THIS FILE IN ANY WAY
//
// Revision History
// -----------------------------------------------------------
// Name               Date                 Reason
/////////////////////////////////////////////////////////////////

/*
Name: Sahil Patel
Seneca Student ID: 159-065-176
Seneca Email: spatel392@myseneca.ca
Date of completion: Summer 2019
Prof Name: Reid Kerr & Nargis Khan
Class Section: NAA
Decleration: I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/

#include "ms4_MyGood.h"

namespace aid
{
	iGood* CreateProduct(char tag) {
		if (tag == 'n')
			return new MyGood("Good");
		else
			return new MyGood("Perishable");
	}
}