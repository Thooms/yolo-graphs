#include <iostream>
#include <string>
#include <utility>

#include "DotMapOutput.hh"
#include "Filter.hh"
#include "Map.hh"
#include "RawTextMapInput.hh"

using namespace std;

/******* Read data from stdin **************/

void read_input(string message, string* value) {
    cout << message << endl;
    getline(cin, *value);
}

void read_input(string message, double* value) {
    cout << message << endl;
    cin >> *value;
    cin.ignore();

    if (*value <= 0.0)
        read_input(message, value);
}

void read_input(string message, EdgeType* type) {
    string input;
    
    cout << message << endl;
    cin >> input;

    if (input == "Road")
        *type = EdgeType::Road;
    else if (input == "Train")
        *type = EdgeType::Train;
    else if (input == "Plane")
        *type = EdgeType::Plane;
    else // Ask again if type is wrong
        read_input(message, type);
}

/*******************************************/

void print_cities(Map *m) {
    cout << "Cities available:" << endl;
    
    for (unsigned int i = 0; i < m->verticesNb(); ++i)
        cout << "\t* " << *m->getCity(i) << endl;

    cout << endl;
}

void print_links(Map* m) {
    cout << "Links available:" << endl;

    for (unsigned int i = 0; i < m->edgesNb(); ++i) {
        auto edge = m->getEdge(i);

        auto cities = edge.vertices();
        cout << "\t* " << *m->getCity(cities.first) << " - ";
        cout << *m->getCity(cities.second) << " - " << edge.distance();
        cout << "km" << endl;
    }
}

City* city_by_name(string name, Map* m) {
    for (unsigned int i = 0; i < m->verticesNb(); ++i) {
        City* c = m->getCity(i);
        
        if (c->name() == name)
            return c;
    }

    return NULL;
}

// Add a new link between two cities
void add_link(Map* m, string city1, string city2, EdgeType type, double distance) {
    City* c1 = city_by_name(city1, m);
    City* c2 = city_by_name(city2, m);

    if ((c1 == NULL) || (c2 == NULL)) {
        cout << "Invalid city name" << endl;
        return;
    }

    switch (type) {
    case EdgeType::Road:
        m->addRoad(distance, c1, c2);
        break;

    case EdgeType::Train:
        m->addTrain(distance, c1, c2);
        break;

    case EdgeType::Plane:
        m->addPlane(distance, c1, c2);
        break;
    }
}

int menu(void) {
    int result;
    
    cout << "What to do?" << endl;
    cout << "\t1. Neighbors of a city" << endl;
    cout << "\t2. Neighbors & neighbors of neighbors of a city" << endl;
    cout << "\t3. All neighbors of a city" << endl;
    cout << "\t4. Shortest path between two cities" << endl;
    cout << "\t5. Exit" << endl;

    cin >> result;
    cin.ignore();

    if ((result < 1) || (result > 5))
        return menu();

    return result;
}

void neighbors(Map* m) {
    string name;
    read_input("Enter city name:", &name);

    City* city = city_by_name(name, m);

    if (city == NULL)
        neighbors(m);

    auto cities = m->neighbors(city, NULL);

    for (auto c : cities)
        cout << "\t* " << *c << endl;
}

void neighbors_neighbors(Map* m) {
    string name;
    read_input("Enter city name:", &name);

    City* city = city_by_name(name, m);

    if (city == NULL)
        neighbors_neighbors(m);

    auto cities = m->neighborsOfNeighbors(city, NULL);

    for (auto c : cities)
        cout << "\t* " << *c << endl;
}

void all_neighbors(Map* m) {
    string name;
    read_input("Enter city name:", &name);

    City* city = city_by_name(name, m);

    if (city == NULL)
        all_neighbors(m);

    auto cities = m->allNeighbors(city, NULL);

    for (auto c : cities)
        cout << "\t* " << *c << endl;
}

void shortest_path(Map* m) {
    string city1, city2;
    read_input("Enter start city name:", &city1);
    read_input("Enter end city name:", &city2);

    City* c1 = city_by_name(city1, m);
    City* c2 = city_by_name(city2, m);

    if ((c1 == NULL) || (c2 == NULL))
        shortest_path(m);

    auto path = m->shortestPath(c1, c2, NULL);

    for (auto c : path.first)
        cout << *c << " -> ";

    cout << "Distance: " << path.second << endl;
}

int main(void) {
    Map m;
    string input;
    string city1, city2;
    EdgeType edge_type;
    double distance;
    bool done;
    
    read_input("Name of the map:", &input);

    m.setName(input);

    read_input("Enter new city name:", &input);
    
    do {
        m.addCity(input);
        read_input("Enter new city name: (EOF when done)", &input);
    } while(input != "EOF");

    cout << "Now adding links between cities." << endl;

    print_cities(&m);

    read_input("First city:", &city1);
    read_input("Second city:", &city2);
    read_input("Edge type: (Road, Train or Plane", &edge_type);
    read_input("Distance: (> 0)", &distance);

    do {
        add_link(&m, city1, city2, edge_type, distance);
        read_input("First city: (EOF when done)", &city1);

        if (city1 == "EOF")
            break;

        read_input("Second city:", &city2);
        read_input("Edge type: (Road, Train or Plane", &edge_type);
        read_input("Distance: (> 0)", &distance);
    } while (true);

    print_links(&m);

    done = false;

    do {
        switch (menu()) {
        case 1:
            neighbors(&m);
            break;
        case 2:
            neighbors_neighbors(&m);
            break;
        case 3:
            all_neighbors(&m);
            break;
        case 4:
            shortest_path(&m);
            break;
        case 5:
            done = true;
            break;
        }
    } while (!done);
    
    return 0;
}
