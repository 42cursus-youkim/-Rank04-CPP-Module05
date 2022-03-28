#include <iostream>
#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "color.hpp"
#include "util.hpp"

using std::cerr;
using std::cout;
using std::string;

int main() {
  // Try instantiating, it's abstract so you don't
  // Form form("trivialForm", 80, 100);
  Bureaucrat highOfficial("highOfficial", Form::HIGHEST_GRADE);
  PresidentialPardonForm pardonForm("Arthur Dent");
  highOfficial.signForm(pardonForm);
  highOfficial.executeForm(pardonForm);
  return 0;
}