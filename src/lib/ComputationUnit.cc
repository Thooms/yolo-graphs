#include "ComputationUnit.hh"

#include <queue>
#include <stack>
#include <unordered_map>
#include <utility>
#include <algorithm>

using namespace std;

template <typename V>
ComputationUnit<V>::ComputationUnit() {

}

template <typename V>
ComputationUnit<V>::ComputationUnit(Graph<V>* g) {
  graph_ = g;
}

template <typename V>
Graph<V>& ComputationUnit<V>::graph(void) {
  return *graph_;
}

template <typename V>
void ComputationUnit<V>::setGraph(Graph<V>* g) {
  graph_ = g;
}

template <typename V>
vector<Vertex> ComputationUnit<V>::dfs(unsigned int start, unsigned int depth, function<bool (Edge<V>&)> filter) {
  vector<Vertex> order;

  stack< pair<Vertex, int> > s;
  vector<bool> visited(graph_->verticesNb(), false);

  Vertex v;
  unsigned int id, current_depth;

  // Insert the start vertex as the root of the bfs
  s.push(make_pair(graph_->getVertex(start), 1));
  visited[start] = true;

  while (!s.empty()) {
    pair<Vertex, int>& head = s.top();

    v = head.first;
    id = v.id();
    current_depth = head.second;

    order.push_back(v);
    s.pop();

    // Iterate over all neighbors of the front vertex
    for (auto edge : graph_->outgoingEdges(id))
      if (filter(*edge)) {
        // Query the neighbor vertex
        Vertex neighbor = graph_->getVertex(edge->getOtherEnd(id));

        // Check whether it has already been visited before or if the max depth has been reached
        if ((current_depth != depth) && !visited[neighbor.id()]) {
          visited[neighbor.id()] = true;
          s.push(make_pair(neighbor, current_depth + 1));
        }
      }
  }

  return order;
}

template <typename V>
vector<Vertex> ComputationUnit<V>::bfs(unsigned int start, unsigned int depth, function<bool (Edge<V>&)> filter) {
  vector<Vertex> order;

  queue< pair<Vertex, int> > q;
  vector<bool> visited(graph_->verticesNb(), false);

  Vertex v;
  unsigned int id, current_depth;

  // Insert the start vertex as the root of the bfs
  q.push(make_pair(graph_->getVertex(start), 1));
  visited[start] = true;

  while (!q.empty()) {
    pair<Vertex, int>& head = q.front();

    v = head.first;
    id = v.id();
    current_depth = head.second;

    order.push_back(v);
    q.pop();

    // Iterate over all neighbors of the front vertex
    for (auto edge : graph_->outgoingEdges(id))
      if (filter(*edge)) {
        // Query the neighbor vertex
        Vertex neighbor = graph_->getVertex(edge->getOtherEnd(id));

        // Check whether it has already been visited before or if the max depth has been reached
        if ((current_depth != depth) && !visited[neighbor.id()]) {
          visited[neighbor.id()] = true;
          q.push(make_pair(neighbor, current_depth + 1));
        }
      }
  }

  return order;
}

/* Handcrafted pair class designed for the Dijkstra algorithm.
   We want the comparison operator to operate only on the first member
   (the second one is only an annotation).

   Note that we reverse the ordering, to turn the STL max-heap into a min-heap (#YOLO)
 */
template <typename V, typename W>
class dijkstra_pair : public pair<V, W> {
public:
  dijkstra_pair() : pair<V, W>() {}
  dijkstra_pair(pair<V, W> p) : pair<V, W>(p.first, p.second) {}
  bool operator<(const dijkstra_pair<V, W>& rhs) const {
    return this->first > rhs.first;
  }
};

/* Dijkstra algorithm implementation, suffers from the usual limitations like
   positivity of cycles, and so on. The graph needs to be connex for now.
*/
template <typename V>
pair<vector<Vertex>, V> ComputationUnit<V>::shortestPath(unsigned int start, unsigned int end,
                            function<bool (Edge<V>&)> filter) {
  // Distances from start
  vector<V> distances(graph_->verticesNb(), -1);
  distances[start] = 0;

  // Output tree
  vector<int> pred(graph_->verticesNb(), -1);

  // Priority queue used to manipulate the border
  priority_queue<dijkstra_pair<V, unsigned int>> p;

  dijkstra_pair<V, unsigned int> curr;
  V tmp;
  unsigned int o_id;

  // We start by enqueueing the start node
  p.push(make_pair(static_cast<V>(0), start));

  while (!p.empty()) {
    // Select the nearest
    curr = p.top();
    // Remove the nearest (since we cannot lower the priority)
    p.pop();

    // For each adjacent edge, update the neighbors if necessary
    for (auto edge : graph_->outgoingEdges(curr.second)) {
      if (filter(*edge)) {
        o_id = edge->getOtherEnd(curr.second);
        tmp = distances[curr.second] + edge->distance();

        if (distances[o_id] == -1 || tmp < distances[o_id]) {
          distances[o_id] = tmp;
          pred[o_id] = curr.second;
          p.push(make_pair(tmp, o_id));
        }
      }
    }
  }

  // We follow the tree to find the path searched for
  vector<Vertex> res;
  unsigned int curr_id = end;

  do {
    res.push_back(graph_->getVertex(curr_id));
    curr_id = pred[curr_id];
  } while (pred[curr_id] != -1);
  res.push_back(graph_->getVertex(start));

  // The current path is reversed, so we reverse it again
  reverse(res.begin(), res.end());

  return make_pair(res, distances[end]);
}

template <typename V>
ComputationUnit<V>& ComputationUnit<V>::instance(void) {
  static ComputationUnit<V> instance_ = ComputationUnit<V>();

  return instance_;
}


// Types of computation unit that can be instantiated
template class ComputationUnit<double>;
template class ComputationUnit<float>;
template class ComputationUnit<int>;
