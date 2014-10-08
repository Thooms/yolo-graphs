
#ifndef GRAPHINPUT_HH
#define GRAPHINPUT_HH

#include "Graph.hh"

template <typename T, typename V>
class GraphInput {
private:
  Graph<V>& graph_;
public:
  GraphInput(Graph<V>& g);

  /* Fills the graph with data. */
  virtual void input(T inputdata) = 0;
};

#endif
