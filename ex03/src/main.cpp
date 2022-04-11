#include <cstdlib>
#include <iostream>
#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "color.hpp"

using std::cerr;
using std::cout;
using std::string;

void printResponsibleOfficial(Bureaucrat& b) {
  cout << HYEL "[[Bureaucrat " BCYN << b << HYEL " is responsible]]\n" END;
}

void printTestHeader(const string& what) {
  const int len = (80 - (what.length() + 4)) / 2;
  if (len < 1)
    throw std::length_error("printTestHeader: len < 1");
  cout << HCYN << string(len, '=') << BHYEL << " " << what << " " << HCYN
       << string(len, '=') << "\n\n";
}

void testAllForm(Bureaucrat& official, Form* formsPtr[3]) {
  for (int i = 0; i < 3; i++) {
    Form& form = *formsPtr[i];
    official.signForm(form);
    official.executeForm(form);
    cout << "\n";
  }
  cout << BYEL << string(80, '=') << "\n\n";
}

const string randomName() {
  const string names[] = {"Arthur Dent", "Ford Prefect",   "Zaphod Beeblebrox",
                          "Marvin",      "Slartibartfast", "Trillian"};
  return names[rand() % 6];
}

void testOverWork(Bureaucrat& official, Intern& intern) {
  printTestHeader(official.getName() + " has passed away from overwork");

  Form* formsPtr[3];
  for (int i = 0; i < 3; i++)
    formsPtr[i] = intern.makeForm(g_formTypes[i], randomName());

  printResponsibleOfficial(official);
  testAllForm(official, formsPtr);
  for (int i = 0; i < 3; i++)
    delete formsPtr[i];
}

void testWrongForm(Intern& intern) {
  printTestHeader("What is this, a form for ants?");

  if (intern.makeForm("WrongForm", randomName()) != NULL)
    throw std::exception();
}

int main() {
  Intern someRandomIntern;
  Bureaucrat canExecAllOfficial("canExecAllOfficial", Form::HIGHEST_GRADE);

  srand(time(NULL) % 4587915786);
  testOverWork(canExecAllOfficial, someRandomIntern);
  testWrongForm(someRandomIntern);
  return 0;
}
