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


