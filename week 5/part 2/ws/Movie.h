//Name:     Krutin Bharatbhai Polra
//studentID:135416220
//email:    kbpolra@myseneca.ca
//Date:     25th february 2024
//Course:   OOP345 NAA
// I have done all the coding by myself and only copied the code 
// that my professor provided to complete my workshops and assignments.
#ifndef SENECA_MOVIE_H
#define SENECA_MOVIE_H

#include <string>

namespace seneca
{
	class Movie
	{
		std::string m_movieTitle;
		size_t m_yearOfRelease{};
		std::string m_movieDescription;
	public:
		Movie() = default;
		Movie(const std::string& strMovie);
		
		Movie(const Movie& other);
		Movie& operator=(const Movie& other);
		
		const std::string& title() const;
		friend std::ostream& operator<<(std::ostream& ostr, const Movie& movie);

		template <typename T>
		void fixSpelling(T& spellChecker);
	};

	template <typename T>
	void Movie::fixSpelling(T& spellChecker)
	{
		spellChecker(m_movieTitle);
		spellChecker(m_movieDescription);
	}
}

#endif // !SENECA_MOVIE_H

