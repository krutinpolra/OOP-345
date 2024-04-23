//Name:     Krutin Bharatbhai Polra
//studentID:135416220
//email:    kbpolra@myseneca.ca
//Date:     5th March 2024
//Course:   OOP345 NAA
// I have done all the coding by myself and only copied the code 
// that my professor provided to complete my workshops and assignments.
#ifndef SENECA_PERSON_H
#define SENECA_PERSON_H
#include <iostream>
#include <string>

namespace seneca
{
	class Person
	{
	public:
		virtual std::string status() const = 0;
		virtual std::string name() const = 0;
		virtual std::string age() const = 0;
		virtual std::string id() const = 0;
		virtual void display(std::ostream&) const = 0;
		
		virtual ~Person() = default;
	};
}

#endif