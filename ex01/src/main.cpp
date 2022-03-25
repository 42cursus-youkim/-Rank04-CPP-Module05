#include <iostream>
#include "Bureaucrat.hpp"
#include "color.hpp"
#include "util.hpp"
using std::cerr;
using std::cout;
using std::string;

void testHeader(const string& header,
                size_t initialExecGrade,
                size_t initialSignGrade) {
  cout << HYEL "[[Testing " << header << " "
       << fractionInParens(initialExecGrade, initialSignGrade) << HYEL
       << "]]\n" END;
}

int main() {
  testHeader("Form", 1, 10);
}