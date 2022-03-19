#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <exception>
#include <iostream>
#include <string>

using std::string;

class Bureaucrat {
 private:
  const string _name;
  size_t _grade;

  Bureaucrat();

 public:
  // Constructors
  Bureaucrat(const Bureaucrat& copy);
  Bureaucrat(const string name, size_t grade);

  // Destructor
  ~Bureaucrat();

  // Operators
  Bureaucrat& operator=(const Bureaucrat& assign);

  // Getters / Setters
  const string getName() const;
  size_t getGrade() const;

  // Methods
  void increaseGrade();
  void decreaseGrade();

  // Exceptions
  class GradeTooHighException;
  class GradeTooLowException;
};

class GradeTooHighException : public std::exception {
 public:
  virtual const char* what() const throw();
};

class Bureaucrat::GradeTooLowException : public std::exception {
 public:
  virtual const char* what() const throw();
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& b);

#endif