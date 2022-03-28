#ifndef __SHRUBBERYCREATIONFORM_H__
#define __SHRUBBERYCREATIONFORM_H__

#include "Form.hpp"

class ShrubberyCreationForm : public Form {
 private:
  // Disabled Operators
  ShrubberyCreationForm& operator=(const ShrubberyCreationForm& assign);

 public:
  enum Requirement { SIGN = 145, EXEC = 137 };
  // Constructors & Destructor
  ShrubberyCreationForm(const string& target);
  ShrubberyCreationForm(const ShrubberyCreationForm& other);
  ~ShrubberyCreationForm();

  // Overrided Abstract Methods
  void formAction() const;
};

#endif  // __SHRUBBERYCREATIONFORM_H__
