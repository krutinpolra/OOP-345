//Name:     Krutin Bharatbhai Polra
//studentID:135416220
//email:    kbpolra@myseneca.ca
//Date:     8th february 2024
//Course:   OOP345 NAA
// I have done all the coding by myself and only copied the code 
// that my professor provided to complete my workshops and assignments.

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <iomanip>
#include "Toy.h"

namespace seneca {
   Toy::Toy(const std::string& toy) : m_orderID(0), m_nameOfToy(""), m_numberOfItems(0), m_priceOfToy(0.0)
   {
      size_t position = toy.find(':');
      m_orderID = std::stoi(toy.substr(0, position));

      size_t nextPosition = toy.find(':', position + 1);
      m_nameOfToy = toy.substr(position + 1, nextPosition - position - 1);

      do
      {
         if (isspace(m_nameOfToy[0]))
         {
            m_nameOfToy.erase(0, 1);
         }
      } while (m_nameOfToy[0] == ' ');

      do
      {
         if (isspace(m_nameOfToy[m_nameOfToy.size() - 1]))
         {
            m_nameOfToy.erase(m_nameOfToy.size() - 1, 1);
         }

      } while (m_nameOfToy[m_nameOfToy.size() - 1] == ' ');

      position = nextPosition;
      nextPosition = toy.find(':', position + 1);
      m_numberOfItems = std::stoi(toy.substr(position + 1, nextPosition - position -1));

      position = nextPosition;
      m_priceOfToy = std::stod(toy.substr(position + 1));
   }

   void Toy::update(int numItems)
   {
      this->m_numberOfItems = numItems;
   }

   std::ostream& operator<<(std::ostream& os, const Toy& toy)
   {
      double price = toy.m_priceOfToy;
      double subtotal = price * static_cast<double>(toy.m_numberOfItems);
      double tax = subtotal * toy.HST;
      double total = subtotal + tax;

      os << "Toy" << std::setw(8) << toy.m_orderID << ":"
         << std::setw(18) << toy.m_nameOfToy << std::setw(3)
         << toy.m_numberOfItems << " items" 
         << std::fixed << std::setprecision(2) << std::setw(8)
         << toy.m_priceOfToy << "/item  subtotal:" << std::setw(7)
         << subtotal << " tax:"
         << std::setw(6) << tax
         << " total:" << std::setw(7) 
         << total << "\n";

      return os;
   }

}

