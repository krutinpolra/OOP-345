// College.h
#ifndef COLLEGE_H
#define COLLEGE_H

#include "Person.h"
#include <vector>
#include <iostream>

namespace seneca {

   class College {
   private:
      std::vector<Person*> m_persons;

   public:
      College() = default;
      ~College();
      College(const College&) = delete;
      College& operator=(const College&) = delete;
      College& operator+=(Person* thePerson);
      void display(std::ostream& out) const;
   };
}

#endif // COLLEGE_H

