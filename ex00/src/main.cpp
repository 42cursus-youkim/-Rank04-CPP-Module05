#include "Bureaucrat.hpp"
#include <iostream>

using std::cerr;
using std::cout;
int main() {
  Bureaucrat guy("some guy", 1);

  try {
    guy.increaseGrade(1);
  } catch (Bureaucrat::GradeTooHighException& e) {
    std::cerr << e.what() << std::endl;
  }
  cout << "Testing Grade too low\n";
  try {
    Bureaucrat guy2("some guy", 151);
  } catch (Bureaucrat::GradeTooHighException& e) {
    std::cerr << e.what() << std::endl;
  }
  cout << "Testing Grade too high\n";
  try {
    Bureaucrat guy2("some guy", 0);
  } catch (Bureaucrat::GradeTooLowException& e) {
    std::cerr << e.what() << std::endl;
  }
}