// Employee.h
#ifndef EMPLOYEE_H
#define EMPLOYEE_H
//Name:     Krutin Bharatbhai Polra
//studentID:135416220
//email:    kbpolra@myseneca.ca
//Date:     5th March 2024
//Course:   OOP345 NAA
// I have done all the coding by myself and only copied the code 
// that my professor provided to complete my workshops and assignments.
#include "Person.h"
#include <iostream>
#include <string>

namespace seneca {

   class Employee : public Person {
   private:
      std::string m_name{};
      int m_age{};
      std::string m_id{};

   public:
      Employee(std::istream& is);
      std::string status() const ;
      std::string name() const ;
      std::string id() const ;
      std::string age() const ;
      void display(std::ostream& out) const;
   };
}

#endif // EMPLOYEE_H
