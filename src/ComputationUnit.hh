
#ifndef COMPUT_UNIT_HH
#define COMPUT_UNIT_HH

#include <vector>
#include <functional>

#include "Graph.hh"
#include "Vertex.hh"
#include "Edge.hh"


template <typename V>
class ComputationUnit {
private:
  // TODO: make the graph ref const, and adapt the code thereof
  Graph<V>& graph_;

public:
  
  /* Constructors */
  
  explicit ComputationUnit();
  explicit ComputationUnit(Graph<V>& g);

  /* {Get,Set}ters */

  Graph<V>& graph(void);
  void setGraph(Graph<V>& g);
  
  std::vector<Vertex*> bfs(Vertex& start, unsigned int depth, std::function<Edge<V>& (bool)> filter);
  std::vector<Vertex*> dfs(Vertex& start, unsigned int depth, std::function<Edge<V>& (bool)> filter);
  std::vector<Vertex*> shortestPath(Vertex& start, Vertex& end, std::function<Edge<V>& (bool)> filter);
};

#endif
