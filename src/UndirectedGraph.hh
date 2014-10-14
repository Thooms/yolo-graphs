
#ifndef UNDIRECTED_GRAPH_HH
#define UNDIRECTED_GRAPH_HH

#include <string>
#include <vector>
#include <utility>

#include "DirectedGraph.hh"
#include "EdgeType.hh"
#include "Edge.hh"
#include "Vertex.hh"


template <typename V>
class UndirectedGraph : public DirectedGraph<V> {
public:

  unsigned int addEdge(EdgeType type, V distance, unsigned int start, unsigned int end);

};

#endif
