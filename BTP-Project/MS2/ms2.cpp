// Final Project Milestone 2 - Error Class
// Version 3.7
// ms2.cpp
// Date	2019-06-22
// Author	Chris Szalwinski, Fardad Soleimanloo, Cornel
//
// For you final test before submission:
//      DO NOT MODIFY THIS FILE IN ANY WAY
//
// Revision History
// --------------------------------------------------------------
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

#include <iostream>
#include "Error.h"
#include "Error.h" // intentional

using namespace std;
using namespace aid;

int main() {
   Error T("Testing Error Module");
   Error e;
   Error f("");
   Error g(nullptr);
   int ret = 0;
   bool ok = true;
   cout << T << endl 
	    << "e: " << e 
	    << "isClear(): " << (e.isClear() ? "Passed!" : "Failed!") << endl
	    << "f: " << f 
	    << "isClear(): " << (f.isClear() ? "Passed!" : "Failed!") << endl
        << "g: " << g 
	    << "isClear(): " << (g.isClear() ? "Passed!" : "Failed!") << endl;
   if (!e.isClear()) ok = false;
   cout << "-----------| Long Message\r";
   for (int i = 0; i < 10000000; i++) {
      if (i % 1000000 == 0) {
         cout << "*";
         cout.flush();
      }
      e.message("An error message that is really long long  long  long  long  long  long  long"
         " long  long  long  long  long  long  long  long  long  long  long  long  long"
         " long  long  long  long  long  long  long  long  long  long  long  long  long"
         " long  long  long  long  long  long  long  long  long  long  long  long  long"
         " long  long  long  long  long  long  long  long  long  long  long  long  long"
         " long  long  long  long  long  long  long  long  long  long  long  long  long"
         " long  long  long  long  long  long  long  long  long  long  long  long  long"
         " long  long  long  long  long  long  long  long  long  long  long  long  long"
         " long  long  long  long  long  long  long  long  long  long  long  long  long"
         " long  long  long  long  long  long  long  long  long  long  long  long  long"
         " long  long  long  long  long  long  long  long  long  long  long  long  long"
         " long  long  long  long  long  long  long  long  long  long  long  long  long"
         " long  long  long  long  long  long  long  long  long  long  long  long  long"
         " long  long  long  long  long  long  long  long  long  long  long  long  long"
         " long  long  long  long  long  long  long  long  long  long  long  long  long"
         " long  long  long  long  long  long  long  long  long  long  long  long  long"
         " long  long  long  long  long  long  long  long  long  long  long  long  long"
         " long  long  long  long  long  long  long  long  long  long  long  long  long"
         " long  long  long  long  long  long  long  long  long  long  long  long  long");
   }
   cout << '*' << endl;
   cout << e << "|***********\nLong Message  isClear(): " << (e.isClear() ? "Failed!" : "Passed!") << endl;
   if (e.isClear()) ok = false;

   e.message("Short Message");
   cout << e << " isClear(): " << (e.isClear() ? "Failed!" : "Passed!") << endl;
   if (e.isClear()) ok = false;

   e.message("Clear Message");
   cout << e;
   e.clear();
   cout << e << " isClear(): " << (e.isClear() ? "Passed!" : "Failed!") << endl;
   if (!e.isClear()) ok = false;

   e.message("Empty Message");
   cout << e;
   e.message("");
   cout << e << " isClear(): " << (!e.isClear() ? "Failed!" : "Passed!") << endl;
   if (!e.isClear()) ok = false;
   cout << endl;

   if (ok) {
	   cout << "You passed all the tests!" << endl;
   }
   else {
	   cout << "You did not pass all the tests, keep working on your project!" << endl;
	   ret = 1;
   }

   return ret;
}