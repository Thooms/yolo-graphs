
#ifndef DIRECTED_GRAPH_HH
#define DIRECTED_GRAPH_HH

#include <string>
#include <vector>
#include <utility>

#include "Graph.hh"
#include "EdgeType.hh"
#include "Edge.hh"
#include "Vertex.hh"

using namespace std;

template <typename V>
class DirectedGraph : public Graph<V> {
protected:
  vector< pair< Vertex*, vector<unsigned int> > > adjacency_;
  vector< Edge<V> > edges_;

public:
  /* Constructors */

  DirectedGraph() : Graph<V>() {}

  DirectedGraph(string name) : Graph<V>(name) {}

  /* Methods */

  unsigned int addEdge(EdgeType type, V distance, unsigned int start, unsigned int end);

  unsigned int addVertex(string);

  unsigned int addVertex(Vertex*);

  Edge<V> getEdge(unsigned int);
  
  Vertex* getVertex(unsigned int);

  vector<Edge<V>*> outgoingEdges(unsigned int);

  vector<Vertex*> adjacentVertices(unsigned int);


  /* Destructor */

  ~DirectedGraph();
};

#endif
