// Name:                   Krutin Bharatbhai Polra
// Seneca Student ID:      135416220
// Seneca email:           kbpolra@myseneca.ca
// Date of completion:     14th March 2024
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.
#include <iostream>
#include "Utilities.h"

namespace seneca {
   char seneca::Utilities::m_delimiter;

   void Utilities::setFieldWidth(size_t newWidth)
   {
      m_widthField = newWidth;
   }

   size_t Utilities::getFieldWidth() const
   {
      return m_widthField;
   }

	std::string Utilities::extractToken(const std::string& str, size_t& next_pos, bool& more) {
		std::string token = "";
		static size_t tokenLength = 0;
		size_t index = 0;
		more = false;
		if (str.find(m_delimiter, next_pos) != next_pos)
		{
			if (str.find(m_delimiter, next_pos) >= str.length())
			{
				index = str.length();
			}
			else
			{
				index = str.find(m_delimiter, next_pos);
			}
			token = str.substr(next_pos, index - next_pos + 1);
			next_pos += token.length();
			if (next_pos >= str.length())
			{
				more = false;
			}
			else
			{
				token.erase(token.find(m_delimiter));
				more = true;
			}
			token = trim(token);
			if (tokenLength < token.size())
			{
				tokenLength = token.size();
				m_widthField = tokenLength;
			}
			if (more == false)
			{
				tokenLength = 0;
			}

		}
		else
		{
			more = false;
			tokenLength = 0;
			throw "   ERROR: No token.";
		}
		return token;
	}


   std::string Utilities::trim(std::string str)
   {
      if (!str.empty()) {
         str.erase(0, str.find_first_not_of(" "));
         str.erase(str.find_last_not_of(" ") + 1);
      }
      return str;
   }

   void Utilities::setDelimiter(char newDelimiter)
   {
      m_delimiter = newDelimiter;
   }

   char Utilities::getDelimiter()
   {
      return m_delimiter;
   }

}

