// Employee.cpp
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
      std::getline(is >> std::ws, m_id);
      m_id.erase(0, m_id.find_first_not_of(" ")); // Remove leading spaces
      m_id.erase(m_id.find_last_not_of(" ") + 1); // Remove trailing spaces

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
      out << "| " << std::left << std::setw(10) << status()
         << "| " << std::setw(10) << id()
         << "| " << std::setw(20) << name()
         << " | " << std::setw(3) << age()
         << " |" << std::endl;
   }
}
