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
  
  void input(string path);
};
