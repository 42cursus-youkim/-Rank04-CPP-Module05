#ifndef __FORM_H__
#define __FORM_H__

#include <string>

using std::string;

class Bureaucrat;

class Form {
 private:
  const string _name;
  const string _target;
  const size_t _executionRequiredGrade;
  const size_t _signRequiredGrade;
  bool _isSigned;

  // Disabled Constructor
  Form();
  // Disabled Operators
  Form& operator=(const Form& assign);

 protected:
  // Methods
  void validateGradeInRange(int grade) const;
  bool canBeSignedBy(const Bureaucrat& bureaucrat) const;
  bool canBeExecutedBy(const Bureaucrat& bureaucrat) const;

 public:
  enum FormGradeRange { HIGHEST_GRADE = 1, LOWEST_GRADE = 150 };
  // Constructors & Destructor
  Form(const string& name, const string& target, int execGrade, int signGrade);
  Form(const Form& other);
  virtual ~Form();

  // Getters
  const string& getName() const;
  const string& getTarget() const;
  size_t getSignRequiredGrade() const;
  size_t getExecutionRequiredGrade() const;
  bool getIsSigned() const;

  // Methods
  void beSigned(const Bureaucrat& bureaucrat);
  void execute(Bureaucrat const& executor) const;
  virtual void formAction() const = 0;

  // Exceptions
  class GradeTooHighException;
  class GradeTooLowException;
  class FormNotSignedException;
};

class Form::GradeTooHighException : public std::exception {
 public:
  virtual const char* what() const throw();
};

class Form::GradeTooLowException : public std::exception {
 public:
  virtual const char* what() const throw();
};

class Form::FormNotSignedException : public std::exception {
 public:
  virtual const char* what() const throw();
};

std::ostream& operator<<(std::ostream& os, const Form& f);

#endif  // __FORM_H__