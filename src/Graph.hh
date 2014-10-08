
#ifndef GRAPH_HH
#define GRAPH_HH

#include "Edge.hh"
#include "Vertex.hh"
#include "Nameable.hh"

#include <vector>

using namespace std;

template <typename V>
class Graph : public Nameable {
protected:
  unsigned int vertices_nb_;
  unsigned int edges_nb_;
  

public:
  explicit Graph();
  explicit Graph(string name);

  // NOTE: No setter, the only way to modify it is to add a vertex
  unsigned int verticesNb(void);
  
  // NOTE: No setter as well
  unsigned int edgesNb(void);
  
  /* Adds an edge and returns its id */
  virtual int addEdge(Edge<V>&) = 0;
  
  /* Removes an edge from the graph */
  virtual void removeEdge(Edge<V>&) = 0;

  /* Adds a vertex and returns its id */
  virtual int addVertex(Vertex&) = 0;

  /* Removes a vertex from the graph 
   *
   * NOTE: depending on the underlying representation, a node removal
   * can also remove some of the edges coming from/to this node.
   */
  virtual void removeVertex(Vertex&) = 0;

  virtual vector<const Edge<V>&> outgoingEdges(Vertex&);

  virtual vector<const Vertex&> adjacentVertices(Vertex&);

};


#endif
