/*
Name: Sahil Patel
Seneca Student ID: 159-065-176
Seneca Email: spatel392@myseneca.ca
Date of completion: Summer 2019
Prof Name: Reid Kerr & Nargis Khan
Class Section: NAA
Decleration: I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/

#ifndef _sict_GRAPH_H
#define _sict_GRAPH_H

namespace sict {

#define MAX_NO_OF_SAMPLES 20

int findMax(int samples[], int noOfSamples);

void printBar(int val, int max);

void printGraph(int samples[], int noOfSamples);

void getSamples(int samples[], int noOfSamples);

}

#endif