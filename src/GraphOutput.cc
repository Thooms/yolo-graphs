#include "GraphOutput.hh"

template <typename T, typename V>
GraphOutput<T, V>::GraphOutput(Graph<V>& g) {
  graph_ = g;
}
