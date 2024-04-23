// Name:                   Krutin Bharatbhai Polra
// Seneca Student ID:      135416220
// Seneca email:           kbpolra@myseneca.ca
// Date of completion:     15th March 2024
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.
#ifndef SENECA_STATION_H
#define SENECA_STATION_H
#include <string>
namespace seneca {

   class Station
   {
      size_t m_id;
      std::string m_nameOfItem{};
      std::string m_description{};
      unsigned int m_nextSerialNumber{};
      unsigned int m_quantity{};

      static size_t m_widthField;
      static size_t id_generator;
   public:

      Station(const std::string& record);
      const std::string& getItemName() const;
      size_t getNextSerialNumber();
      size_t getQuantity() const;
      void updateQuantity();
      void display(std::ostream& os, bool full) const;

   };
}
#endif // !SENECA_STATION_H


