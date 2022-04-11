#include "PresidentialPardonForm.hpp"
#include <iostream>
#include "color.hpp"

using std::cout;

// Constructors & Destructor
PresidentialPardonForm::PresidentialPardonForm(const string& target)
    : Form("Presidential Pardon Form",
           target,
           PresidentialPardonForm::EXEC,
           PresidentialPardonForm::SIGN) {}

PresidentialPardonForm::PresidentialPardonForm(
    const PresidentialPardonForm& other)
    : Form(other.getName(),
           other.getTarget(),
           PresidentialPardonForm::EXEC,
           PresidentialPardonForm::SIGN) {}

PresidentialPardonForm::~PresidentialPardonForm() {}

// Overrided Abstract Methods
void PresidentialPardonForm::formAction() const {
  cout << BCYN << Form::getTarget()
       << GRN " is hereby pardoned by the Galactic President " BBLU
              "-*- Zaphod Beeblebrox -*-\n";
}
