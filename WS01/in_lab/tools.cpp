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
#include "tools.h"
using namespace std;

int menu(){
  cout << "1- Number of Samples" << endl;
  cout << "2- Sample Entry" << endl;
  cout << "3- Draw Graph" << endl;
  cout << "0- Exit" << endl;
  cout << "> ";
  return getInt(0, 3);
}

int getInt(int min, int max){
  int val;
  bool done = false;
  while (!done){
    cin >> val;
    if (cin.fail()){
      cin.clear();
      cout << "Invalid Integer, try again: ";
    }
    else{
      if (val < min || val > max){
        cout << "Invalid value!" << endl << "Enter a value between " << min << " and " << max << ": ";
      }
      else{
        done = true;
      }
    }
    cin.ignore(1000, '\n');
  }
  return val;
}