#include "Graph.hh"

#include <map>
#include <vector>

using namespace std;

template <typename V>
class DirectedGraph : public Graph<V> {
private:
  map<Vertex&, vector<Edge<V>>> adjacency_;
};
