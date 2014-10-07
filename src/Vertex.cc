#include "Vertex.hh"

unsigned int Vertex::COUNTER = 0;

void Vertex::counterIncr(void) {
  ++COUNTER;
}

void Vertex::counterDecr(void) {
  --COUNTER;
}

unsigned int Vertex::getCounter(void) {
  return COUNTER;
}

Vertex::Vertex() {
  id_ = getCounter();
  counterIncr();
}

Vertex::Vertex(string& name) {
  Vertex();

  setName(name);
}

Vertex::Vertex(string& name, pair<double, double>& coordinates) {
  Vertex();

  setName(name);
  coordinates_ = coordinates;
}
