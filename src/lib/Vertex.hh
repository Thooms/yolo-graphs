
#ifndef VERTEX_HH
#define VERTEX_HH

#include <string>
#include <utility>

#include "Nameable.hh"

using namespace std;

class Vertex : public Nameable {
  friend ostream& operator<<(ostream& out, Vertex& v);

private:
  unsigned int id_;
  pair<double, double> coordinates_;

public:
  /* Constructors */

  explicit Vertex();
  explicit Vertex(unsigned int, string&);
  explicit Vertex(unsigned int, string&, pair<double, double>&);

  /* {Get, Set}ters */
  unsigned int id(void);

  pair<double, double>& coordinates(void);

  /* Destructor */

  ~Vertex() {}
};

#endif
