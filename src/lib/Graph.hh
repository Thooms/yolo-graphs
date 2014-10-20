
#ifndef GRAPH_HH
#define GRAPH_HH

#include "Edge.hh"
#include "EdgeType.hh"
#include "Vertex.hh"
#include "Nameable.hh"

#include <vector>

using namespace std;

template <typename V>
class Graph : public Nameable {
protected:

  /* The next available id for each object id *_nb_. */
  unsigned int vertices_nb_;
  unsigned int edges_nb_;
  
public:
  explicit Graph() {
    vertices_nb_ = 0;
    edges_nb_ = 0;
  }

  explicit Graph(string name) {
    setName(name);
    vertices_nb_ = 0;
    edges_nb_ = 0;
  }

  // NOTE: No setter, the only way to modify it is to add a vertex
  unsigned int verticesNb(void) { return vertices_nb_; }
  
  // NOTE: No setter as well
  unsigned int edgesNb(void) { return edges_nb_; }
  
  /* Adds an edge and returns its id */
  virtual unsigned int addEdge(EdgeType type, V distance, unsigned int start, unsigned int end) = 0;

  /* Adds a vertex and returns its id */
  virtual unsigned int addVertex(string name, pair<double, double> coordinates) = 0;

  /* Getters for the graph's elements */
  virtual Edge<V> getEdge(unsigned int) = 0;
  
  virtual Vertex getVertex(unsigned int) = 0;

  virtual vector<Edge<V>*> outgoingEdges(unsigned int) = 0;

  virtual vector<Vertex*> adjacentVertices(unsigned int) = 0;

  /* Modifiers for the graph's elements */
  //TODO

};


#endif
