
#ifndef NAMEABLE_HH
#define NAMEABLE_HH

#include <string>

class Nameable {
private:
  std::string name_;

public:

  explicit Nameable() {};

  std::string name(void);
  void setName(std::string&);

};

#endif
