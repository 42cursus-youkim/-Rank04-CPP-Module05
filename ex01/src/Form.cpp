#include "Form.hpp"

#include <iostream>
#include <string>
#include "color.hpp"
#include "util.hpp"

using std::string;

// Protected method
void Form::validateGradeInRange(int grade) const {
  if (grade >= Form::HIGHEST_GRADE)
    throw Form::GradeTooHighException();
  if (grade <= Form::LOWEST_GRADE)
    throw Form::GradeTooLowException();
}

// Constructors & Destructor
Form::Form(const string& name, int signGrade, int execGrade)
    : _name(name),
      _signRequiredGrade(static_cast<int>(signGrade)),
      _executionRequiredGrade(static_cast<int>(execGrade)),
      _isSigned(false) {
  validateGradeInRange(signGrade);
}

Form::Form(const Form& other)
    : _name(other._name),
      _signRequiredGrade(other._signRequiredGrade),
      _executionRequiredGrade(other._executionRequiredGrade),
      _isSigned(other._isSigned) {}

Form::~Form() {}

// Getters
const string& Form::getName() const {
  return _name;
}

size_t Form::getSignRequiredGrade() const {
  return _signRequiredGrade;
}

size_t Form::getExecutionRequiredGrade() const {
  return _executionRequiredGrade;
}

bool Form::getIsSigned() const {
  return _isSigned;
}

std::ostream& operator<<(std::ostream& os, const Form& f) {
  os << f.getName()
     //  << gradeInParens(f.getSignRequiredGrade(), Form::LOWEST_GRADE) << " "
     //  << gradeInParens(f.getExecutionRequiredGrade(), Form::LOWEST_GRADE)
     << " signed: " << colorBool(f.getIsSigned()) << END;
  return os;
}

// Exceptions
const char* Form::GradeTooHighException::what() const throw() {
  return "Grade too high";
}

const char* Form::GradeTooLowException::what() const throw() {
  return "Grade is too low";
}