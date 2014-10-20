
#include <string>

#include "Nameable.hh"

using namespace std;

ostream& operator<<(ostream& out, Nameable& n) {
  out << n.name();
  return out;
}

string Nameable::name(void) {
  return name_;
}

void Nameable::setName(string& s) {
  name_ = s;
}
