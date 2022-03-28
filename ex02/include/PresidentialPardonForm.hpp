#ifndef __PRESIDENTIALPARDONFORM_H__
#define __PRESIDENTIALPARDONFORM_H__

#include "Form.hpp"
class PresidentialPardonForm : public Form {
 private:
  enum Requirement { SIGN = 25, EXEC = 5 };

 public:
  // Constructors & Destructor
  PresidentialPardonForm(const string& target);
  PresidentialPardonForm(const PresidentialPardonForm& other);
  ~PresidentialPardonForm();

  // Operators
  PresidentialPardonForm& operator=(const PresidentialPardonForm& assign);

  // Overrided Abstract Methods
  void formAction() const;
};

#endif  // __PRESIDENTIALPARDONFORM_H__