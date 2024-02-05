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
#ifndef SENECA_COLLECTION_H
#define SENECA_COLLECTION_H

#include <iostream>
#include "Pair.h"

namespace seneca
{
	template <typename T, const unsigned int CAPACITY>
	class Collection
	{
		T m_arr[CAPACITY]{};
		static unsigned int m_count;
		T m_dummy;
	public:
		Collection();
		static unsigned int size();
		std::ostream& display(std::ostream& ostr = std::cout) const;
		virtual bool add(const T& item);
		T operator[](const unsigned int index) const;
		virtual ~Collection();
	};

	template <typename T, const unsigned int CAPACITY>
	std::ostream& operator<<(std::ostream& ostr, const Collection<T, CAPACITY>& other);

	template <typename T, const unsigned int CAPACITY>
	unsigned int Collection<T, CAPACITY>::m_count = 0;

	template <typename T, const unsigned int CAPACITY>
	Collection<T, CAPACITY>::Collection() : m_dummy{} {} 
	
	template <>
	Collection<Pair, 100>::Collection() : m_dummy{ "No Key", "No Value" } {} 

	template <typename T, const unsigned int CAPACITY>
	unsigned int Collection<T, CAPACITY>::size()
	{
		return m_count;
	}

	template <typename T, const unsigned int CAPACITY>
	std::ostream& Collection<T, CAPACITY>::display(std::ostream& ostr) const
	{
		unsigned int i;
		std::cout << "----------------------\n"
			<< "| Collection Content |\n"
			<< "----------------------\n";
		
		for (i = 0; i < m_count; ++i)
		{
			ostr << m_arr[i] << std::endl;
		}

		std::cout << "----------------------\n";
		return ostr;
	}

	template <typename T, const unsigned int CAPACITY>
	bool Collection<T, CAPACITY>::add(const T& item)
	{
		bool done = false;
		if (m_count < CAPACITY)
		{
			m_arr[m_count++] = item;
			done = true;
		}
		else
			done = false;
		return done;
	}

	template <typename T, const unsigned int CAPACITY>
	T Collection<T, CAPACITY>::operator[](const unsigned int index) const
	{
		if (index > m_count)
			return m_dummy;
		else
			return m_arr[index];
	}

	template <typename T, const unsigned int CAPACITY>
	std::ostream& operator<<(std::ostream& ostr, const Collection<T, CAPACITY>& other)
	{
		return other.display(ostr);
	}
	
	template <typename T, const unsigned int CAPACITY>
	Collection<T, CAPACITY>::~Collection() {};
}

#endif // !SENECA_COLLECTION_H

