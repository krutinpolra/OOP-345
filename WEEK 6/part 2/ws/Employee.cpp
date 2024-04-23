//Name:     Krutin Bharatbhai Polra
//studentID:135416220
//email:    kbpolra@myseneca.ca
//Date:     5th March 2024
//Course:   OOP345 NAA
// I have done all the coding by myself and only copied the code 
// that my professor provided to complete my workshops and assignments.
#include "Employee.h"
#include <sstream>
#include <stdexcept>
#include <iomanip>

namespace seneca {

   Employee::Employee(std::istream& is) {
      
      // Read name
      std::getline(is >> std::ws, m_name, ',');
      m_name.erase(0, m_name.find_first_not_of(" ")); // Remove leading spaces
      m_name.erase(m_name.find_last_not_of(" ") + 1); // Remove trailing spaces

      // Read age
      std::string age_str;
      std::getline(is, age_str, ',');
      try {
         m_age = std::stoi(age_str);
      }
      catch (const std::invalid_argument&) {
         throw std::runtime_error(m_name + "++Invalid record!");
      }

      // Read ID
      std::string id_str{};
      char id;
      is.get(id);
      do
      {
         id_str += id; 
         is.get(id);

      } while (id != '\n' && id != ',');
      id_str.erase(0, id_str.find_first_not_of(" ")); // Remove leading spaces
      id_str.erase(id_str.find_last_not_of(" ") + 1); // Remove trailing spaces
      m_id = id_str;

      if (m_name.empty() || m_id.empty() || m_id[0] != 'E')
         throw std::runtime_error(m_name + "++Invalid record!");
   }

   std::string Employee::status() const {
      return "Employee";
   }

   std::string Employee::name() const {
      return m_name;
   }

   std::string Employee::id() const {
      return m_id;
   }

   std::string Employee::age() const {
      return std::to_string(m_age);
   }

   void Employee::display(std::ostream& out) const {
      out << "| " << std::left << std::setw(10) << Employee::status()
         << "| " << std::setw(10) << id()
         << "| " << std::setw(20) << name()
         << " | " << std::setw(3) << age()
         << " |" << std::right;
   }
}
