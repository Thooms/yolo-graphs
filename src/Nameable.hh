
#ifndef NAMEABLE_HH
#define NAMEABLE_HH

#include <string>

class Nameable {
  
  explicit Nameable() {};

private:
  std::string name;

public:
  std::string getName(void);
  void setName(std::string&);

};

#endif
