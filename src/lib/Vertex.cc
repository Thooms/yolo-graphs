#include "Vertex.hh"

Vertex::Vertex() {}

Vertex::Vertex(unsigned int id, string& name) {
  setName(name);
  id_ = id;
}

unsigned int Vertex::id(void) {
	return id_;
}

void Vertex::setID(unsigned int id) {
    id_ = id;
}
