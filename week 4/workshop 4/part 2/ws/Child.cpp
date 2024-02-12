//Name:     Krutin Bharatbhai Polra
//studentID:135416220
//email:    kbpolra@myseneca.ca
//Date:     10th february 2024
//Course:   OOP345 NAA
// I have done all the coding by myself and only copied the code 
// that my professor provided to complete my workshops and assignments.
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Child.h"

namespace seneca {

   size_t Child::m_counter{};

   Child::Child(std::string name, int age, const Toy* toys[], size_t count) :
      m_nameOfChild(name),
      m_ageOfChild(age),
      m_numberOfToys(count)
   {
      m_toys = new const Toy * [count];
      for (unsigned int i = 0; i < count; ++i)
      {
         m_toys[i] = new Toy(*(toys[i])); // This dereferences the pointer obtained from toys[i], which gives us the actual Toy object it points to
      }
   }

   Child::Child(const Child& other)
   {
      *this = other;
   }

   Child& Child::operator=(const Child& other) {
      if (this != &other) { // Check for self-assignment
         // Deallocate previously allocated memory
         for (unsigned int i = 0; i < m_numberOfToys; ++i) {
            delete m_toys[i];
         }
         delete[] m_toys;

         // Copy member variables
         m_nameOfChild = other.m_nameOfChild;
         m_ageOfChild = other.m_ageOfChild;
         m_numberOfToys = other.m_numberOfToys;

         // Allocate new memory and copy toys
         m_toys = new const Toy * [m_numberOfToys];
         for (unsigned int i = 0; i < m_numberOfToys; ++i) {
            m_toys[i] = new Toy(*(other.m_toys[i]));
         }
      }
      return *this;
   }

   Child::Child(Child&& other) noexcept 
   {
      *this = std::move(other);
   }

   Child& Child::operator=(Child&& other) noexcept {
      if (this != &other) {
         for (size_t i = 0; i < m_numberOfToys; ++i) {
            delete m_toys[i];
         }
         delete[] m_toys;

         m_nameOfChild = other.m_nameOfChild;
         m_ageOfChild = other.m_ageOfChild;
         m_toys = other.m_toys;
         m_numberOfToys = other.m_numberOfToys;

         other.m_toys = nullptr;
         other.m_numberOfToys = 0;
         other.m_nameOfChild = "";
         other.m_ageOfChild = 0;
      }
      return *this;
   }

   Child::~Child()
   {
      for (unsigned int i = 0; i < m_numberOfToys; i++)
      {
         delete m_toys[i];
      }

      delete[] m_toys;
   }
   size_t Child::size() const
   {
      return m_numberOfToys;
   }
   std::ostream& operator<<(std::ostream& os, const Child& child) {
      Child::m_counter++;
      os << "--------------------------\n";
      os << "Child " << Child::m_counter << ": " << child.m_nameOfChild << " " << child.m_ageOfChild << " years old:\n";
      if (child.m_numberOfToys == 0) {
         os << "--------------------------\n"
            << "This child has no toys!\n";
      }
      else {
         os << "--------------------------\n";
         for (size_t i = 0; i < child.m_numberOfToys; ++i) {
            os << *(child.m_toys[i]);
         }
      }
      os << "--------------------------\n";
      return os;
   }
}

