#include <iostream>
#include <string>
#include <utility>

#include "DotMapOutput.hh"
#include "Filter.hh"
#include "Map.hh"
#include "RawTextMapInput.hh"

using namespace std;

// Cost function using distance between cities
double distance_cost(Edge<double> e) { return e.distance(); }

// Cost function using estimated time between cities (time = distance / speed)
double time_cost(Edge<double> e) { return e.distance() / static_cast<double>(e.type()); }


int main(void) {
  Map m;
  RawTextMapInput in(m);

  // Read the map from test.yolo
  in << "tests/graphtests/test.yolo"; // directed_30_100.yolo";

  // Start city, arbitrarily chosen for the test
  City* start = m.getCity(0);

  // End city, arbitrarily chosen for the test
  City* end = m.getCity(8);


  // Get the shortest path between the cities
  auto shortest_path = m.shortestPath(start, end, NULL, distance_cost);

  auto path = shortest_path.first;
  auto distance = shortest_path.second;

  cout << "Shortest path (distance) between " << *start << " and " << *end << ":" << endl;

  // Print the path
  for (auto c : path)
    cout << "\t* " << *c << endl;

  // Print the distance
  cout << "Distance: " << distance << "km" << endl;


  // Get the shortest path between the cities
  shortest_path = m.shortestPath(start, end, NULL, time_cost);

  path = shortest_path.first;
  auto time_ = shortest_path.second;

  cout << "Shortest path (time) between " << *start << " and " << *end << ":" << endl;

  // Print the path
  for (auto c : path)
    cout << "\t* " << *c << endl;

  // Print the distance
  cout << "Time: " << time_ << "h" << endl;

  return 0;
}
