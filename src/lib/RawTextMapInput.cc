
#include "RawTextMapInput.hh"

/*
  name
  |V|
  [|V| names]
  |E|
  [|E| lines formatted like start end type distance]
 */

void RawTextMapInput::input(string path) {
  
  ifstream ifs(path, ifstream::in);
  
  int v, e;
  string title;

  // Graph title fetching

  ifs >> title;

  this->map_.setName(title);

  // Vertices fetching

  ifs >> v;
  ifs.ignore();

  for (int i = 0; i < v; i++) {
    getline(ifs, title);
    this->map_.addCity(title);
  }

  // Edges fetching

  unsigned int start, end;
  string type;
  double dist;

  ifs >> e;

  for (int i = 0; i < e; i++) {
    ifs >> start >> end >> type >> dist;

    City* s = this->map_.getCity(start);
    City* e = this->map_.getCity(end);

    if (type == "Train")
      this->map_.addTrain(dist, s, e);
    else if (type == "Road")
      this->map_.addRoad(dist, s, e);
    else
      this->map_.addPlane(dist, s, e);
  }
}
