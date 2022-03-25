#include "Bureaucrat.hpp"

// Constructors
Bureaucrat::Bureaucrat(const string& name, int grade)
    : _name(name), _grade(static_cast<size_t>(grade)) {
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
  if (this != &assign)
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
  if (_grade < static_cast<size_t>(amount) + HIGHEST_GRADE)
    throw Bureaucrat::GradeTooHighException();
  _grade -= amount;
}

void Bureaucrat::decreaseGrade(int amount) {
  if (_grade + amount > LOWEST_GRADE)
    throw Bureaucrat::GradeTooLowException();
  _grade += amount;
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& b) {
  os << b.getName() << "::grade " << b.getGrade() << "/"
     << Bureaucrat::LOWEST_GRADE;
  return os;
}

// Exceptions
const char* Bureaucrat::GradeTooHighException::what() const throw() {
  return "Grade too high";
}

const char* Bureaucrat::GradeTooLowException::what() const throw() {
  return "Grade is too low";
}