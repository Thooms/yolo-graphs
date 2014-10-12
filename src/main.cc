#include <iostream>
#include <string>
#include <utility>

#include "DirectedGraph.hh"
#include "Edge.hh"
#include "EdgeType.hh"
#include "Vertex.hh"
#include "DotGraphOutput.hh"

using namespace std;

int main(void) {
  DirectedGraph<double> g("France");

  std::cout << g.name() << std::endl;

  g.addVertex("Paris", make_pair(50.0, 50.0));
  g.addVertex("Lyon", make_pair(75.0, 100.0));
  g.addVertex("Marseille", make_pair(85.0, 130.0));
  g.addVertex("Lille", make_pair(45.0, 10.0));

  // g.addEdge(EdgeType::Plane, 1000.0, 0, 2); // Paris - Marseille
  g.addEdge(EdgeType::Road, 500.0, 0, 1); // Paris - Lyon
  g.addEdge(EdgeType::Road, 350.0, 1, 2); // Lyon - Marseille
  g.addEdge(EdgeType::Train, 500.0, 0, 1); // Paris - Lyon
  g.addEdge(EdgeType::Train, 200.0, 0, 3); // Paris - Lille

  // Paris adjacent cities
  for (auto v : g.adjacentVertices(0)) {
  	std::cout << v->name() << std::endl;
  }

  DotGraphOutput<double> out(g);

  out.output("truc.dot");

  return 0;
}
