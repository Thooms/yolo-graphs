#include <string>
#include <iostream>
#include <fstream>
#include <utility>

#include "Graph.hh"
#include "GraphInput.hh"
#include "Vertex.hh"

using namespace std;

template <typename V>
class RawTextGraphInput : public GraphInput<string, V> {
public:
  
  RawTextGraphInput(Graph<V>& g) : GraphInput<string, V>(g) {}
  
  void input(string path) {
    cout << "Fetching graph from file " << path << endl;

    ifstream ifs(path, ifstream::in);

    int v;
    string tmp;

    /* We parse a vertex number, and a list of vertices names */
    
    ifs >> v;

    for (int i = 0; i < v; i++) {
      ifs >> tmp;
      this->graph_.addVertex(tmp, make_pair(0.0, 0.0));
    }
    
  }
};
