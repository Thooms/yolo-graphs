
#ifndef NAMEABLE_HH
#define NAMEABLE_HH

#include <string>

class Nameable {
  
  explicit Nameable() {};

private:
  std::string name_;

public:
  std::string name(void);
  void setName(std::string&);

};

#endif
