#include "Bureaucrat.hpp"

// Constructors
Bureaucrat::Bureaucrat(const string name, size_t grade)
    : _name(name), _grade(grade) {
  if (grade > 150)
    throw Bureaucrat::GradeTooHighException();
  if (grade < 1)
    throw Bureaucrat::GradeTooLowException();
}

Bureaucrat::Bureaucrat(const Bureaucrat& copy)
    : _name(copy._name), _grade(copy._grade) {}

// Destructor
Bureaucrat::~Bureaucrat() {}

// Operators
Bureaucrat& Bureaucrat::operator=(const Bureaucrat& assign) {
  _grade = assign.getGrade();
  return *this;
}

// Getters / Setters
const string Bureaucrat::getName() const {
  return _name;
}

size_t Bureaucrat::getGrade() const {
  return _grade;
}

// Methods
void Bureaucrat::increaseGrade() throw() {
  if (_grade <= 1)
    throw Bureaucrat::GradeTooLowException();
  _grade--;
}

void Bureaucrat::decreaseGrade() {
  if (_grade >= 150)
    throw Bureaucrat::GradeTooHighException();
  _grade++;
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& b) {
  os << b.getName() << "::grade " << b.getGrade();
  return os;
}

// Exceptions
// const char* Bureaucrat::GradeTooHighException::what() const throw() {
//   return "grades cannot be higher than 1";
// }
// const char* Bureaucrat::GradeTooLowException::what() const throw() {
//   return "grades cannot be lower than 150";
// }
