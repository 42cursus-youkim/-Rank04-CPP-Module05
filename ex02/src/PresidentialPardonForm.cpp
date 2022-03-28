#include "PresidentialPardonForm.hpp"
#include <iostream>
#include "color.hpp"

using std::cout;

// Constructors & Destructor
PresidentialPardonForm::PresidentialPardonForm(const string& target)
    : Form("Presidential Pardon Form",
           target,
           PresidentialPardonForm::SIGN,
           PresidentialPardonForm::EXEC) {}

PresidentialPardonForm::PresidentialPardonForm(
    const PresidentialPardonForm& other)
    : Form(other.getName(),
           other.getTarget(),
           PresidentialPardonForm::SIGN,
           PresidentialPardonForm::EXEC) {}

PresidentialPardonForm::~PresidentialPardonForm() {}

// Operators
PresidentialPardonForm& PresidentialPardonForm::operator=(
    const PresidentialPardonForm& assign) {
  Form::operator=(assign);
  return *this;
}

// Overrided Abstract Methods
void PresidentialPardonForm::formAction() const {
  cout << CYN << Form::getTarget()
       << HGRN " is hereby pardoned by the President " BBLU
               "-*- Zaphod Beeblebrox -*-\n";
}