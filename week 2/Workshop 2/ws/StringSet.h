// Student Nmae: Krutin Bharatbhai Polra
// Student ID:   135416220
// E-mail:       kbpolra@myseneca.ca
// Date-Of-Compeletion: 27th January 2024
// Course: OOP345 NAA
// I have done all the coding by myself and only copied the code that my
// professor provided to complete my workshops and assignments.


#ifndef SENECA_STRINGSET_H
#define SENECA_STRINGSET_H

#include <string>

namespace seneca {
   
   class StringSet
   {
      std::string* m_stringSet{};
      unsigned long long m_numberOfString{};

   public:
      StringSet() = default;
      StringSet(const char* strSet);
      StringSet(const StringSet& other);
      StringSet& operator=(const StringSet& other);
      ~StringSet();
      StringSet(StringSet&& other);
      StringSet& operator=(StringSet&& other);
      size_t size() const;
      std::string operator[](size_t index) const;
   };
}
#endif

