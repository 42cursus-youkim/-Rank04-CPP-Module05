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

  // Disabled Constructor
  Bureaucrat();

 public:
  enum BureaucratGradeRange { HIGHEST_GRADE = 1, LOWEST_GRADE = 150 };

  // Constructors & Destructor
  Bureaucrat(const string& name, int grade);
  Bureaucrat(const Bureaucrat& copy);
  ~Bureaucrat();

  // Operators
  Bureaucrat& operator=(const Bureaucrat& assign);

  // Getters / Setters
  const string getName() const;
  size_t getGrade() const;

  // Methods
  void increaseGrade(size_t amount);
  void decreaseGrade(size_t amount);

  // Exceptions
  class GradeTooHighException;
  class GradeTooLowException;
};

class Bureaucrat::GradeTooHighException : public std::exception {
 public:
  virtual const char* what() const throw();
};

class Bureaucrat::GradeTooLowException : public std::exception {
 public:
  virtual const char* what() const throw();
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& b);

#endif
