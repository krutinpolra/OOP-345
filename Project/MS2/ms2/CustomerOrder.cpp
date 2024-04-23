// Name:                   Krutin Bharatbhai Polra
// Seneca Student ID:      135416220
// Seneca email:           kbpolra@myseneca.ca
// Date of completion:     24th March 2024
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.
#include <iostream>
#include <sstream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include "CustomerOrder.h"
#include "Station.h"
#include "Utilities.h"

namespace seneca {

	// Static member initialization
	size_t CustomerOrder::m_widthField = 0;

	// Constructor that initializes a CustomerOrder object from a string record
	CustomerOrder::CustomerOrder(const std::string& record) {
		Utilities Util;
		bool more = false;
		size_t position = 0u;

		if (!record.empty()) {
			// Extract customer name
			m_name = Util.extractToken(record, position, more);
			// If there's more data, extract product name
			if (more) {
				m_product = Util.extractToken(record, position, more);
			}
			// Extract item details
			std::string item = record.substr(position, record.length() - position);
			// Count the number of items
			m_cntItem = (count(item.begin(), item.end(), Util.getDelimiter())) + 1;

			// Allocate memory for the array of Item pointers
			m_lstItem = new Item * [m_cntItem];
			// Populate the array with Item objects
			for (size_t i = 0u; i < m_cntItem && more; i++)
				m_lstItem[i] = new Item(Util.extractToken(record, position, more));
			// Update the width field if necessary
			if (m_widthField < Util.getFieldWidth())
				m_widthField = Util.getFieldWidth();
		}
		else {
			// Set default values if record is empty
			m_name = "";
			m_product = "";
			m_cntItem = 0;
			m_lstItem = nullptr;
		}
	}

	// Copy constructor - not implemented
	CustomerOrder::CustomerOrder(CustomerOrder& record) {
		throw "Error!";
	}

	// Move constructor
	CustomerOrder::CustomerOrder(CustomerOrder&& record) noexcept {
		*this = std::move(record);
	}

	// Move assignment operator
	CustomerOrder& CustomerOrder::operator=(CustomerOrder&& record) noexcept {
		if (this != &record) {
			// Delete existing data
			for (auto i = 0u; i < m_cntItem; i++)
				delete m_lstItem[i];
			delete[] m_lstItem;

			// Move data from the source object
			m_name = record.m_name;
			m_product = record.m_product;
			m_cntItem = record.m_cntItem;
			m_lstItem = record.m_lstItem;

			// Clear data from the source object
			record.m_name = "";
			record.m_product = "";
			record.m_cntItem = 0;
			record.m_lstItem = nullptr;
		}
		return *this;
	}

	// Destructor
	CustomerOrder::~CustomerOrder() {
		for (auto i = 0u; i < m_cntItem; i++)
			delete m_lstItem[i];
		delete[] m_lstItem;
	}

	// Check if the entire order is filled
	bool CustomerOrder::isOrderFilled() const {
		bool isFilled = true;
		for (unsigned i = 0; i < m_cntItem; i++) {
			if (!m_lstItem[i]->m_isFilled) {
				isFilled = false;
				break; // No need to continue checking if one item is not filled
			}
		}
		return isFilled;
	}

	// Check if a specific item is filled
	bool CustomerOrder::isItemFilled(const std::string& itemName) const {
		bool isFilled = true;
		for (unsigned int i = 0; i < m_cntItem; i++) {
			if (m_lstItem[i]->m_itemName == itemName) {
				return m_lstItem[i]->m_isFilled;
			}
		}
		return isFilled;
	}

	// Fill an item at a station
	void CustomerOrder::fillItem(Station& station, std::ostream& os) {
		for (size_t i = 0; i < m_cntItem; i++) {
			if (m_lstItem[i]->m_itemName == station.getItemName() && !m_lstItem[i]->m_isFilled) {
				if (station.getQuantity() >= 1) {
					station.updateQuantity();
					m_lstItem[i]->m_serialNumber = station.getNextSerialNumber();
					m_lstItem[i]->m_isFilled = true;
					os << std::setw(11) << std::right;
					os << "Filled " << m_name << ", " << m_product << " [" << m_lstItem[i]->m_itemName << "]" << std::endl;
				}
				else {
					os << "    Unable to fill " << m_name << ", " << m_product << " [" << m_lstItem[i]->m_itemName << "]" << std::endl;
				}
				break; // No need to continue searching if item is filled or not found
			}
		}
	}

	// Display the details of the order
	void CustomerOrder::display(std::ostream& os) const {
		os << m_name << " - " << m_product << std::endl;
		for (unsigned int i = 0; i < m_cntItem; i++) {
			os << "[" << std::setw(6) << std::setfill('0') << m_lstItem[i]->m_serialNumber << "] ";
			os << std::setw(m_widthField) << std::setfill(' ') << std::left << m_lstItem[i]->m_itemName << " - ";
			if (m_lstItem[i]->m_isFilled)
				os << "FILLED" << std::endl;
			else
				os << "TO BE FILLED" << std::endl;
		}
	}
}
