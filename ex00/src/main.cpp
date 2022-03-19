#include <iostream>
#include "Bureaucrat.hpp"

using std::cerr;
using std::cout;
int main() {
  cout << "[[Testing Grade Increase]]\n";
  try {
    Bureaucrat successPerson("some person", 30);
    cout << successPerson << std::endl;
    successPerson.increaseGrade(10);
    cout << successPerson << std::endl;
  } catch (std::exception& e) {
    cerr << e.what() << std::endl;
  }
  cout << "[[Testing Grade Decrease]]\n";
  try {
    Bureaucrat failPerson("some person", 120);
    cout << failPerson << std::endl;
    failPerson.decreaseGrade(10);
    cout << failPerson << std::endl;
  } catch (std::exception& e) {
    cerr << e.what() << std::endl;
  }
  cout << "[[Testing Grade too high]]\n";
  try {
    Bureaucrat person("good grade person", 1);
    cout << person << std::endl;
    person.increaseGrade(1);
  } catch (std::exception& e) {
    std::cerr << e.what() << std::endl;
  }
  try {
    Bureaucrat person2("goodest grade person", 0);
    cout << person2 << std::endl;
  } catch (std::exception& e) {
    std::cerr << e.what() << std::endl;
  }
  cout << "[[Testing Grade too low]]\n";
  try {
    Bureaucrat person3("low grade person", 150);
    cout << person3 << std::endl;
    person3.decreaseGrade(1);
  } catch (std::exception& e) {
    std::cerr << e.what() << std::endl;
  }
  try {
    Bureaucrat person4("lowest grade person", 151);
    cout << person4 << std::endl;
  } catch (std::exception& e) {
    std::cerr << e.what() << std::endl;
  }
}