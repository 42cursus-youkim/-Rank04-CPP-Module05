#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "color.hpp"

using std::cout;

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
void Bureaucrat::increaseGrade(size_t amount) {
  if (_grade < amount + HIGHEST_GRADE)
    throw Bureaucrat::GradeTooHighException();
  _grade -= amount;
}

void Bureaucrat::decreaseGrade(size_t amount) {
  if (_grade + amount > LOWEST_GRADE)
    throw Bureaucrat::GradeTooLowException();
  _grade += amount;
}

bool Bureaucrat::signForm(Form& form) {
  try {
    form.beSigned(*this);
    cout << CYN << getName() << " signed " << form.getName();
  } catch (const std::exception& e) {
    cout << HRED << getName() << " couldn't sign " CYN << form.getName()
         << HRED " because: " << e.what();
  }
  cout << "\n" END;
  return form.getIsSigned();
}

bool Bureaucrat::executeForm(const Form& form) {
  try {
    form.execute(*this);
    cout << CYN << getName() << " executed " << form.getName();
  } catch (const std::exception& e) {
    cout << HRED << getName() << " couldn't execute " CYN << form.getName()
         << HRED " because: " << e.what();
  }
  cout << "\n" END;
  return form.getIsSigned();
}

// Overloaded << operator
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
  return "Grade too low";
}