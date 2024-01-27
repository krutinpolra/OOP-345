#pragma once
#ifndef SENECA_STRINGSET_H
#define SENECA_STRINGSET_H

#include <string>

namespace seneca {
   
   class StringSet
   {
      unsigned int m_numberOfString;

   public:
      StringSet();
      StringSet(size_t size);
      StringSet(const StringSet& other);
      StringSet& operator=(const StringSet& other);
      ~StringSet();

      size_t size() const;
      std::string operator[](size_t) const;
   };
}
#endif

