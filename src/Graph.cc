#include "Graph.hh"

template <typename V>
Graph<V>::Graph() {
  vertices_nb_ = 0;
  edges_nb_ = 0;
}

template <typename V>
unsigned int Graph<V>::verticesNb(void) {
  return vertices_nb_;
}

template <typename V>
unsigned int Graph<V>::edgesNb(void) {
  return edges_nb_;
}

