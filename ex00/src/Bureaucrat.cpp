#include "Bureaucrat.hpp"

// Constructors
Bureaucrat::Bureaucrat(const string name, size_t grade)
    : _name(name), _grade(grade) {
  if (grade > LOWEST_GRADE)
    throw Bureaucrat::GradeTooLowException();
  if (grade < HIGHEST_GRADE)
    throw Bureaucrat::GradeTooHighException();
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
void Bureaucrat::increaseGrade(int amount) {
  _grade -= amount;
  if (_grade < HIGHEST_GRADE)
    throw Bureaucrat::GradeTooHighException();
}

void Bureaucrat::decreaseGrade(int amount) {
  _grade += amount;
  if (_grade > LOWEST_GRADE)
    throw Bureaucrat::GradeTooLowException();
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& b) {
  os << b.getName() << "::grade " << b.getGrade() << "/"
     << Bureaucrat::LOWEST_GRADE;
  return os;
}

// Exceptions
const char* Bureaucrat::GradeTooHighException::what() const throw() {
  return "Grade is too high";
}

const char* Bureaucrat::GradeTooLowException::what() const throw() {
  return "Grade is too low";
}