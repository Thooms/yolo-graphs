
#ifndef VERTEX_HH
#define VERTEX_HH

#include <string>
#include <utility>

#include "Nameable.hh"

using namespace std;

class Vertex : public Nameable {
private:
  unsigned int id_;

public:
  /* Constructors */

  explicit Vertex();
  explicit Vertex(unsigned int, string&);

  /* {Get, Set}ters */
  unsigned int id(void);

  /* Destructor */

  ~Vertex() {}
};

#endif
