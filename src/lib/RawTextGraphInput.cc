
#include "RawTextGraphInput.hh"

/*
  name
  |V|
  [|V| names]
  |E|
  [|E| lines formatted like start end type distance]
 */

template <typename V>
void RawTextGraphInput<V>::input(string path) {
  
  ifstream ifs(path, ifstream::in);
  
  int v, e;
  string title;

  // Graph title fetching

  ifs >> title;

  this->graph_.setName(title);

  // Vertices fetching

  ifs >> v;
  ifs.ignore();

  for (int i = 0; i < v; i++) {
    getline(ifs, title);
    std::cout << "Found " << title << std::endl;
    this->graph_.addVertex(title);
  }

  // Edges fetching

  unsigned int start, end;
  string type;
  EdgeType t;
  V dist;

  ifs >> e;

  for (int i = 0; i < e; i++) {
    ifs >> start >> end >> type >> dist;
    if (type == "Train")
      t = EdgeType::Train;
    else if (type == "Road")
      t = EdgeType::Road;
    else
      t = EdgeType::Plane;

    this->graph_.addEdge(t, dist, start, end);
  }
}

template class RawTextGraphInput<double>;
