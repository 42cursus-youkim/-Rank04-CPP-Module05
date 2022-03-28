#ifndef __PRESIDENTIALPARDONFORM_H__
#define __PRESIDENTIALPARDONFORM_H__

#include "Form.hpp"
class PresidentialPardonForm : public Form {
 private:
  // Disabled Operators
  PresidentialPardonForm& operator=(const PresidentialPardonForm& assign);

 public:
  enum Requirement { SIGN = 25, EXEC = 5 };
  // Constructors & Destructor
  PresidentialPardonForm(const string& target);
  PresidentialPardonForm(const PresidentialPardonForm& other);
  ~PresidentialPardonForm();

  // Overrided Abstract Methods
  void formAction() const;
  // create new PresidentialPardonForm
};

#endif  // __PRESIDENTIALPARDONFORM_H__