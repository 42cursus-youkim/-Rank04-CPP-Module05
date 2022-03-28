#include "Form.hpp"
#include "Bureaucrat.hpp"

#include <iostream>
#include <string>
#include "Form.hpp"
#include "color.hpp"
#include "util.hpp"
using std::string;

// Constructors & Destructor
Form::Form(const string& name,
           const string& target,
           int execGrade,
           int signGrade)
    : _name(name),
      _target(target),
      _executionRequiredGrade(static_cast<int>(execGrade)),
      _signRequiredGrade(static_cast<int>(signGrade)),
      _isSigned(false) {
  validateGradeInRange(signGrade);
  validateGradeInRange(execGrade);
}

Form::Form(const Form& other)
    : _name(other.getName()),
      _target(other.getTarget()),
      _executionRequiredGrade(other.getSignRequiredGrade()),
      _signRequiredGrade(other.getExecutionRequiredGrade()),
      _isSigned(other.getIsSigned()) {}

Form::~Form() {}

// Getters
const string& Form::getName() const {
  return _name;
}
const string& Form::getTarget() const {
  return _target;
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

// Protected method
void Form::validateGradeInRange(int grade) const {
  if (grade > Form::LOWEST_GRADE) {
    throw Form::GradeTooLowException();
  }
  if (grade < Form::HIGHEST_GRADE)
    throw Form::GradeTooHighException();
}

bool Form::canBeSignedBy(const Bureaucrat& bureaucrat) const {
  return (bureaucrat.getGrade() <= _signRequiredGrade);
}

bool Form::canBeExecutedBy(const Bureaucrat& bureaucrat) const {
  return (bureaucrat.getGrade() <= _executionRequiredGrade);
}

// Methods
void Form::beSigned(const Bureaucrat& bureaucrat) {
  if (not canBeSignedBy(bureaucrat))
    throw Form::GradeTooLowException();
  _isSigned = true;
}

void Form::execute(Bureaucrat const& executor) const {
  if (not _isSigned)
    throw Form::FormNotSignedException();
  if (not canBeExecutedBy(executor))
    throw Form::GradeTooLowException();
  formAction();
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

const char* Form::FormNotSignedException::what() const throw() {
  return "Unsigned forms cannot be executed";
}