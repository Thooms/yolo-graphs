
#ifndef DOTOUTPUT_HH
#define DOTOUTPUT_HH

#include <string>
#include <iostream>
#include <fstream>

#include "Map.hh"
#include "MapOutput.hh"

using namespace std;

class DotMapOutput : public MapOutput<string> {
public:
  DotMapOutput(Map& m) : MapOutput<string>(m) {}

  void output(string path);
};

#endif
