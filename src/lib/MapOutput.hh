
#ifndef MAPOUTPUT_HH
#define MAPOUTPUT_HH

#include "Map.hh"

template <typename T>
class MapOutput {
protected:
  Map& map_;

public:
  MapOutput(Map& m) : map_(m) {}

  /* Outputs the graph. */
  virtual void output(T outputdata) = 0;

  void operator>>(std::string out) { output(out); }
};

#endif
