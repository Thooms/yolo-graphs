
#include <string>

#include "Nameable.hh"

using namespace std;

Nameable::getName(void) {
  return name;
}

Nameable::setName(string& s) {
  name = s;
}
