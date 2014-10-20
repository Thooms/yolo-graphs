#include "Vertex.hh"

ostream& operator<<(ostream& out, Vertex& v) {
    out << v.name();
    return out;
  }

Vertex::Vertex() {}

Vertex::Vertex(unsigned int id, string& name) {
  setName(name);
  id_ = id;
}

Vertex::Vertex(unsigned int id, string& name, pair<double, double>& coordinates) {
  setName(name);
  id_ = id;
  coordinates_ = coordinates;
}

unsigned int Vertex::id(void) {
	return id_;
}

pair<double, double>& Vertex::coordinates(void) {
	return coordinates_;
}
