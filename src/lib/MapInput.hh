
#ifndef MAPINPUT_HH
#define MAPINPUT_HH

template <typename T>
class MapInput {
protected:
  Map& map_;
public:
  MapInput(Map& m) : map_(m) {}

  /* Fills the graph with data. */
  virtual void input(T inputdata) = 0;

  void operator<<(std::string in) { input(in); }
};

#endif
