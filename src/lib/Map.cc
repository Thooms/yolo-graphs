#include "Map.hh"

using namespace std;

City::City(string name) : Vertex(0, name) {
    lat_ = lon_ = 0.0;
}

City::City(string name, double lat, double lon) : City(name) {
    lat_ = lat;
    lon_ = lon;
}


City* Map::addCity(string name) {
    City* c = new City(name);

    addVertex(c);

    return c;
}

City* Map::addCity(string name, double lat, double lon) {
    City* c = new City(name, lat, lon);

    addVertex(c);

    return c;
}

City* Map::getCity(unsigned int id) {
    return (City*)getVertex(id);
}

unsigned int Map::addRoad(double distance, City* start, City* end) {
    return addEdge(EdgeType::Road, distance, start->id(), end->id());
}

unsigned int Map::addTrain(double distance, City* start, City* end) {
    return addEdge(EdgeType::Train, distance, start->id(), end->id());
}

unsigned int Map::addPlane(double distance, City* start, City* end) {
    return addEdge(EdgeType::Plane, distance, start->id(), end->id());
}

vector<City*> Map::neighbors(City* city, GenericFilter<double>* filter) {
    return neighbors_depth(city, 2, filter);
}

vector<City*> Map::neighborsOfNeighbors(City* city, GenericFilter<double>* filter) {
    return neighbors_depth(city, 3, filter);
}

vector<City*> Map::allNeighbors(City* city, GenericFilter<double>* filter) {
    return neighbors_depth(city, 0, filter);
}

pair<vector<City*>, double> Map::shortestPath(City* start, City* end, GenericFilter<double>* filter) {
    auto& cu = ComputationUnit<double>::instance();
    cu.setGraph(this);

    auto shortest = cu.shortestPath(start->id(), end->id(), filter);

    pair<vector<City*>, double> result;

    result.first.resize(shortest.first.size());

    for (unsigned int i = 0; i < shortest.first.size(); ++i)
        result.first[i] = (City*)shortest.first[i];

    result.second = shortest.second;

    shortest.first.clear();

    return result;
}

vector<City*> Map::neighbors_depth(City* city, unsigned int depth, GenericFilter<double>* filter) {
    auto& cu = ComputationUnit<double>::instance();
    cu.setGraph(this);

    auto vertices = cu.bfs(city->id(), depth, filter);

    vector<City*> result(vertices.size(), NULL);

    for (auto i = 0; i < vertices.size(); ++i)
        result[i] = (City*)vertices[i];

    vertices.clear();

    return result;
}
