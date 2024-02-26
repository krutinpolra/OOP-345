//Name:     Krutin Bharatbhai Polra
//studentID:135416220
//email:    kbpolra@myseneca.ca
//Date:     25th february 2024
//Course:   OOP345 NAA
// I have done all the coding by myself and only copied the code 
// that my professor provided to complete my workshops and assignments.
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include "SpellChecker.h"

using namespace std;

namespace seneca
{
	SpellChecker::SpellChecker(const char* filename)
	{
		ifstream file(filename);

		if (!file)
		{
			throw "Bad file name!";
		}
		else
		{
			string line;
			for (size_t i = 0; file && i < noOfString; ++i)
			{
				getline(file, line);

				size_t firstPosition = line.find(' ');
				m_badWords[i] = line.substr(0, firstPosition);
				string goodWord = line.substr(firstPosition + 1);

				size_t sizeOfspace = 0;
				for (size_t j = 0; j < goodWord.size() && isspace(goodWord[j]); ++j) {
					++sizeOfspace;
				}
				m_goodWords[i] = goodWord.erase(0, sizeOfspace);

			}
		}
	}

	void SpellChecker::operator()(std::string& text)
	{
		for (size_t i = 0; i < noOfString; i++)
		{
			size_t startingPosition{}, badWordPosition{};
			bool ISok{};

			do
			{
				badWordPosition = text.find(m_badWords[i], startingPosition);
				if (badWordPosition != string::npos)
				{
					text.replace(badWordPosition, m_badWords[i].size(), m_goodWords[i]);
					startingPosition = badWordPosition + m_badWords[i].size();
					m_badWordStatistic[i]++;
				}
				else
				{
					ISok = true;
				}
			} while (!ISok);
		}
	}

	void SpellChecker::showStatistics(std::ostream& out) const
	{
		out << "Spellchecker Statistics\n";
		for (size_t i = 0; i < noOfString; i++)
		{
			out << setw(15) << m_badWords[i]
				<< ": " << m_badWordStatistic[i] << " replacements\n";
		}
	}

}
