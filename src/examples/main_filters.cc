#include <iostream>
#include <string>
#include <utility>

#include "DotMapOutput.hh"
#include "EdgeType.hh"
#include "Filter.hh"
#include "Map.hh"
#include "RawTextMapInput.hh"

using namespace std;

bool small_edges_(Edge<double>& e) { return e.distance() < 450.0; }
bool roads_(Edge<double>& e) { return e.type() == EdgeType::Road; }
bool planes_(Edge<double>& e) { return e.type() == EdgeType::Plane; }

int main(void) {
  Map m;
  RawTextMapInput in(m);

  // Read the map from test.yolo
  in << "tests/graphtests/test.yolo";

  // Base city, arbitrarily chosen for the test
  City* base = m.getCity(0);


  // Create filters : accept only small edges (<450km), only roads and only planes
  GenericFilter<double>* small_edges = new Filter<double>(small_edges_);
  GenericFilter<double>* roads = new Filter<double>(roads_);
  GenericFilter<double>* planes = new Filter<double>(planes_);

  // Accepted edges must be either planes or both small and roads
  GenericFilter<double>* global_filter = *planes || (*small_edges && roads);

  // City and its neighbors
  cout << *base << " neighbors accessible by plane or {with distance lower than 450 km and accessible by road}: ";

  for (auto city : m.neighbors(base, global_filter))
    cout << *city << " ";
  cout << endl;

  // Free memory, it's ecological! :-)
  delete global_filter;
  delete small_edges;
  delete roads;
  delete planes;

  return 0;
}
