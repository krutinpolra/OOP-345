// ---------------------------------------------------------
// Student Name :    Dharam Mehulbhai Ghevariya
// Student ID  :     136270220
// E-mail:           dmghevariya@myseneca.ca
// Date of compeletion: 02-02-2024
// Course/Section: OOP435/NAA
//
// I have done all the coding by myself and only copied the code that my
// professor provided to complete my workshops and assignments.
// ---------------------------------------------------------

#pragma once
#ifndef SENECA_SET_H
#define SENECA_SET_H

#include "Collection.h"
#include <cmath>

namespace seneca
{
	template <typename T>
	class Set : public Collection<T, 100>
	{
	public:
		bool add(const T& set) override;
	};

	template <typename T>
	bool Set<T>::add(const T& item)
	{	
		unsigned int i;
		bool found{};

		for (i = 0; i < this->size(); ++i)
		{
			if ((item == (*this)[i]))
			{
				found = true;
			}
		}
		if (!found)
		{
			return Collection<T, 100>::add(item);
		}
		else
		{
			return false;
		}
	}

	template<>
	bool Set<double>::add(const double& item)
	{
		unsigned int i;
		bool found{};

		for (i = 0; i < this->size(); ++i)
		{
			if (abs((*this)[i] - item) <= 0.01)
			{
				found = true;
			}
		}
		if (!found)
		{
			return Collection<double, 100>::add(item);
		}
		else
		{
			return false;
		}
	}
}

#endif // !SENECA_SET_H
