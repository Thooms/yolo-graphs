#include "Vertex.hh"

Vertex::Vertex() {}

Vertex::Vertex(string& name) {
  setName(name);
}

Vertex::Vertex(string& name, pair<double, double>& coordinates) {
  setName(name);
  coordinates_ = coordinates;
}
