#include "util.hpp"
#include <sstream>
#include "color.hpp"

// helper function
string colorBool(bool b) {
  return string(b ? GRN "true" : RED "false") + END;
}

string inParens(size_t value) {
  std::stringstream ss;
  ss << CYN "(" << value << ")" END;
  return ss.str();
}

string fractionInParens(size_t num, size_t denom) {
  std::stringstream ss;

  ss << CYN "(" << num << "/" << denom << ")" END;
  return ss.str();
}