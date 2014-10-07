
#ifndef EDGE_HH
#define EDGE_HH

#include "EdgeType.hh"

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


public:
  
  /* COUNTER behavior */
  static void counterIncr(void);
  static void counterDecr(void);
  static unsigned int getCounter(void);

  /* Constructors */

  explicit Edge();

  /* {Get,Set}ters */

  unsigned int id(void);

  EdgeType type(void);
  
  V distance(void);
  void setDistance(V);

  V speed(void);

  /* Destructor */

  ~Edge() {}

};

#endif
