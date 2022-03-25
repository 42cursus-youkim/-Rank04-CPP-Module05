#include "util.hpp"
#include <sstream>
#include "color.hpp"

// helper function
string colorBool(bool b, string trueValue, string falseValue) {
  return string(b ? BHGRN : BHRED) + (b ? trueValue : falseValue) + END;
}

string inParens(size_t value) {
  std::stringstream ss;
  ss << CYN "(" << value << ")" END;
  return ss.str();
}

string inParens(string value) {
  std::stringstream ss;
  ss << CYN "(" << value << ")" END;
  return ss.str();
}

string fractionInParens(size_t num, size_t denom) {
  std::stringstream ss;

  ss << CYN "(" << num << "/" << denom << ")" END;
  return ss.str();
}