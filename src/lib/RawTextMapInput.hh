#include <string>
#include <iostream>
#include <fstream>
#include <utility>

#include "Map.hh"
#include "MapInput.hh"
#include "Vertex.hh"

using namespace std;


class RawTextMapInput : public MapInput<string> {
public:
  RawTextMapInput(Map& m) : MapInput(m) {}  

  void input(string path);
};
