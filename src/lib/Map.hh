
#ifndef MAP_HH
#define MAP_HH

#include <string>
#include <vector>
#include <utility>

#include "ComputationUnit.hh"
#include "UndirectedGraph.hh"
#include "EdgeType.hh"
#include "Edge.hh"
#include "Vertex.hh"

using namespace std;


class City : public Vertex {
private:
    double lat_, lon_;

public:
    explicit City(string name);
    explicit City(string name, double lat, double lon);
};


class Map : public UndirectedGraph<double> {
public:
    City* addCity(string name);
    City* addCity(string name, double lat, double lon);

    City* getCity(unsigned int);

    unsigned int addRoad(double distance, City* start, City* end);
    unsigned int addTrain(double distance, City* start, City* end);
    unsigned int addPlane(double distance, City* start, City* end);

    std::vector<City*> neighbors(City*, GenericFilter<double>*);
    std::vector<City*> neighborsOfNeighbors(City*, GenericFilter<double>*);
    std::vector<City*> allNeighbors(City*, GenericFilter<double>*);

    pair<vector<City*>, double> shortestPath(City* start, City* end, GenericFilter<double>* filter, std::function<double (Edge<double>)> cost);

private:
    std::vector<City*> neighbors_depth(City*, unsigned int, GenericFilter<double>*);
};

#endif
