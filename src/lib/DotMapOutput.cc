#include "DotMapOutput.hh"
#include "EdgeType.hh"

#include <sstream>

template <typename V>
string getEdgeStyle(EdgeType t, V val) {
  
  stringstream ss;
  string end("\"]");

  switch (t) {
  case EdgeType::Plane:
    ss << string("[color=red, label=\"") << val << end;
    break;
  case EdgeType::Train:
    ss << string("[color=blue, style=dotted, label=\"") << val << end ;
    break;
  default:
    ss << string("[label=\"") << val << end;
    break;
  }
  return ss.str();
}

void DotMapOutput::output(string path) {

  ofstream st(path, ofstream::out);

  st << "digraph " << this->map_.name() << " {" << endl;

  for (unsigned int i = 0; i < this->map_.verticesNb(); i++)
    st << "\t" << i << " [label=\"" << this->map_.getVertex(i)->name() << "\"];" << endl;

  for (unsigned int i = 0; i < this->map_.verticesNb(); i++)
    for (auto e : this->map_.outgoingEdges(i)) {
      st << "\t" << i
	 << " -> " << e->getOtherEnd(i)
	 << " " << getEdgeStyle(e->type(), e->distance()) 
	 << ";" << endl;
    }

  st << "}" << endl;

  st.close();
}
