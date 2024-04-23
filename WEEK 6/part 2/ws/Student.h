//Name:     Krutin Bharatbhai Polra
//studentID:135416220
//email:    kbpolra@myseneca.ca
//Date:     8th March 2024
//Course:   OOP345 NAA
// I have done all the coding by myself and only copied the code 
// that my professor provided to complete my workshops and assignments.
#ifndef SENECA_STUDENT_H
#define SENECA_STUDENT_H
#include "Person.h"

namespace seneca{
   class Student : public Person
   {
      std::string m_name{};
      unsigned int m_age{};
      std::string m_id{};
      std::string* m_courses{};
      unsigned int m_count{};

   public:
      Student(const Student& S) = delete;
      Student& operator=(const Student& S) = delete;
      Student(std::istream& is);
      ~Student();
      std::string age() const;
      std::string id() const;
      std::string status() const;
      std::string name() const;
      void display(std::ostream& out) const;
   };
}
#endif // !SENECA_STUDENT_H
