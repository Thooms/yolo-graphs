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

  in << "tests/graphtests/test.yolo";

  auto& cu = ComputationUnit<double>::instance();
  cu.setGraph(&g);

  cout << "BFS from vertex " << g.getVertex(0).name() << endl;

  for (auto vertex : cu.bfs(0, 0, true__))
  	std::cout << vertex.name() << " ";
  std::cout << std::endl;

  cout << "DFS from vertex " << g.getVertex(0).name() << endl;

  for (auto vertex : cu.dfs(0, 0, true__))
  	std::cout << vertex.name() << " ";
  std::cout << std::endl;


  DotGraphOutput<double> out(g);
  out >> "truc.dot";

  return 0;
}
