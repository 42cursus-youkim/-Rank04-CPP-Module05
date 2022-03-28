#ifndef __ROBOTOMYREQUESTFORM_H__
#define __ROBOTOMYREQUESTFORM_H__

#include "Form.hpp"

class RobotomyRequestForm : public Form {
 private:
  enum Requirement { SIGN = 72, EXEC = 45 };

 public:
  // Constructors & Destructor
  RobotomyRequestForm(const string& target);
  RobotomyRequestForm(const RobotomyRequestForm& other);
  ~RobotomyRequestForm();
  // Operators
  RobotomyRequestForm& operator=(const RobotomyRequestForm& assign);

  // Overrided Abstract Methods
  void formAction() const;
};

#endif  // __ROBOTOMYREQUESTFORM_H__