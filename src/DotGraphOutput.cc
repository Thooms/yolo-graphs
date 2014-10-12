#include "DotGraphOutput.hh"
#include "EdgeType.hh"

string getEdgeStyle(EdgeType t) {
  switch (t) {
  case EdgeType::Plane:
    return "[color=red]";
  case EdgeType::Train:
    return "[color=blue,style=dotted]";
  default:
    return "";
  }
}

template <typename V>
void DotGraphOutput<V>::output(string path) {

  cout << "Exporting " << this->graph_.name() << " to " << path << endl;

  ofstream st(path, ofstream::out);

  st << "digraph " << this->graph_.name() << " {" << endl;

  for (unsigned int i = 0; i < this->graph_.verticesNb(); i++)
    for (auto e : this->graph_.outgoingEdges(i)) {
      st << "\t" << this->graph_.getVertex(i).name()
	 << " -> " << this->graph_.getVertex(e->getOtherEnd(i)).name()
	 << " " << getEdgeStyle(e->type()) 
	 << ";" << endl;
    }

  st << "}" << endl;

  st.close();
}


template class DotGraphOutput<double>;
