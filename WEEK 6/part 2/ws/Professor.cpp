//Name:     Krutin Bharatbhai Polra
//studentID:135416220
//email:    kbpolra@myseneca.ca
//Date:     8th March 2024
//Course:   OOP345 NAA
// I have done all the coding by myself and only copied the code 
// that my professor provided to complete my workshops and assignments.
#include <string>
#include "Employee.h"
#include "Professor.h"
namespace seneca {
   
   Professor::Professor(std::istream& in) : Employee(in) {

      std::string departMent{};
      std::getline(in, departMent, '\n');
      departMent.erase(0, departMent.find_first_not_of(" ")); // Remove leading spaces
      departMent.erase(departMent.find_last_not_of(" ") + 1);
      m_department = departMent;
   }

   void Professor::display(std::ostream& out) const {
      Employee::display(out);
      out << m_department << "| Professor";
   }

   std::string Professor::status() const {
      return "Professor";
   }

   std::string Professor::department() const {
      return m_department;
   }
}