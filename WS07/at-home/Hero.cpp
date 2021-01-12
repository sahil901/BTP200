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
#include "Hero.h"

namespace sict 
{
    bool Hero::isAlive() const
    {
        return m_health > 0;
    }

    Hero::Hero()
    {
        m_name[0] = '\0';
        m_health = 0;
        m_strength = 0;
    }

    Hero::Hero(const char* name, int health, int power)
    {
        if (name == nullptr || name[0] == '\0' || power < 0 || health < 0)
        {
            *this = Hero();
        }
        else 
        {
            strncpy(m_name, name, 40);
            m_health = health;
            m_strength = power;
        }
    }
    int Hero::attackStrength() const 
    {
        return m_strength;
    }

    std::ostream& operator<<(std::ostream& os, const Hero& hero)
    {
        if (hero.m_name == nullptr)
        {
            return os << "No hero";
        }
        return os << hero.m_name;
    }

    void Hero::operator-=(int attack)
    {
        if (attack > 0)
        {
            this->m_health -= attack;        
        }

        if (this->m_health < 0)
        {
            this->m_health = 0;
        }
    }

    const Hero& operator*(const Hero& first, const Hero& second)
    {
        Hero left = first, right = second;
        int round = 0;

        for (round = 0; round < MAX_ROUNDS && (left.isAlive() && right.isAlive()); round++)
            {
                left -= right.attackStrength();
                right -= left.attackStrength();
            }

        if (left.isAlive())
        {
            std::cout << "Ancient Battle! " << left << " vs " << right << " : Winner is " << left << " in " << round << " rounds." << std::endl;
            return first;
        }
        else if (right.isAlive())
        {
            std::cout << "Ancient Battle! " << left << " vs " << right << " : Winner is " << right << " in " << round << " rounds." << std::endl;
            return second;
        }
        else if (!left.isAlive() && !right.isAlive())
        {
            std::cout << "Ancient Battle! " << left << " vs " << right << " : Winner is " << left << " in " << round << " rounds." << std::endl;
            return first;
        }
        else {
            return first;
        }
    }   
}