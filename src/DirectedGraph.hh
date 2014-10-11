
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
  vector<pair<Vertex, vector<unsigned int> > > adjacency_;
  vector<Edge<V> > edges_;

public:
  /* Constructors */

  DirectedGraph() : Graph<V>() {}

  DirectedGraph(string name) : Graph<V>(name) {}

  /* Methods */

  virtual unsigned int addEdge(EdgeType type, V distance, unsigned int start, unsigned int end);

  virtual unsigned int addVertex(string name, pair<double, double> coordinates);

  virtual Edge<V> getEdge(unsigned int);
  
  virtual Vertex getVertex(unsigned int);

  virtual vector<Edge<V>*> outgoingEdges(unsigned int);

  virtual vector<Vertex*> adjacentVertices(unsigned int);


  /* Destructor */

  ~DirectedGraph();
};

#endif
