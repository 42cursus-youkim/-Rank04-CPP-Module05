#ifndef __UTIL_H__
#define __UTIL_H__

#include <string>

using std::string;

string colorBool(bool b);
string inParens(size_t value);
string fractionInParens(size_t grade, size_t lowest);

#endif  // __UTIL_H__