#include "ShrubberyCreationForm.hpp"
#include <iostream>
#include "color.hpp"

using std::cout;

// Constructors & Destructor
ShrubberyCreationForm::ShrubberyCreationForm(const string& target)
    : Form("ShrubberyCreationForm",
           target,
           ShrubberyCreationForm::SIGN,
           ShrubberyCreationForm::EXEC) {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other)
    : Form(other.getName(),
           other.getTarget(),
           ShrubberyCreationForm::SIGN,
           ShrubberyCreationForm::EXEC) {}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

// Overrided Abstract Methods
void ShrubberyCreationForm::formAction() const {
  cout << "TODO: implement ShrubberyCreationForm::formAction\n";
}