// Student Nmae: Krutin Bharatbhai Polra
// Student ID:   135416220
// E-mail:       kbpolra@myseneca.ca
// Date-Of-Compeletion: 27th January 2024
// Course: OOP345 NAA
// I have done all the coding by myself and only copied the code that my
// professor provided to complete my workshops and assignments.

#include <iostream>
#include <fstream>
#include "StringSet.h"

namespace seneca {

   StringSet::StringSet(const char* strSet)
   {
      std::ifstream file(strSet);

      if (!file.is_open())
      {
         std::cerr << "Error: Could not open file " << strSet << std::endl;
      }
      else
      {
         std::string word{};

         while (getline(file, word, ' '))
         {
            m_numberOfString++;
         }

         m_stringSet = new std::string[m_numberOfString];

         file.close();
         file.open(strSet);

         for (unsigned long long i = 0; i < m_numberOfString && getline(file, word, ' '); i++) {
            m_stringSet[i] = word;
         }

         file.close();
      }

   } 

   StringSet::StringSet(const StringSet& other)
   {
      *this = other;
   }

   StringSet& seneca::StringSet::operator=(const StringSet& other)
   {
      if (this != &other)
      {
         delete[] m_stringSet;
         m_numberOfString = other.m_numberOfString;

         if (m_numberOfString > 0) 
         {
            m_stringSet = new std::string[m_numberOfString];

            for (unsigned long long int i = 0; i < m_numberOfString; i++)
            {
               m_stringSet[i] = other.m_stringSet[i];
            }
         }
         else 
         {
            m_stringSet = nullptr;
         }

      }

      return *this;
   }

   StringSet::StringSet(StringSet&& other)
   {
      *this = std::move(other);

   }

   StringSet& StringSet::operator=(StringSet&& other)
   {
         if (this != &other)
         {
            delete[] m_stringSet;

            m_numberOfString = other.m_numberOfString;

            m_stringSet = other.m_stringSet;

            other.m_stringSet = nullptr;
            other.m_numberOfString = 0;
         }
         return *this;
   }



   StringSet::~StringSet()
   {
      delete[] m_stringSet;
   }



   size_t StringSet::size() const
   {
      return m_numberOfString;
   }

   std::string StringSet::operator[](size_t index) const
   {
      if (index < m_numberOfString) {
         return m_stringSet[index];
      }
      return "";
   }

}
