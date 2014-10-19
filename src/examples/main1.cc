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

using namespace std;

bool true__(Edge<double>& e) { (void)e; return true; }

int main(void) {
  UndirectedGraph<double> g;
  RawTextGraphInput<double> in(g);

  // Read the graph from test.yolo
  in << "tests/graphtests/test.yolo";


  // Get the computation unit
  auto& cu = ComputationUnit<double>::instance();
  cu.setGraph(&g);


  // City and its neighbors
  cout << g.getVertex(0).name() << " neighbors: ";

  for (auto vertex : cu.bfs(0, 2, true__))
  	cout << vertex.name() << " ";
  cout << endl;

  // City, its neighbors and their neighbors
  cout << g.getVertex(0).name() << " neighbors, and their neighbors: ";

  for (auto vertex : cu.bfs(0, 3, true__))
  	cout << vertex.name() << " ";
  cout << endl;

  // All cities
  cout << "All cities, starting from " << g.getVertex(0).name() << ": ";

  for (auto vertex : cu.bfs(0, 0, true__))
    cout << vertex.name() << " ";
  cout << endl;


  // Output the graph
  DotGraphOutput<double> out(g);
  out >> "truc.dot";

  return 0;
}
