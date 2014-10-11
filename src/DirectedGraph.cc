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

template <typename V>
Vertex DirectedGraph<V>::getVertex(unsigned int id) {
  // if (id >= adjacency_.size())
  //  return;
  
  return adjacency_[id].first;
}

template <typename V>
vector<Edge<V>*> DirectedGraph<V>::outgoingEdges(unsigned int id) {
  // if (id >= adjacency_.size())
  //  return;

  vector<Edge<V>*> edges(adjacency_[id].second.size());
  int j(0);

  for (auto i : adjacency_[id].second)
    edges[j++] = &edges_[i];

  return edges; 
}

template <typename V>
vector<Vertex*> DirectedGraph<V>::adjacentVertices(unsigned int id) {
  // if (id >= adjacency_.size())
  //  return;

  vector<Vertex*> vertices(adjacency_[id].second.size());
  int j(0);

  for (auto i : adjacency_[id].second) {
    Edge<V> edge = edges_[i];

    vertices[j++] = &adjacency_[edge.getOtherEnd(id)].first;
  }

  return vertices;
}

template <typename V>
DirectedGraph<V>::~DirectedGraph() {
  for (auto v : adjacency_)
    v.second.clear();

  adjacency_.clear();
  edges_.clear();
}

