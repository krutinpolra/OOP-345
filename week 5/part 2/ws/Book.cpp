//Name:     Krutin Bharatbhai Polra
//studentID:135416220
//email:    kbpolra@myseneca.ca
//Date:     25th february 2024
//Course:   OOP345 NAA
// I have done all the coding by myself and only copied the code 
// that my professor provided to complete my workshops and assignments.
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <iomanip>
#include <string>
#include <vector>
#include "Book.h"

using namespace std;

namespace seneca {

   Book::Book(const std::string& strBook)
   {
      if (!strBook.empty()) {
         size_t firstPos = strBook.find(',');
         size_t secondPos = strBook.find(',', firstPos + 1);
         size_t thirdPos = strBook.find(',', secondPos + 1);
         size_t forthPos = strBook.find(',', thirdPos + 1);
         size_t fifthPos = strBook.find(',', forthPos + 1);

         string author = strBook.substr(0, firstPos);
         string title = strBook.substr(firstPos + 1, secondPos - firstPos - 1);
         string country = strBook.substr(secondPos + 1, thirdPos - secondPos - 1);
         string price = strBook.substr(thirdPos + 1, forthPos - thirdPos - 1);
         string year = strBook.substr(forthPos + 1, fifthPos - forthPos - 1);
         string description = strBook.substr(fifthPos + 1);

         m_author = eliminateSpace(author);
         m_title = eliminateSpace(title);
         m_country = eliminateSpace(country);
         m_year = stoi(year);
         m_price = stod(price);
         m_description = eliminateSpace(description);
      }
   }

   
   const std::string& Book::title() const
   {
      return m_title;
   }

   const std::string& Book::country() const
   {
      return m_country;
   }

   const size_t& Book::year() const
   {
      return m_year;
   }

   double& Book::price()
   {
      return m_price;
   }

   Book::Book(const Book& other) {
      m_author = other.m_author;
      m_title = other.m_title;
      m_country = other.m_country;
      m_year = other.m_year;
      m_price = other.m_price;
      m_description = other.m_description;
   }

   Book& Book::operator=(const Book& other) {
      if (this != &other) {
         m_author = other.m_author;
         m_title = other.m_title;
         m_country = other.m_country;
         m_year = other.m_year;
         m_price = other.m_price;
         m_description = other.m_description;
      }
      return *this;
   }

   std::ostream& operator<<(std::ostream& os, const Book& book) {
      os << std::setw(20)  << book.m_author
         << " | " << std::setw(22) << book.m_title
         << " | " << std::setw(5) << book.m_country
         << " | " << std::setw(4)  << book.m_year << std::fixed
         << " | " << std::setw(6) << std::setprecision(2) << book.m_price
         << " | " << book.m_description
         << std::endl;
      return os;
   }

   std::string eliminateSpace(std::string str)
   {
      int spaceSize{};
      size_t i{};
      do
      {
         if (isspace(str[i]))
         {
            spaceSize++;
         }
      } while (isspace(str[i++]));

      str.erase(0, spaceSize);

      spaceSize = 0;
      i = str.size() - 1;

      do
      {
         if (isspace(str[i]))
         {
            spaceSize++;
         }
      } while (isspace(str[i--]));

      str.erase(i + 2, spaceSize);

      return str;
   }


} // namespace seneca