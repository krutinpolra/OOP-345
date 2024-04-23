// Utilities.cpp
#include "Utilities.h"
#include "Employee.h"

namespace seneca {

   Person* buildInstance(std::istream& in) {
      std::string tag;
      if (!(in >> tag))
         return nullptr;

      if (tag[0] == 'e' || tag[0] == 'E') {
         return new Employee(in);
      }

      return nullptr;
   }
}
