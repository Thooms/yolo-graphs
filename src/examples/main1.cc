#include <iostream>
#include <string>
#include <utility>

#include "ComputationUnit.hh"
#include "DirectedGraph.hh"
#include "UndirectedGraph.hh"
#include "Edge.hh"
#include "EdgeType.hh"
#include "Vertex.hh"
#include "DotGraphOutput.hh"
#include "RawTextGraphInput.hh"

#include "Filter.hh"

using namespace std;

bool road__(Edge<double>& e) { return e.type() == EdgeType::Road; }

int main(void) {
  UndirectedGraph<double> g;
  RawTextGraphInput<double> in(g);

  // Read the graph from test.yolo
  in << "tests/graphtests/test.yolo";

  cout << "Manipulating graph '" << g << "'" << endl;

  // Generate filters used later
  GenericFilter<double>* road_ = new Filter<double>(road__);

  // Get the computation unit
  auto& cu = ComputationUnit<double>::instance();
  cu.setGraph(&g);

  Vertex base = g.getVertex(0);

  // City and its neighbors
  cout << base << " neighbors: ";

  for (auto vertex : cu.bfs(0, 2, road_))
  	cout << vertex << " ";
  cout << endl;

  // City, its neighbors and their neighbors
  cout << base << " neighbors, and their neighbors: ";

  for (auto vertex : cu.bfs(0, 3, NULL))
  	cout << vertex << " ";
  cout << endl;

  // All cities
  cout << "All cities, starting from " << base << ": ";

  for (auto vertex : cu.bfs(0, 0, NULL))
    cout << vertex << " ";
  cout << endl;

  // Output the graph
  DotGraphOutput<double> out(g);
  out >> "truc.dot";

  return 0;
}
