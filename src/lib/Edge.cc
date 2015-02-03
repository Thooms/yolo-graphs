#include "Edge.hh"

template <typename V>
Edge<V>::Edge() {}

template <typename V>
Edge<V>::Edge(unsigned int id, unsigned int start, unsigned int end, EdgeType type, V dist) {
  id_ = id;
  vertices_ = make_pair(start, end);
  type_ = type;
  distance_ = dist;
}

template <typename V>
unsigned int Edge<V>::id(void) {
  return id_;
}

template <typename V>
EdgeType Edge<V>::type(void) {
  return type_;
}

template <typename V>
V& Edge<V>::distance(void) {
  return distance_;
}

template <typename V>
void Edge<V>::setDistance(V distance) {
  distance_ = distance;
}

template <typename V>
V Edge<V>::speed(void) {
  return (V)type_;
}

template <typename V>
pair<unsigned int, unsigned int>& Edge<V>::vertices(void) {
  return vertices_;
}

template <typename V>
unsigned int Edge<V>::getOtherEnd(unsigned int id) {
  if (id == vertices_.first)
    return vertices_.second;

  if (id == vertices_.second)
    return vertices_.first;

  // Bad id is given
  return -1;
}

// Types of edges that can be instantiated
template class Edge<double>;
template class Edge<float>;
template class Edge<int>;
