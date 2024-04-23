//Name:     Krutin Bharatbhai Polra
//studentID:135416220
//email:    kbpolra@myseneca.ca
//Date:     8th March 2024
//Course:   OOP345 NAA
// I have done all the coding by myself and only copied the code 
// that my professor provided to complete my workshops and assignments.
#include <iostream>
#include <iomanip>
#include <string>
#include "Student.h"
namespace seneca {

   Student::Student(std::istream& is) : m_courses(nullptr) {
      
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
         is.ignore(1000, '\n');
         throw std::runtime_error(m_name + "++Invalid record!");
      }

      //read id
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

     // Read count
      std::string count_str;
      std::getline(is, count_str, ',');
      m_count = std::stoi(count_str);

      // read courses
      std::string str;
      if (m_count)
      {
         m_courses = new std::string[m_count];
         for (size_t i = 0; i < m_count - 1; ++i)
         {
            std::getline(is, str, ',');
            str.erase(0, str.find_first_not_of(" ")); // Remove leading spaces
            str.erase(str.find_last_not_of(" ") + 1);
            m_courses[i] = str;
         }

         std::getline(is , str, '\n');
         str.erase(0, str.find_first_not_of(" ")); // Remove leading spaces
         str.erase(str.find_last_not_of(" ") + 1);

         m_courses[m_count - 1] = str;
      }
   }

   std::string Student::age() const
   {
      return std::to_string(m_age);
   }
   std::string Student::id() const
   {
      return m_id;
   }
   std::string Student::status() const
   {
      return "Student";
   }
   std::string Student::name() const
   {
      return m_name;
   }
   void Student::display(std::ostream& out) const
   {
      out << std::left  << "| " << std::setw(10) << status() 
                        << "| " << std::setw(10) << m_id
                        << "| " << std::setw(20) << m_name 
                        << " | " << std::setw(3) << m_age
                        << " |" << std::right;

      for (size_t i = 0; i < m_count; ++i) {
         out << m_courses[i];
         if (i != m_count - 1)
            out << ", ";
      }
   }
   Student::~Student()
   {
      delete[] m_courses;
   }
}
