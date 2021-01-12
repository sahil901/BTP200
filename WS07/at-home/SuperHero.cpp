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
#include "SuperHero.h"

using namespace std;

namespace sict 
{

SuperHero::SuperHero() : Hero()
{
    m_defense = 0;
    m_superBonus = 0;
}

SuperHero::SuperHero(const char* name, int health, int attack, int bonus, int defense) : Hero(name, health, attack)
{
    m_superBonus = bonus;
    m_defense = defense;
}
int SuperHero::attackStrength() const
{
    return Hero::attackStrength() != -1 ? Hero::attackStrength() + m_superBonus : 0;
}

    int SuperHero::defend() const
    {
        return m_defense != -1 ? m_defense : 0;   
    }

const SuperHero& operator*(const SuperHero& first, const SuperHero& second)
{
        SuperHero left = first, right = second;
        int round = 0;

        for (round = 0; round < MAX_ROUNDS && (left.isAlive() && right.isAlive()); round++)
            {
                left -= right.attackStrength() - left.defend();
                right -= left.attackStrength() - right.defend();
            }
        if (left.isAlive())
        {
            std::cout << "Super Fight! " << left << " vs " << right << " : Winner is " << left << " in " << round << " rounds." << std::endl;
            return first;
        }
        else if (right.isAlive())
        {
            std::cout << "Super Fight! " << left << " vs " << right << " : Winner is " << right << " in " << round << " rounds." << std::endl;
            return second;
        }
        else if (!left.isAlive() && !right.isAlive())
        {
            std::cout << "Super Fight! " << left << " vs " << right << " : Winner is " << left << " in " << round << " rounds." << std::endl;
            return first;
        }
        else {
            return first;
        }
}
    
}