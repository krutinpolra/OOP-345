//Name:     Krutin Bharatbhai Polra
//studentID:135416220
//email:    kbpolra@myseneca.ca
//Date:     5th March 2024
//Course:   OOP345 NAA
// I have done all the coding by myself and only copied the code 
// that my professor provided to complete my workshops and assignments.
#include "Utilities.h"
#include "Professor.h"
#include "Student.h"
#include "Employee.h"

namespace seneca {

   Person* buildInstance(std::istream& in) {
      std::string tag{};
      Person* prsn{};
      if (!(in >> tag))
         return nullptr;

      if (tag[0] == 'e' || tag[0] == 'E') {
         prsn =  new Employee(in);
      }
      else if (tag[0] == 's' || tag[0] == 'S')
      {
         prsn = new Student(in);
      }
      else if (tag[0] == 'p' || tag[0] == 'P') {
         prsn = new Professor(in);
      }
      else
      {
         prsn = nullptr;
      }

      return prsn;
   }
}
