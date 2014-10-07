
#ifndef COMPUT_UNIT_HH
#define COMPUT_UNIT_HH

#include <vector>
#include <functional>

#include "Graph.hh"
#include "Vertex.hh"
#include "Edge.hh"

class ComputationUnit {
private:
  // TODO: make the graph ref const, and adapt the code thereof
  Graph& graph_;

  /* General-purpose search, to be parametrized with a queue or a
   * stack, and an edge filter */
  std::vector<Vertex*> search(Vertex& start, std::function<Edge& (bool)> filter);

public:
  
  /* Constructors */
  
  explicit ComputationUnit() {};
  explicit ComputationUnit(Graph& g) {};

  /* {Get,Set}ters */

  Graph& graph(void);
  void setGraph(Graph& g);

  /* HERE BEGINZ THE LULZ */
  
  std::vector<Vertex*> bfs(Vertex& start, std::function<Edge& (bool)> filter);
  std::vector<Vertex*> dfs(Vertex& start, std::function<Edge& (bool)> filter);
  std::vector<Vertex*> shortestPath(Vertex& start, Vertex& end
				    , std::function<Edge& (bool)> filter);
};

#endif


