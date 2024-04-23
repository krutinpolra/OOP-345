// Name:                   Krutin Bharatbhai Polra
// Seneca Student ID:      135416220
// Seneca email:           kbpolra@myseneca.ca
// Date of completion:     23th March 2024
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.

#ifndef SENECA_CUSTOMERORDER_H
#define SENECA_CUSTOMERORDER_H

#include <iostream>
#include <string>
#include "Station.h"    // Include necessary header files
#include "Utilities.h"

namespace seneca {
   // Declaration of struct Item, representing an item in a customer order
   struct Item
   {
      std::string m_itemName;     // Name of the item
      size_t m_serialNumber{ 0 }; // Serial number of the item
      bool m_isFilled{ false };   // Flag indicating whether the item is filled

      // Constructor initializing the item name
      Item(const std::string& src) : m_itemName(src) {};
   };

   // Declaration of class CustomerOrder, representing a customer order
   class CustomerOrder
   {
      std::string m_name{};       // Name of the customer
      std::string m_product{};    // Product associated with the order
      size_t m_cntItem{};         // Count of items in the order
      Item** m_lstItem{};         // Pointer to an array of pointers to items in the order
      static size_t m_widthField; // Width of the field for formatting output

   public:
      // Default constructor
      CustomerOrder() = default;
      // Constructor that initializes a CustomerOrder object from a string record
      CustomerOrder(const std::string& record);
      // Copy constructor (deleted)
      CustomerOrder(CustomerOrder& record);
      // Copy assignment operator (deleted)
      CustomerOrder& operator=(CustomerOrder& record) = delete;
      // Move constructor
      CustomerOrder(CustomerOrder&& record) noexcept;
      // Move assignment operator
      CustomerOrder& operator=(CustomerOrder&& record) noexcept;
      // Destructor
      ~CustomerOrder();

      // Member functions
      bool isOrderFilled() const;                     // Check if the entire order is filled
      bool isItemFilled(const std::string& itemName) const; // Check if a specific item is filled
      void fillItem(Station& station, std::ostream& os);     // Fill an item at a station
      void display(std::ostream& os) const;           // Display the details of the order
   };
}

#endif // !SENECA_CUSTOMERORDER_H
