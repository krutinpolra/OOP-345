//Name:     Krutin Bharatbhai Polra
//studentID:135416220
//email:    kbpolra@myseneca.ca
//Date:     10th february 2024
//Course:   OOP345 NAA
// I have done all the coding by myself and only copied the code 
// that my professor provided to complete my workshops and assignments.
#ifndef SENECA_CONFIRMORDER_H
#define SENECA_CONFIRMORDER_H
#include "Toy.h"

namespace seneca {

   class ConfirmOrder
   {
      const Toy** m_toys{};
      size_t m_count{};

   public:
      ConfirmOrder() = default;
      ~ConfirmOrder();
    
      //copy constructor and copy assignment operator
      ConfirmOrder(const ConfirmOrder& other);
      ConfirmOrder& operator=(const ConfirmOrder& other);

      //move constructor and move assignment operator
      ConfirmOrder(ConfirmOrder&& other) noexcept;
      ConfirmOrder& operator=(ConfirmOrder&& other) noexcept;

      ConfirmOrder& operator+=(const Toy& toy);
      ConfirmOrder& operator-=(const Toy& toy);

      friend std::ostream& operator<<(std::ostream& os, const ConfirmOrder& co);
   };
}
#endif // !SENECA_CONFIRMORDER_H


