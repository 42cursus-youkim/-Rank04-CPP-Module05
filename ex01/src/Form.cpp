#include "Form.hpp"
#include "Bureaucrat.hpp"

#include <iostream>
#include <string>
#include "Form.hpp"
#include "color.hpp"
#include "util.hpp"
using std::string;

// Protected method
void Form::validateGradeInRange(int grade) const {
  if (grade > Form::LOWEST_GRADE) {
    throw Form::GradeTooLowException();
  }
  if (grade < Form::HIGHEST_GRADE)
    throw Form::GradeTooHighException();
}

// Constructors & Destructor
Form::Form(const string& name, int execGrade, int signGrade)
    : _name(name),
      _executionRequiredGrade(static_cast<int>(execGrade)),
      _signRequiredGrade(static_cast<int>(signGrade)),
      _isSigned(false) {
  validateGradeInRange(signGrade);
  validateGradeInRange(execGrade);
}

Form::Form(const Form& other)
    : _name(other._name),
      _executionRequiredGrade(other._executionRequiredGrade),
      _signRequiredGrade(other._signRequiredGrade),
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

// Methods
void Form::beSigned(const Bureaucrat& bureaucrat) {
  if (bureaucrat.getGrade() > _signRequiredGrade)
    throw Form::GradeTooLowException();
  _isSigned = true;
}

std::ostream& operator<<(std::ostream& os, const Form& f) {
  os << f.getName()
     << fractionInParens(f.getExecutionRequiredGrade(),
                         f.getSignRequiredGrade())
     << " " << colorBool(f.getIsSigned(), "signed", "unsigned") << END;
  return os;
}

// Exceptions
const char* Form::GradeTooHighException::what() const throw() {
  return "Grade too high";
}

const char* Form::GradeTooLowException::what() const throw() {
  return "Grade too low";
}