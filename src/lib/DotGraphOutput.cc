#include "DotGraphOutput.hh"
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

template <typename V>
void DotGraphOutput<V>::output(string path) {

  cout << "Exporting " << this->graph_.name() << " to " << path << endl;

  ofstream st(path, ofstream::out);

  st << "digraph " << this->graph_.name() << " {" << endl;

  for (unsigned int i = 0; i < this->graph_.verticesNb(); i++)
    st << "\t" << i << " [label=\"" << this->graph_.getVertex(i).name() << "\"];" << endl;

  for (unsigned int i = 0; i < this->graph_.verticesNb(); i++)
    for (auto e : this->graph_.outgoingEdges(i)) {
      st << "\t" << i
	 << " -> " << e->getOtherEnd(i)
	 << " " << getEdgeStyle(e->type(), e->distance()) 
	 << ";" << endl;
    }

  st << "}" << endl;

  st.close();
}


template class DotGraphOutput<double>;
