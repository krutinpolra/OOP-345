//Name:     Krutin Bharatbhai Polra
//studentID:135416220
//email:    kbpolra@myseneca.ca
//Date:     8th March 2024
//Course:   OOP345 NAA
// I have done all the coding by myself and only copied the code 
// that my professor provided to complete my workshops and assignments.
#ifndef SENECA_PROFESSOR_H
#define SENECA_PROFESSOR_H
#include "Employee.h"

namespace seneca {
   class Professor :
      public Employee
   {
      std::string m_department;
   public:
      Professor(std::istream& in);
      void display(std::ostream& out) const;
      std::string status() const;
      std::string department() const;
   };
}
#endif // !SENECA_PROFESSOR_H


