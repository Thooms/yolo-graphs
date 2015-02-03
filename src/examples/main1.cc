#include <iostream>
#include <string>
#include <utility>

#include "DotMapOutput.hh"
#include "Filter.hh"
#include "Map.hh"
#include "RawTextMapInput.hh"

using namespace std;


int main(void) {
  Map m;
  RawTextMapInput in(m);

  // Read the map from test.yolo
  in << "tests/graphtests/test.yolo";


  // Base city, arbitrarily chosen for the test
  City* base = m.getCity(0);

  // City and its neighbors
  cout << *base << " neighbors:" << endl;

  for (auto city : m.neighbors(base, NULL))
    cout << "\t* " << *city << endl;
  cout << endl;


  // City, its neighbors and their neighbors
  cout << *base << " neighbors, and their neighbors:" << endl;

  for (auto city : m.neighborsOfNeighbors(base, NULL))
    cout << "\t* " << *city << endl;
  cout << endl;


  // All cities
  cout << "All cities, starting from " << *base << ":" << endl;

  for (auto city : m.allNeighbors(base, NULL))
    cout << "\t* " << *city << endl;
  cout << endl;


  // Output the map
  DotMapOutput out(m);
  out >> "livrable_1.dot";

  return 0;
}
