
#ifndef DOTOUTPUT_HH
#define DOTOUTPUT_HH

#include <string>
#include <iostream>
#include <fstream>

#include "Graph.hh"
#include "GraphOutput.hh"
#include "Vertex.hh"
#include "Edge.hh"

using namespace std;

template <typename V>
class DotGraphOutput : public GraphOutput<string, V> {
public:
  DotGraphOutput(Graph<V>& g) : GraphOutput<string, V>(g) {}

  void output(string path);
};

#endif
