
#ifndef DIRECTED_GRAPH_HH
#define DIRECTED_GRAPH_HH

#include <string>
#include <unordered_map>
#include <vector>

#include "Graph.hh"
#include "Vertex.hh"
#include "Edge.hh"

using namespace std;

template <typename V>
class DirectedGraph : public Graph<V> {
private:
  unordered_map<int, vector<int> > adjacency_;
  unordered_map<int, Edge<V>&> edges_;

public:
  /* Constructors */

  DirectedGraph() : Graph<V>() {}

  DirectedGraph(string name) : Graph<V>(name) { }

  /* Methods */

  int addEdge(Edge<V>&);
  int addEdge(Vertex&, Vertex&, EdgeType, V&);

  void removeEdge(Edge<V>&);

  int addVertex(Vertex&);

  void removeVertex(Vertex&);

  vector<const Edge<V>&> outgoingEdges(Vertex&);

  vector<const Vertex&> adjacentVertices(Vertex&);

  /* Destructor */

  ~DirectedGraph();
};

#endif
