
#ifndef GRAPH_HH
#define GRAPH_HH

#import "Edge.hh"
#import "Vertex.hh"

template <typename V>
class Graph {
private:
  int vertices_nb_;
  int edges_nb_;
  

public:
  Graph();

  // NOTE: No setter, the only way to modify it is to add a vertex
  int verticesNb(void);
  
  // NOTE: No setter as well
  int edgesNb(void);
  
  /* Adds an edge and returns its id */
  virtual int addEdge(Edge<V>&) = 0;
  
  /* Removes an edge from the graph */
  virtual void removeEdge(int) = 0;

  /* Adds a vertex and returns its id */
  virtual int addVertex(Vertex&) = 0;

  /* Removes a vertex from the graph 
   *
   * NOTE: depending on the underlying representation, a node removal
   * can also remove some of the edges coming from/to this node.
   */
  virtual void removeVertex(int) = 0;

};


#endif
