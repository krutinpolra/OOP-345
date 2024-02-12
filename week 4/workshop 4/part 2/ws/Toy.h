//Name:     Krutin Bharatbhai Polra
//studentID:135416220
//email:    kbpolra@myseneca.ca
//Date:     8th february 2024
//Course:   OOP345 NAA
// I have done all the coding by myself and only copied the code 
// that my professor provided to complete my workshops and assignments.
#ifndef SENECA_TOY_H
#define SENECA_TOY_H
#include <string>
namespace seneca {

   class Toy
   {
      unsigned int m_orderID{};
      std::string m_nameOfToy{};
      unsigned int m_numberOfItems{};
      double m_priceOfToy{};
      const double HST = 0.13;

   public:

      Toy() = default;

      Toy(const std::string& toy);
      void update(int numItems);

      friend std::ostream& operator<<(std::ostream& os, const Toy& toy);
   };

}
#endif // !SENECA_TOY_H


