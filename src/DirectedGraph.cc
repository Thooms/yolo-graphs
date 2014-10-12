#include "DirectedGraph.hh"

#include "Edge.hh"
#include "EdgeType.hh"
#include "Vertex.hh"

using namespace std;


template <typename V>
unsigned int DirectedGraph<V>::addEdge(EdgeType type, V distance, unsigned int start, unsigned int end) {

  Edge<V> e = Edge<V>(this->edges_nb_, start, end, type, distance);
  this->edges_nb_++;

  if (start >= this->vertices_nb_ || end >= this->vertices_nb_)
    return -1;
  
  adjacency_[start].second.push_back(e.id());
  edges_.push_back(e);

  return e.id();
}

template <typename V>
unsigned int DirectedGraph<V>::addVertex(string name, pair<double, double> coordinates) {
  Vertex v = Vertex(this->vertices_nb_, name, coordinates);
  this->vertices_nb_++;

  adjacency_.push_back(make_pair(v, vector<unsigned int>()));

  return v.id();
}

template <typename V>
Edge<V> DirectedGraph<V>::getEdge(unsigned int id) {
  // if (id >= this->edges_nb_)
  //  return;
  
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

  vector<Vertex*> vertices;
  vector<bool> inserted(this->vertices_nb_, false);

  for (auto i : adjacency_[id].second) {
    Edge<V> edge = edges_[i];
    int other_id = edge.getOtherEnd(id);

    if (!inserted[other_id]) {
      inserted[other_id] = true;
      vertices.push_back(&adjacency_[other_id].first);
    }
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


// Types of directed graphs that can be instantiated
template class DirectedGraph<double>;
template class DirectedGraph<float>;
template class DirectedGraph<int>;
