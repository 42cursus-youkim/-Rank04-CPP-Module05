#include "RobotomyRequestForm.hpp"
#include <cstdlib>
#include <iostream>
#include "color.hpp"

using std::cout;

// Constructors & Destructor
RobotomyRequestForm::RobotomyRequestForm(const string& target)
    : Form("RobotomyRequestForm",
           target,
           RobotomyRequestForm::SIGN,
           RobotomyRequestForm::EXEC) {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other)
    : Form(other.getName(),
           other.getTarget(),
           RobotomyRequestForm::SIGN,
           RobotomyRequestForm::EXEC) {}

RobotomyRequestForm::~RobotomyRequestForm() {}

// Operators
RobotomyRequestForm& RobotomyRequestForm::operator=(
    const RobotomyRequestForm& assign) {
  Form::operator=(assign);
  return *this;
}

// Overrided Abstract Methods
static bool randHalf() {
  return rand() % 2;
}

void RobotomyRequestForm::formAction() const {
  if (randHalf())
    cout << CYN << Form::getTarget()
         << HGRN " has been robotomized successfully.\n";
  else
    cout << CYN << "robotomy for subject " << Form::getTarget()
         << HRED "failed.\n";
}