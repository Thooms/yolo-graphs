#include "DirectedGraph.hh"

#include <utility>
#include <vector>

#include "Edge.hh"
#include "EdgeType.hh"
#include "Vertex.hh"


using namespace std;


template <typename V>
unsigned int DirectedGraph<V>::addEdge(EdgeType type, V distance, unsigned int start, unsigned int end) {

  Edge<V> e = Edge<V>(this->edges_nb, start, end, type, distance);
  this->edges_nb++;

  if (start >= this->vertices_nb_ || end >= this->vertices_nb_)
    return -1;
  
  adjacency_[start].second.push_back(e.id());
  edges_.push_back(e);

  return e.id();
}

template <typename V>
unsigned int DirectedGraph<V>::addVertex(string name, pair<double, double> coordinates) {
  Vertex v = Vertex(name, coordinates);

  adjacency_.push_back(make_pair(v, vector<unsigned int>()));

  return ++(this->vertices_nb_);
}

template <typename V>
Edge<V> DirectedGraph<V>::getEdge(unsigned int id) {
  if (id >= this->edges_nb_)
    return;
  
  return edges_[id];
}





