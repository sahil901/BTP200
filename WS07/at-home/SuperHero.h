/*
Name: Sahil Patel
Seneca Student ID: 159-065-176
Seneca Email: spatel392@myseneca.ca
Date of completion: Summer 2019
Prof Name: Reid Kerr & Nargis Khan
Class Section: NAA
Decleration: I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/

#ifndef _SICT_SUPERHERO_H
#define _SICT_SUPERHERO_H
#include <iostream>
#include "Hero.h"

namespace sict 
{
    class SuperHero : public Hero
    {
        int m_superBonus;
        int m_defense;

        public:
            SuperHero();
            SuperHero(const char*, int, int, int, int);
            int attackStrength() const;
            int defend() const;
    };
    const SuperHero& operator*(const SuperHero& first, const SuperHero& second);
}
#endif