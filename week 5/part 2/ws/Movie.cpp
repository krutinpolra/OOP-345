//Name:     Krutin Bharatbhai Polra
//studentID:135416220
//email:    kbpolra@myseneca.ca
//Date:     25th february 2024
//Course:   OOP345 NAA
// I have done all the coding by myself and only copied the code 
// that my professor provided to complete my workshops and assignments.
#include <iostream>
#include <iomanip>
#include <string>
#include "Movie.h"
#include "Book.h"
namespace seneca {
   Movie::Movie(const std::string& strMovie)
   {
      if (!strMovie.empty()) {
         size_t firstSeparator = strMovie.find(',');
         size_t secondSeparator = strMovie.find(',', firstSeparator + 1);

         if (firstSeparator != std::string::npos && secondSeparator != std::string::npos) {
            m_movieTitle = eliminateSpace(strMovie.substr(0, firstSeparator));
            m_yearOfRelease = std::stoi(strMovie.substr(firstSeparator + 1, secondSeparator - firstSeparator - 1));

            // Calculate the length of the description substring
            size_t descLength = strMovie.size() - secondSeparator - 1;
            m_movieDescription = eliminateSpace(strMovie.substr(secondSeparator + 1, descLength));
         }
      }

   }
   Movie::Movie(const Movie& other)
   {
      *this = other;
   }
   Movie& Movie::operator=(const Movie& other)
   {

      if (this != &other)
      {
         m_movieTitle = other.m_movieTitle;
         m_yearOfRelease = other.m_yearOfRelease;
         m_movieDescription = other.m_movieDescription;
      }
      return *this;
   }
   const std::string& Movie::title() const
   {
      return m_movieTitle;
   }
   std::ostream& operator<<(std::ostream& ostr, const Movie& movie)
   {
      return ostr << std::setw(40) << movie.m_movieTitle << " | "
         << std::setw(4) << movie.m_yearOfRelease << " | "
         << movie.m_movieDescription << std::endl;
   }
}
