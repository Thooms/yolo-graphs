#include "UndirectedGraph.hh"

template <typename V>
unsigned int UndirectedGraph<V>::addEdge(EdgeType type, V distance, unsigned int start, unsigned int end) {
	Edge<V> e = Edge<V>(this->edges_nb_, start, end, type, distance);
	this->edges_nb_++;

	if ((start >= this->vertices_nb_) || (end >= this->vertices_nb_))
    	return -1;

    this->adjacency_[start].second.push_back(e.id());
    this->adjacency_[end].second.push_back(e.id());

    this->edges_.push_back(e);

    return e.id();
}

// Types of directed graphs that can be instantiated
template class UndirectedGraph<double>;
template class UndirectedGraph<float>;
template class UndirectedGraph<int>;
