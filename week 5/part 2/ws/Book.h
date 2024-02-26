//Name:     Krutin Bharatbhai Polra
//studentID:135416220
//email:    kbpolra@myseneca.ca
//Date:     25th february 2024
//Course:   OOP345 NAA
// I have done all the coding by myself and only copied the code 
// that my professor provided to complete my workshops and assignments.

#ifndef SENECA_BOOK_H
#define SENECA_BOOK_H

#include <string>

namespace seneca{

   class Book {

      std::string m_author;
      std::string m_title;
      std::string m_country;
      size_t m_year{};
      double m_price{};
      std::string m_description;

   public:
      Book() = default; // Default constructor
      Book(const std::string& strBook); // Constructor from string
      Book(const Book& other);
      Book& operator=(const Book& other);

      const std::string& title() const;
      const std::string& country() const;
      const size_t& year() const;
      double& price();
      friend std::ostream& operator<<(std::ostream& os, const Book& book);
      
      template<typename T>
      void fixSpelling(T& spellChecker);
   };
   std::string eliminateSpace(std::string string);

   template <typename T>
   void Book::fixSpelling(T& spellChecker)
   {
      spellChecker(m_description);
   }
}
#endif // !SENECA_BOOK_H


