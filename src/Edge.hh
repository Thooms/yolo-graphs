
#ifndef EDGE_HH
#define EDGE_HH

#include <utility>

#include "EdgeType.hh"
#include "Vertex.hh"

using namespace std;

template <typename V>
class Edge {
private:
  /* COUNTER is the latest available edge id, it is safe to use as
   * this, but do not forget to increment it afterwards. 
   */
  static unsigned int COUNTER;

  unsigned int id_;

  EdgeType type_;
  
  V distance_;

  pair<Vertex&, Vertex&> vertices_;

public:
  
  /* COUNTER behavior */
  static void counterIncr(void);
  static void counterDecr(void);
  static unsigned int getCounter(void);

  /* Constructors */

  explicit Edge();
  explicit Edge(Vertex&, Vertex&, EdgeType, V);

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
