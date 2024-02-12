//Name:     Krutin Bharatbhai Polra
//studentID:135416220
//email:    kbpolra@myseneca.ca
//Date:     10th february 2024
//Course:   OOP345 NAA
// I have done all the coding by myself and only copied the code 
// that my professor provided to complete my workshops and assignments.
#ifndef SENECA_CHILD_H
#define SENECA_CHILD_H
#include <string>
#include "Toy.h"

namespace seneca {

   class Child
   {
      std::string m_nameOfChild{};
      unsigned int m_ageOfChild{};
      const Toy** m_toys{};
      size_t m_numberOfToys{};
      static size_t m_counter;

   public:

      Child(std::string name, int age, const Toy* toys[], size_t count);
      ~Child();
      Child(const Child& other);
      Child& operator=(const Child& other);
      Child(Child&& other) noexcept;
      Child& operator=(Child&& other) noexcept;

      size_t size() const;

      friend std::ostream& operator<<(std::ostream& os, const Child& child);
   };

}
#endif // !SENECA_CHILD_H


