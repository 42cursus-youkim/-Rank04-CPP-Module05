#include "Intern.hpp"
#include <iostream>
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "color.hpp"

using std::cout;

Intern::Intern() {}
Intern::~Intern() {}

// Factory
Form* Intern::createShrubberyCreationForm(const string& target) const {
  return new ShrubberyCreationForm(target);
}
Form* Intern::createRobotomyRequestForm(const string& target) const {
  return new RobotomyRequestForm(target);
}
Form* Intern::createPresidentialPardonForm(const string& target) const {
  return new PresidentialPardonForm(target);
}

Form* Intern::makeForm(const string& formType, const string& target) const {
  // typedef FormFactory
  typedef Form* (Intern::*FormFactory)(const string&) const;
  FormFactory factory[] = {&Intern::createShrubberyCreationForm,
                           &Intern::createRobotomyRequestForm,
                           &Intern::createPresidentialPardonForm};

  for (int i = 0; i < 3; i++)
    if (g_formTypes[i] == formType)
      return (this->*factory[i])(target);
  cout << RED "Intern says there's no such form!\n" END;
  return NULL;
}
