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

// Add a new link between two cities
void add_link(Map* m, string city1, string city2, EdgeType type, double distance) {
    City* c1 = NULL;
    City* c2 = NULL;
    
    for (unsigned int i = 0; i < m->verticesNb(); ++i) {
        City* c = m->getCity(i);
        
        if (c->name() == city1)
            c1 = c;

        if (c->name() == city2)
            c2 = c;
    }

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

int main(void) {
    Map m;
    string input;
    string city1, city2;
    EdgeType edge_type;
    double distance;
    
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

    cout << "Map created" << endl;
    
    return 0;
}
