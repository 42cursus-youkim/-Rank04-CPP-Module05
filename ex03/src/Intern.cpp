#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

Intern::Intern() {}
Intern::~Intern() {}

// Factory
static Form* createShrubberyCreationForm(const string& target) {
  return new ShrubberyCreationForm(target);
}
static Form* createRobotomyRequestForm(const string& target) {
  return new RobotomyRequestForm(target);
}
static Form* createPresidentialPardonForm(const string& target) {
  return new PresidentialPardonForm(target);
}

Form* Intern::makeForm(const string& formType, const string& target) const {
  typedef Form* (*FormFactory)(const string& target);
  FormFactory factory[] = {createShrubberyCreationForm,
                           createRobotomyRequestForm,
                           createPresidentialPardonForm};

  for (int i = 0; i < 3; i++)
    if (g_formTypes[i] == formType)
      return factory[i](target);
  throw FormNotFoundException();
}
// Exceptions
const char* Intern::FormNotFoundException::what() const throw() {
  return "No such form";
}
