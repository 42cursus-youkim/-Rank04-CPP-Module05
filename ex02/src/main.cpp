#include <cstdlib>
#include <iostream>
#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "color.hpp"
#include "util.hpp"

using std::cerr;
using std::cout;
using std::string;

// Haha, this is global and you can do nothing to prevent this
Bureaucrat canExecAllOfficial("canExecAllOfficial", Form::HIGHEST_GRADE);
Bureaucrat cantExecPardonOfficial("can'tExecPardonOfficial",
                                  PresidentialPardonForm::EXEC + 10);
Bureaucrat cantSignPardonOfficial("can'tSignPardonOfficial",
                                  PresidentialPardonForm::SIGN + 10);
Bureaucrat cantExecRobotomyOfficial("can'tExecRobotomyOfficial",
                                    RobotomyRequestForm::EXEC + 10);
Bureaucrat cantSignRobotomyOfficial("can'tSignRobotomyOfficial",
                                    RobotomyRequestForm::SIGN + 10);
Bureaucrat cantExecShrubberyOfficial("can'tExecShrubberyOfficial",
                                     ShrubberyCreationForm::EXEC + 10);
Bureaucrat cantSignShrubberyOfficial("can'tSignShrubberyOfficial",
                                     ShrubberyCreationForm::SIGN + 5);
Bureaucrat* officialPtr[7] = {
    &canExecAllOfficial,       &cantExecPardonOfficial,
    &cantSignPardonOfficial,   &cantExecRobotomyOfficial,
    &cantSignRobotomyOfficial, &cantExecShrubberyOfficial,
    &cantSignShrubberyOfficial};

void printResponsibleOfficial(Bureaucrat& b) {
  cout << HYEL "[[Bureaucrat " BCYN << b << HYEL " is responsible]]\n" END;
}

void printTestHeader(const string& what) {
  cout << HCYN << string(18, '=') << BHYEL << " " << what << " " << HCYN
       << string(18, '=') << "\n\n";
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

void testSimple() {
  printTestHeader("One official to do everything");
  for (int i = 0; i < 7; i++) {
    // Hence tests are atomic
    PresidentialPardonForm pardonForm("Arthur Dent");
    RobotomyRequestForm robotomyForm("Ford Prefect");
    ShrubberyCreationForm shrubberyForm("Trillian");
    Form* formsPtr[3] = {&pardonForm, &robotomyForm, &shrubberyForm};

    Bureaucrat& official = *officialPtr[i];
    printResponsibleOfficial(official);
    testAllForm(official, formsPtr);
  }
}

void testPeakBureaucracy() {
  PresidentialPardonForm pardonForm("Arthur Dent");
  RobotomyRequestForm robotomyForm("Ford Prefect");
  ShrubberyCreationForm shrubberyForm("Trillian");
  Form* formsPtr[3] = {&pardonForm, &robotomyForm, &shrubberyForm};

  printTestHeader("Peak Bureaucracy: Now in reverse!");
  for (int i = 6; i >= 0; i--) {
    Bureaucrat& official = *officialPtr[i];
    printResponsibleOfficial(official);
    testAllForm(official, formsPtr);
  }
}

int main() {
  srand(time(NULL) % 4587915786);
  // testSimple();
  testPeakBureaucracy();

  // Try instantiating, it's abstract so you don't
  // Form form("trivialForm", 80, 100);

  return 0;
}