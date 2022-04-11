#include "ShrubberyCreationForm.hpp"
#include <fstream>
#include <iostream>
#include <stdexcept>
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
  const string assetfile = "asset/shrubbery.txt";
  const string targetfile = Form::getTarget() + "_shrubbery";

  std::ifstream in(assetfile.c_str());
  std::ofstream out(targetfile.c_str(), std::ios::app);

  in.exceptions(std::ifstream::badbit);
  out.exceptions(std::ofstream::failbit | std::ofstream::badbit);

  string line;
  while (std::getline(in, line)) {
    out << line << "\n";
  }
}
