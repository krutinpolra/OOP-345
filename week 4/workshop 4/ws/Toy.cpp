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

      os << std::left << std::setw(5) << "Toy " << std::setw(10) << toy.m_orderID << ": "
         << std::setw(18) << std::right << toy.m_nameOfToy
         << std::setw(3) << std::right << toy.m_numberOfItems 
         << std::setw(6) << std::right << "items"
         << std::fixed << std::setprecision(2) << std::setw(8) << std::right << price << "/item "
         << "subtotal: " << std::setw(7) << std::right << subtotal
         << " tax: " << std::setw(6) << std::right << tax
         << " total: " << std::setw(7) << std::right << total << std::endl;

      return os;
   }

}

