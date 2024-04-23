// Name:                   Krutin Bharatbhai Polra
// Seneca Student ID:      135416220
// Seneca email:           kbpolra@myseneca.ca
// Date of completion:     16th March 2024
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.
#include <iomanip>
#include "Station.h"
#include "Utilities.h"

namespace seneca {
   
   size_t Station::m_widthField = 0;
   size_t Station::id_generator = 0;

   Station::Station(const std::string& record)
   {
      Utilities Util;
      bool more = true;
      size_t pos = 0;

      m_id = ++id_generator;
      m_nameOfItem = Util.extractToken(record, pos, more);
      m_nextSerialNumber = std::stoi(Util.extractToken(record, pos, more));
      m_quantity = std::stoi(Util.extractToken(record, pos, more));
      
      if (m_nameOfItem.length() > m_widthField) {
         m_widthField = m_nameOfItem.length();
      }

      m_description = Util.extractToken(record, pos, more);
      Util.trim(m_description, " ");
   }

   const std::string& Station::getItemName() const
   {
      return m_nameOfItem;
   }

   size_t Station::getNextSerialNumber()
   {
      return m_nextSerialNumber++;
   }

   size_t Station::getQuantity() const
   {
      return m_quantity;
   }

   void Station::updateQuantity()
   {
      if (m_quantity > 0)
      {
         m_quantity--;
      }
   }

   void Station::display(std::ostream& os, bool full) const
   {
      os << std::right << std::setfill('0') << std::setw(3) << m_id << " | " << std::left << std::setfill(' ')
         << std::setw(m_widthField) << m_nameOfItem << " | " << std::right << std::setfill('0')
         << std::setw(6) << m_nextSerialNumber << " | " << std::setfill(' ') << std::left;

      if (full)
      {
         os << std::right << std::setw(4) << m_quantity << " | " << std::left << m_description;
      }

      os << std::endl;
   }

}

