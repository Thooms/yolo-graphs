#include "Vertex.hh"

Vertex::Vertex() {}

Vertex::Vertex(unsigned int id, string& name) {
  setName(name);
  id_ = id;
}

unsigned int Vertex::id(void) {
	return id_;
}

