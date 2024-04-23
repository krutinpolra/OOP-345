// College.cpp
#include "College.h"

namespace seneca {

   College::~College() {
      for (auto person : m_persons)
         delete person;
   }

   College& College::operator+=(Person* thePerson) {
      m_persons.push_back(thePerson);
      return *this;
   }

   void College::display(std::ostream& out) const {
      out << "------------------------------------------------------------------------------------------------------------------------" << std::endl;
      out << "|                                        Test #1 Persons in the college!                                               |" << std::endl;
      out << "------------------------------------------------------------------------------------------------------------------------" << std::endl;
      for (const auto person : m_persons)
         person->display(out);


      out << "------------------------------------------------------------------------------------------------------------------------\n"
         << "|                                        Test #2 Persons in the college!                                               |\n"
         << "------------------------------------------------------------------------------------------------------------------------\n";
      for (auto it = m_persons.begin(); it != m_persons.end(); ++it) {
         (*it)->display(out);
      }

      out << "------------------------------------------------------------------------------------------------------------------------\n";
   }
}
