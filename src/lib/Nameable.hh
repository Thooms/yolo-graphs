
#ifndef NAMEABLE_HH
#define NAMEABLE_HH

#include <iostream>
#include <string>

using namespace std;

class Nameable {
  friend ostream& operator<<(ostream& out, Nameable& n);

private:
  string name_;

public:

  explicit Nameable() {}

  string name(void);
  void setName(string&);
};

#endif
