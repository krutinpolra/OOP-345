//Name:     Krutin Bharatbhai Polra
//studentID:135416220
//email:    kbpolra@myseneca.ca
//Date:     25th february 2024
//Course:   OOP345 NAA
// I have done all the coding by myself and only copied the code 
// that my professor provided to complete my workshops and assignments.
#ifndef SENECA_COLLECTION_H
#define SENECA_COLLECTION_H

#include <stdexcept>
#include <iostream>
#include <string>

namespace seneca
{
	template <typename T>
	class  Collection
	{
		T* m_collectionItems{};
		std::string m_nameOfCollection;
		size_t m_sizeOfCollection{};
		void (*m_observer)(const Collection<T>&, const T&) {};
	public:
		Collection(const std::string& name);

		//deleting copy operation
		Collection(const Collection&) = delete;
		Collection(const Collection&&) = delete;
		Collection& operator=(const Collection&) = delete;
		Collection& operator=(const Collection&&) = delete;


		~Collection();
		const std::string& name() const;
		size_t size() const;
		void setObserver(void (*observer)(const Collection<T>&, const T&));

		Collection<T>& operator+=(const T& item);

		T& operator[](size_t idx) const;
		T* operator[](const std::string& title) const;


		std::ostream& display(std::ostream& ostr = std::cout) const;
	};

	template <typename T>
	std::ostream& operator<<(std::ostream& ostr, const Collection<T>& collect);

	template <typename T>
	Collection<T>::Collection(const std::string& name)
	{
		m_nameOfCollection = name;
	}

	template <typename T>
	Collection<T>::~Collection()
	{
		delete[] m_collectionItems;
	}

	template <typename T>
	const std::string& Collection<T>::name() const
	{
		return m_nameOfCollection;
	}

	template <typename T>
	size_t Collection<T>::size() const
	{
		return m_sizeOfCollection;
	}

	template <typename T>
	void Collection<T>::setObserver(void (*observer)(const Collection<T>&, const T&))
	{
		m_observer = observer;
	}

	template <typename T>
	Collection<T>& Collection<T>::operator+=(const T& item)
	{
		for (size_t i = 0; i < m_sizeOfCollection; ++i)
		{
			if (m_collectionItems[i].title() == item.title())
			{
				return *this;
			}
		}

		T* tempObj = new T[m_sizeOfCollection + 1];

		for (size_t i = 0; i < m_sizeOfCollection; ++i)
		{
			tempObj[i] = m_collectionItems[i];
		}

		delete[] m_collectionItems;
		tempObj[m_sizeOfCollection++] = item;
		m_collectionItems = tempObj;
		tempObj = nullptr;

		if (m_observer)
		{
			m_observer(*this, m_collectionItems[m_sizeOfCollection - 1]);
		}
		return *this;
	}

	template <typename T>
	T& Collection<T>::operator[](size_t idx) const
	{
		if (idx < m_sizeOfCollection)
		{
			return m_collectionItems[idx];
		}
		else
		{
			throw std::out_of_range("Bad index [" + std::to_string(idx) + "]. Collection has [" + std::to_string(m_sizeOfCollection) + "] items.");
		}
	}

	template <typename T>
	T* Collection<T>::operator[](const std::string& title) const
	{
		for (size_t i = 0; i < m_sizeOfCollection; ++i)
		{
			if (m_collectionItems[i].title() == title)
			{
				return &m_collectionItems[i];
			}
		}
		return nullptr;
	}

	template <typename T>
	std::ostream& Collection<T>::display(std::ostream& ostr) const
	{
		for (size_t i = 0; i < m_sizeOfCollection; ++i)
		{
			ostr << m_collectionItems[i];
		}
		return ostr;
	}

	template <typename T>
	std::ostream& operator<<(std::ostream& ostr, const Collection<T>& collect)
	{
		return collect.display(ostr);
	}

}

#endif // !SENECA_COLLECTION_H



