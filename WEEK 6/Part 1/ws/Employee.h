// Employee.h
#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include "Person.h"
#include <iostream>
#include <string>

namespace seneca {

   class Employee : public Person {
   private:
      std::string m_name;
      int m_age;
      std::string m_id;

   public:
      Employee(std::istream& is);
      std::string status() const override;
      std::string name() const override;
      std::string id() const override;
      std::string age() const override;
      void display(std::ostream& out) const override;
   };
}

#endif // EMPLOYEE_H
