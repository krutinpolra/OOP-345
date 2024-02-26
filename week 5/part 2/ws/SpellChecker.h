//Name:     Krutin Bharatbhai Polra
//studentID:135416220
//email:    kbpolra@myseneca.ca
//Date:     25th february 2024
//Course:   OOP345 NAA
// I have done all the coding by myself and only copied the code 
// that my professor provided to complete my workshops and assignments.
#ifndef SENECA_SPELLCHECKER_H
#define SENECA_SPELLCHECKER_H

#include <string>

namespace seneca
{
	const size_t noOfString = 6;
	class SpellChecker
	{
		std::string m_badWords[noOfString];
		std::string m_goodWords[noOfString];
		size_t m_badWordStatistic[noOfString]{};
	public:
		SpellChecker(const char* filename);
		void operator()(std::string& text);
		void showStatistics(std::ostream& out) const;
	};
}

#endif // !SENECA_SPELLCHECKER_H

