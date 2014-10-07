
#ifndef VERTEX_HH
#define VERTEX_HH

#include <string>
#include <utility>

#include "Nameable.hh"

using namespace std;

class Vertex : public Nameable {
private:
  /* COUNTER is the latest available edge id, it is safe to use as
   * this, but do not forget to increment it afterwards.
   */
  static unsigned int COUNTER;

  unsigned int id_;
  pair<double, double> coordinates_;

public:

  /* COUNTER behavior */

  static void counterIncr(void);
  static void counterDecr(void);
  static unsigned int getCounter(void);

  /* Constructors */

  explicit Vertex();
  explicit Vertex(string&);
  explicit Vertex(string&, pair<double, double>&);

  /* {Get, Set}ters */
  unsigned int id(void);

  pair<double, double>& coordinates(void);

  /* Destructor */

  ~Vertex() {}
};

#endif
