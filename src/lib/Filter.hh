
#ifndef FILTER_HH
#define FILTER_HH

#include <functional>

#include "Edge.hh"


// Let GenericFilter see these two classes before we define them
template <typename V> class AndFilter;
template <typename V> class OrFilter;


template <typename V>
class GenericFilter {
public:
	explicit GenericFilter() {}

	virtual bool operator() (Edge<V>&) = 0;

	friend GenericFilter<V>& operator&& (GenericFilter<V>& left, GenericFilter<V>& right) {
		AndFilter<V>* filter = new AndFilter<V>(left, right);

		return *filter;
	}

	friend GenericFilter<V>& operator|| (GenericFilter<V>& left, GenericFilter<V>& right) {
		OrFilter<V>* filter = new OrFilter<V>(left, right);

		return *filter;
	}
};


template <typename V>
class AndFilter : public GenericFilter<V> {
private:
	GenericFilter<V> &left_, &right_;

public:
	explicit AndFilter(GenericFilter<V>& left, GenericFilter<V>& right)
		: left_(left), right_(right) {}

	bool operator() (Edge<V>& e) {
		return left_(e) && right_(e);
	}
};

template <typename V>
class OrFilter : public GenericFilter<V> {
private:
	GenericFilter<V> &left_, &right_;

public:
	explicit OrFilter(GenericFilter<V>& left, GenericFilter<V>& right)
		: left_(left), right_(right) {}

	bool operator() (Edge<V>& e) {
		return left_(e) || right_(e);
	}
};


template <typename V>
class Filter : public GenericFilter<V> {
private:
	std::function<bool (Edge<V>&)> filter_;

public:
	explicit Filter(std::function<bool (Edge<V>&)> filter)
		: filter_(filter) {}

	bool operator() (Edge<V>& e) {
		return filter_(e);
	}
};

#endif
