/*
Name: Sahil Patel
Seneca Student ID: 159-065-176
Seneca Email: spatel392@myseneca.ca
Date of completion: Summer 2019
Prof Name: Reid Kerr & Nargis Khan
Class Section: NAA
Decleration: I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/

#ifndef _SICT_HERO_H
#define _SICT_HERO_H

namespace sict 
{
    const int MAX_ROUNDS = 100;

    class Hero
    {
        char m_name[40];
        int m_health;
        int m_strength;
    public:
        Hero();
        Hero(const char*, int, int);
        void operator-=(int);
        bool isAlive() const;
        int attackStrength() const;
        friend std::ostream& operator<<(std::ostream&, const Hero&);
    };
    const Hero& operator*(const Hero& first, const Hero& second);
}
#endif