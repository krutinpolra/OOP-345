// ---------------------------------------------------------
// Student Name :    Krutin Bharatbhai Polra
// Student ID  :     136270220
// E-mail:           kbpolra@myseneca.ca
// Date of compeletion: 02-02-2024
// Course/Section: OOP435/NAA
//
// I have done all the coding by myself and only copied the code that my
// professor provided to complete my workshops and assignments.
// ---------------------------------------------------------

#include "Pair.h"
#include <iostream>
#include <iomanip>

using namespace std;

namespace seneca
{
	Pair::Pair(const std::string& key, const std::string& value) : m_key(key), m_value(value) {}

	Pair::Pair(const Pair& other)
	{
		*this = other;
	}

	Pair& Pair::operator=(const Pair& other)
	{
		if (this != &other)
		{
			m_key = other.m_key;
			m_value = other.m_value;
		}
		return *this;
	}

	ostream& Pair::display(ostream& ostr) const
	{
		ostr << std::right << std::setw(20) << m_key << ": " << std::left << m_value;
		return ostr;
	}

	bool Pair::operator==(const Pair& other) const
	{
		bool done{};

		if (m_key == other.m_key)
		{
			done = true;
		}
		else
			done = false;

		return done;
	}

	std::ostream& operator<<(std::ostream& ostr, const Pair& pair)
	{
		return pair.display(ostr);
	}

	const std::string& Pair::getKey()
	{
		return m_key;
	}

	const std::string& Pair::getValue()
	{
		return m_value;
	}

}