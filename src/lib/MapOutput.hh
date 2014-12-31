
#ifndef GRAPHOUTPUT_HH
#define GRAPHOUTPUT_HH

#include "Graph.hh"

template <typename T, typename V>
class GraphOutput {
protected:
  Graph<V>& graph_;

public:
  GraphOutput(Graph<V>& g) : graph_(g) {}

  /* Outputs the graph. */
  virtual void output(T outputdata) = 0;

  void operator>>(std::string out) { output(out); }
};

#endif
