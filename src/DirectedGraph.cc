#include "DirectedGraph.hh"

#include <utility>
#include <vector>

#include "Vertex.hh"

using namespace std;

template <typename V>
int DirectedGraph<V>::addEdge(Edge<V>& e) {
  pair<Vertex&, Vertex&>& vertices = e.vertices();

  Vertex& source = vertices.first;

  auto obj = adjacency_.find(source);

  if (obj == adjacency_.end()) {
    adjacency_[source] = vector<Edge<V>&>();
    obj.second = adjacency_[source];
  }

  obj.second.push_back(e);

  return e.id();
}

template <typename V>
int DirectedGraph<V>::addEdge(Vertex& source, Vertex& destination, EdgeType type, V& distance) {
  Edge<V> e = Edge<V>(source, destination, type, distance);

  return addEdge(e);
}


