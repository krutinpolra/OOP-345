//Name:     Krutin Bharatbhai Polra
//studentID:135416220
//email:    kbpolra@myseneca.ca
//Date:     5th March 2024
//Course:   OOP345 NAA
// I have done all the coding by myself and only copied the code 
// that my professor provided to complete my workshops and assignments.
#ifndef COLLEGE_H
#define COLLEGE_H
#include <vector>
#include <list>
#include <iostream>
#include "Person.h"

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

      template <typename T>
      void select(const T& test, std::list<const Person*>& persons);
   };

   template <typename T>
   void College::select(const T& test, std::list<const Person*>& persons) {
      for (auto it = m_persons.begin(); it != m_persons.end(); ++it)
         if (test(*it))
            persons.push_back(*it);
   }
}

#endif // COLLEGE_H

