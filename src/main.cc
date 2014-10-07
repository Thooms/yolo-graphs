#include <iostream>
#include <string>

#include "Vertex.hh"

using namespace std;

int main(void) {
  string name = "Paris";

  Vertex v(name);

  cout << v.name() << endl;

  return 0;
}
