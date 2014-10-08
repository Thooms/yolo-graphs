#include <string>
#include <iostream>

#include "Graph.hh"
#include "GraphInput.hh"


using namespace std;

template <typename V>
class RawTextGraphInput : public GraphInput<string, V> {
public:
  
  RawTextGraphInput(Graph<V>& g) : GraphInput<string, V>(g) {}
  
  void input(string path) {
    cout << "Fetching graph from file " << path << endl;
  }
};
