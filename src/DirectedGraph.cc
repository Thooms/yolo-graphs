#include "DirectedGraph.hh"

#include <utility>
#include <vector>

#include "Vertex.hh"

using namespace std;

template <typename V>
int DirectedGraph<V>::addEdge(Edge<V>& e) {
  pair<Vertex&, Vertex&>& vertices = e.vertices();

  int source = vertices.first.id();

  auto obj = adjacency_.find(source);

  if (obj == adjacency_.end()) {
    adjacency_[source] = vector<Edge<V>&>();
    obj.second = adjacency_[source];
  }

  obj.second.push_back(e);

  this->edges_nb_++;

  return e.id();
}

template <typename V>
int DirectedGraph<V>::addEdge(Vertex& source, Vertex& destination, EdgeType type, V& distance) {
  Edge<V> e = Edge<V>(source, destination, type, distance);

  return addEdge(e);
}

template <typename V>
void DirectedGraph<V>::removeEdge(Edge<V> &e) {
  pair<Vertex&, Vertex&>& vertices = e.vertices();

  int source = vertices.first.id();

  auto obj = adjacency_.find(source);

  if (obj == adjacency_.end())
    return;

  for (int i = 0; i < obj.second.size(); ++i)
    if (obj.second[i] == e) {
      obj.second.erase(obj.second.begin() + i);
      break;
    }

}

template <typename V>
int DirectedGraph<V>::addVertex(Vertex& v) {

  return v.id();
}


