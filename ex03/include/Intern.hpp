#ifndef __INTERN_H__
#define __INTERN_H__

#include <string>
#include "Form.hpp"

using std::string;

const string g_formTypes[] = {"shrubbery creation", "robotomy request",
                            "presidential pardon"};

class Intern {
 private:
  // Disabled Constructor
  Intern(const Intern& other);
  // Disabled Operators
  Intern& operator=(const Intern& assign);

 public:
  // Constructors & Destructor
  Intern();
  ~Intern();

  // Methods
  Form* makeForm(const string& formType, const string& target) const;

  // Exceptions
  class FormNotFoundException;
};

class Intern::FormNotFoundException : public std::exception {
 public:
  virtual const char* what() const throw();
};

#endif  // __INTERN_H__