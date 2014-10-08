#include "Edge.hh"

template <typename V>
unsigned int Edge<V>::COUNTER = 0;

template <typename V>
void Edge<V>::counterIncr(void) {
  ++COUNTER;
}

template <typename V>
void Edge<V>::counterDecr(void) {
  --COUNTER;
}

template <typename V>
unsigned int Edge<V>::getCounter(void) {
  return COUNTER;
}

template <typename V>
Edge<V>::Edge() {

}

template <typename V>
Edge<V>::Edge(Vertex& a, Vertex& b, EdgeType type, V distance) {
  vertices_.first = a;
  vertices_.second = b;
  type_ = type;
  distance_ = distance;

  id_ = getCounter();
  counterIncr();
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
pair<Vertex&, Vertex&>& Edge<V>::vertices(void) {
  return vertices_;
}