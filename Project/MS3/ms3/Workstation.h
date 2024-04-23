// Name:                   Krutin Bharatbhai Polra
// Seneca Student ID:      135416220
// Seneca email:           kbpolra@myseneca.ca
// Date of completion:     6th April 2024
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.
#ifndef SENECA_WORKSTATION_H
#define SENECA_WORKSTATION_H
#include <iostream>
#include <deque>
#include <ostream>
#include <string>
#include "Station.h"
#include "CustomerOrder.h"

namespace seneca {

   extern std::deque<CustomerOrder> g_pending;
   extern std::deque<CustomerOrder> g_completed;
   extern std::deque<CustomerOrder> g_incomplete;

   class Workstation : public Station {
      std::deque<CustomerOrder> m_orders;
      Workstation* m_pNextStation = nullptr;

   public:
      // Copy operations are deleted
      Workstation(const Workstation& other) = delete;
      Workstation(Workstation&& other) = delete;
      Workstation& operator=(const Workstation& other) = delete;
      Workstation& operator=(Workstation&& other) = delete;

      Workstation(const std::string&);

      void fill(std::ostream& os);
      bool attemptToMoveOrder();
      void setNextStation(Workstation* station = nullptr);
      Workstation* getNextStation() const;
      void display(std::ostream& os) const;
      Workstation& operator+=(CustomerOrder&& newOrder);
      bool allOrderFilled();

   };
}
#endif // !SENECA_WORKSTATION_H

