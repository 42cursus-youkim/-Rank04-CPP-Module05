#ifndef __ROBOTOMYREQUESTFORM_H__
#define __ROBOTOMYREQUESTFORM_H__

#include "Form.hpp"

class RobotomyRequestForm {
 private:
  enum Requirement { SIGN = 72, EXEC = 45 };

 public:
  // Constructors & Destructor
  RobotomyRequestForm(const string& target);
  RobotomyRequestForm(const RobotomyRequestForm& other);
  ~RobotomyRequestForm();
  // Operators
  RobotomyRequestForm& operator=(const RobotomyRequestForm& assign);

  // Overrided Virtual Methods
  void formAction() const;
};

#endif  // __ROBOTOMYREQUESTFORM_H__