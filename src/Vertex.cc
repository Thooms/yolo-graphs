#include "Vertex.hh"

Vertex::Vertex() {}

Vertex::Vertex(string& name) {
  setName(name);
}

Vertex::Vertex(string& name, pair<double, double>& coordinates) {
  setName(name);
  coordinates_ = coordinates;
}

unsigned int Vertex::id(void) {
	return id_;
}

pair<double, double>& Vertex::coordinates(void) {
	return coordinates_;
}
