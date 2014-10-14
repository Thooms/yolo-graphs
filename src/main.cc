#include <iostream>
#include <string>
#include <utility>

#include "ComputationUnit.hh"
#include "DirectedGraph.hh"
#include "Edge.hh"
#include "EdgeType.hh"
#include "Vertex.hh"
#include "DotGraphOutput.hh"
#include "RawTextGraphInput.hh"

using namespace std;

bool true__(Edge<double>& e) { if (e.distance() >= 0.0) return true; return true; }

int main(void) {
  DirectedGraph<double> g;
  RawTextGraphInput<double> in(g);

  in.input("tests/directed_20_100.yolo");

  auto& cu = ComputationUnit<double>::instance();
  cu.setGraph(&g);

  cout << "BFS from vertex " << g.getVertex(0).name() << endl;

  for (auto vertex : cu.bfs(0, 2, true__))
  	std::cout << vertex.name() << " ";
  std::cout << std::endl;



  DotGraphOutput<double> out(g);
  out.output("truc.dot");

  return 0;
}
