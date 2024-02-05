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

#pragma once
#ifndef SENECA_PAIR_H
#define SENECA_PAIR_H

#include <iostream>
#include <string>

namespace seneca
{
	class Pair
	{
		std::string m_key{};
		std::string m_value{};
	public:
		const std::string& getKey();
		const std::string& getValue();
		Pair(const std::string& key, const std::string& value); 

		// TODO: Add here the missing prototypes for the members
		//           that are necessary if this class is to be used
		//           with the template classes described below.
		//       Implement them in the Pair.cpp file.

		Pair() = default;
		Pair(const Pair& other);
		Pair& operator=(const Pair& other);
		std::ostream& display(std::ostream& ostr = std::cout) const;
		bool operator==(const Pair& other) const;
	};
	std::ostream& operator<< (std::ostream& ostr, const Pair& pair);
}

#endif // !SENECA_PAIR_H

