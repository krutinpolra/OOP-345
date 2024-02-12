//Name:     Krutin Bharatbhai Polra
//studentID:135416220
//email:    kbpolra@myseneca.ca
//Date:     10th february 2024
//Course:   OOP345 NAA
// I have done all the coding by myself and only copied the code 
// that my professor provided to complete my workshops and assignments.
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "ConfirmOrder.h"

namespace seneca {
   
   ConfirmOrder::~ConfirmOrder()
   {
      delete[] m_toys;
   }

   ConfirmOrder::ConfirmOrder(const ConfirmOrder& other)
   {
      *this = other;
   }

   ConfirmOrder& ConfirmOrder::operator=(const ConfirmOrder& other) {
      if (this != &other) 
      {  // Check for self-assignment
         // Deallocate previously allocated memory
         for (size_t i = 0; i < m_count; ++i) {
            delete m_toys[i];
         }
         delete[] m_toys;

         // Copy other's data
         m_count = other.m_count;

         if (m_count != 0)
         {
            // Allocate memory for new array
            m_toys = new const Toy * [m_count];

            // Copy elements
            for (size_t i = 0; i < m_count; ++i) {
               m_toys[i] = other.m_toys[i];
            }
         }
         else 
         {
            m_toys = nullptr;
         }

      }
      return *this;
   }

   ConfirmOrder::ConfirmOrder(ConfirmOrder&& other) noexcept
   {
      *this = std::move(other);
   }

   ConfirmOrder& ConfirmOrder::operator=(ConfirmOrder&& other) noexcept {
      if (this != &other) 
      { // Check for self-assignment
         // Release current resources
         delete[] m_toys;

         // Steal the resources from the 'other' object
         m_toys = other.m_toys;
         m_count = other.m_count;

         // Reset 'other' object
         other.m_toys = nullptr;
         other.m_count = 0;
      }
      return *this;
   }

   ConfirmOrder& ConfirmOrder::operator+=(const Toy& toy)
   {
      bool exists = false;
      for (size_t i = 0; i < m_count; ++i)
      {
         if (m_toys[i] == &toy)
         {
            exists = true;
            break;
         }
      }

      if (!exists)
      {
         const Toy** temp = new const Toy * [m_count + 1];
         for (size_t i = 0; i < m_count; ++i)
         {
            temp[i] = m_toys[i];
         }
         temp[m_count] = &toy;

         delete[] m_toys;
         m_toys = temp;

         ++m_count;
      }

      return *this;
   }
   ConfirmOrder& ConfirmOrder::operator-=(const Toy& toy)
   {
      size_t foundIndex = m_count;
      for (size_t i = 0; i < m_count; ++i)
      {
         if (m_toys[i] == &toy)
         {
            foundIndex = i;
            break;
         }
      }

      if (foundIndex < m_count)
      {
         const Toy** temp = new const Toy * [m_count - 1];
         size_t j = 0;
         for (size_t i = 0; i < m_count; ++i)
         {
            if (i != foundIndex)
            {
               temp[j++] = m_toys[i];
            }
         }

         delete[] m_toys;
         m_toys = temp;
         --m_count;
      }

      return *this;
   }

   std::ostream& operator<<(std::ostream& os, const ConfirmOrder& co)
   {
      if (co.m_count == 0)
      {
         os << "--------------------------\n"
            << "Confirmations to Send\n"
            << "--------------------------\n"
            << "There are no confirmations to send!\n"
            << "--------------------------\n";
      }
      else {
         os << "--------------------------\n";
         os << "Confirmations to Send\n";
         os << "--------------------------\n";
         for (size_t i = 0; i < co.m_count; ++i) {
            os << *(co.m_toys[i]);
         }

         os << "--------------------------\n";
      }
      return os;
   }
}