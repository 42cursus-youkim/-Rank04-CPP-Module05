#include <iostream>
#include "Bureaucrat.hpp"
#include "color.hpp"
#include "util.hpp"

using std::cerr;
using std::cout;
using std::string;

void printResponsibleBurger(Bureaucrat& b) {
  cout << HYEL "[[Bureaucrat " BYEL << b << HYEL " is responsible]]\n" END;
}

void signForms(Bureaucrat& b, Form& form) {
  Form previous = form;

  b.signForm(form);
  cout << previous << " => " << form << "\n\n";
}

void testInvalidForm(int execGrade, int signGrade) {
  try {
    Form f("Test", execGrade, signGrade);
    cout << "Form " << f << " created\n";
  } catch (const std::exception& e) {
    cout << "Form creation failed: " << e.what() << "\n";
  }
}

void testFailedForm() {
  cout << HYEL "[[Creating failed forms]]\n" END;
  int cases[][2] = {
      {Form::LOWEST_GRADE + 1, 11},
      {100, 200},
      {Form::HIGHEST_GRADE - 1, 11},
      {-10, 100},
  };
  for (size_t i = 0; i < sizeof(cases) / sizeof(cases[0]); i++)
    testInvalidForm(cases[i][0], cases[i][1]);
  cout << "\n";
}

void testFormActions() {
  Bureaucrat bureaucrats[] = {Bureaucrat("lowRANK", 100),
                              Bureaucrat("midRANK", 50),
                              Bureaucrat("highRANK", 1)};

  for (int i = 0; i < 3; i++) {
    Form forms[] = {Form("trivialForm", 80, 100), Form("ImportantForm", 30, 50),
                    Form("advancedForm", 5, 10)};
    Bureaucrat bureaucrat = bureaucrats[i];
    printResponsibleBurger(bureaucrat);
    for (int j = 0; j < 3; j++)
      signForms(bureaucrat, forms[j]);
  }
}

int main() {
  testFailedForm();
  testFormActions();
}