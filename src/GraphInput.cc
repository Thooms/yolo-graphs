#include "GraphInput.hh"

template <typename T, typename V>
GraphInput<T, V>::GraphInput(Graph<V>& g) {
  graph_ = g;
}

