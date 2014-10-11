
#ifndef EDGE_HH
#define EDGE_HH

#include <utility>

#include "EdgeType.hh"
#include "Vertex.hh"

using namespace std;

template <typename V>
class Edge {
private:
  unsigned int id_;

  EdgeType type_;
  
  V distance_;

  pair<unsigned int, unsigned int> vertices_;

public:
  /* Constructors */

  explicit Edge();
  explicit Edge(unsigned int id, unsigned int start, unsigned int end, EdgeType type, V dist);

  /* {Get,Set}ters */

  unsigned int id(void);

  EdgeType type(void);
  
  V& distance(void);
  void setDistance(V);

  V speed(void);

  pair<Vertex&, Vertex&>& vertices(void);

  /* Destructor */

  ~Edge() {}

};

#endif
