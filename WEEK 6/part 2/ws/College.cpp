//Name:     Krutin Bharatbhai Polra
//studentID:135416220
//email:    kbpolra@myseneca.ca
//Date:     5th March 2024
//Course:   OOP345 NAA
// I have done all the coding by myself and only copied the code 
// that my professor provided to complete my workshops and assignments.
#include <iomanip>
#include "College.h"

namespace seneca {

   College& College::operator+=(Person* thePerson) {
      m_persons.push_back(thePerson);
      return *this;
   }

   void College::display(std::ostream& out) const {
      out << "------------------------------------------------------------------------------------------------------------------------" << std::endl;
      out << "|                                        Test #1 Persons in the college!                                               |" << std::endl;
      out << "------------------------------------------------------------------------------------------------------------------------" << std::endl;
      for (auto it = m_persons.begin(); it != m_persons.end(); ++it) {
         (*it)->display(out);
         std::cout << std::endl;
      }

      out << "------------------------------------------------------------------------------------------------------------------------\n"
         << "|                                        Test #2 Persons in the college!                                               |\n"
         << "------------------------------------------------------------------------------------------------------------------------\n";
      for (size_t i = 0; i < m_persons.size(); ++i)
      {
         out << std::left << "| "
            << std::setw(10) << m_persons[i]->status() << "| "
            << std::setw(10) << m_persons[i]->id() << "| "
            << std::setw(20) << m_persons[i]->name() << " | "
            << std::setw(3) << m_persons[i]->age() << " |" << std::right << std::endl;
      }
      out << "------------------------------------------------------------------------------------------------------------------------\n";
   }

   College::~College()
   {
      for (auto it = m_persons.begin(); it != m_persons.end(); ++it)
      {
         delete (*it);
      }
   }
}
