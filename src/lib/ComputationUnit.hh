
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
  Graph<V>* graph_;
  
  /* Constructors */
  
  explicit ComputationUnit();
  explicit ComputationUnit(Graph<V>* g);


public:

  /* {Get,Set}ters */

  Graph<V>& graph(void);
  void setGraph(Graph<V>* g);
  
  std::vector<Vertex> bfs(unsigned int start, unsigned int depth, std::function<bool (Edge<V>&)> filter);
  std::vector<Vertex> dfs(unsigned int start, unsigned int depth, std::function<bool (Edge<V>&)> filter);
  std::vector<Vertex> shortestPath(Vertex start, Vertex end, std::function<bool (Edge<V>&)> filter);

  static ComputationUnit<V>& instance(void);
};

#endif
