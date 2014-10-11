
#ifndef DIRECTED_GRAPH_HH
#define DIRECTED_GRAPH_HH

#include <string>
#include <vector>
#include <utility>

#include "Graph.hh"
#include "Vertex.hh"
#include "Edge.hh"

using namespace std;

template <typename V>
class DirectedGraph : public Graph<V> {
private:
  vector< pair< Vertex, vector<unsigned int> > > adjacency_;
  vector< Edge<V> > edges_;

public:
  /* Constructors */

  DirectedGraph() : Graph<V>() {}

  DirectedGraph(string name) : Graph<V>(name) {}

  /* Methods */

  unsigned int addEdge(EdgeType type, V distance, unsigned int start, unsigned int end);

  unsigned int addVertex(string name, pair<double, double> coordinates);

  Edge<V> getEdge(unsigned int);
  
  Vertex getVertex(unsigned int);

  vector<Edge<V>*> outgoingEdges(unsigned int);

  vector<Vertex*> adjacentVertices(unsigned int);


  /* Destructor */

  ~DirectedGraph();
};

#endif
