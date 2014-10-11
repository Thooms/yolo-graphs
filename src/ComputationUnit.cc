#include "ComputationUnit.hh"

#include <queue>
#include <stack>
#include <unordered_map>
#include <utility>

using namespace std;

template <typename V>
ComputationUnit<V>::ComputationUnit() {

}

template <typename V>
ComputationUnit<V>::ComputationUnit(Graph<V>& g) {
  graph_ = g;
}

template <typename V>
Graph<V>& ComputationUnit<V>::graph(void) {
  return graph_;
}

template <typename V>
void ComputationUnit<V>::setGraph(Graph<V>& g) {
  graph_ = g;
}

template <typename V>
vector<Vertex*> ComputationUnit<V>::bfs(Vertex& start, unsigned int depth, function<Edge<V>& (bool)> filter) {
  vector<Vertex*> order;

  queue< pair<Vertex*, int> > q;
  vector<bool> visited(graph_.verticesNb(), false);

  Vertex* v;
  int id, current_depth;

  // Insert the start vertex as the root of the bfs
  q.push(make_pair(&start, 1));

  while (!q.empty()) {
    pair<Vertex*, int>& head = q.front();

    v = head.first;
    id = v->id();
    current_depth = head.second;

    order.push_back(v);
    q.pop();

    // Iterate over all neighbors of the front vertex
    for (auto edge : graph_.outgoingEdges(id))
      if (filter(*edge)) {
        // Query the neighbor vertex
        Vertex& neighbor = graph_.getVertex(edge->getOtherId(id));

        // Check whether it has already been visited before or if the max depth has been reached
        if ((current_depth != depth) && !visited[neighbor.id()]) {
          visited[neighbor.id()] = true;
          q.push(make_pair(&neighbor, current_depth + 1));
        }
      }
  }

  return order;
}
