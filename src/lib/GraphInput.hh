
#ifndef GRAPHINPUT_HH
#define GRAPHINPUT_HH

#include "Graph.hh"

template <typename T, typename V>
class GraphInput {
protected:
  Graph<V>& graph_;
public:
  GraphInput(Graph<V>& g) : graph_(g) {}

  /* Fills the graph with data. */
  virtual void input(T inputdata) = 0;

  void operator<<(std::string in) { input(in); }
};

#endif
