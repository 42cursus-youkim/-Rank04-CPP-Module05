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

// Overrided Abstract Methods
static bool randHalf() {
  return rand() % 2;
}

void RobotomyRequestForm::formAction() const {
  cout << HYEL "Haha drill goes brrrrrrrrrrrrrrrrrr\n";
  cout << CYN << "robotomy for subject " BCYN << Form::getTarget() << " ";
  if (randHalf()) {
    cout << HGRN "is successful.\n" END;
  } else
    cout << HRED "failed.\n";
}
