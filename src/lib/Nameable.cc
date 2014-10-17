
#include <string>

#include "Nameable.hh"

using namespace std;

string Nameable::name(void) {
  return name_;
}

void Nameable::setName(string& s) {
  name_ = s;
}
