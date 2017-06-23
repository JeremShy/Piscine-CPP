#include "Span.hpp"

Span::Span(void) {
}

Span::Span(unsigned int N) : _N(N){
}

Span::Span(Span const & src) : _N(src._N), _vec(src._vec){
}

Span::~Span(void) {
}

Span & Span::operator=(Span const & rhs) {
	this->_N = rhs._N;
	this->_vec = rhs._vec;

	return (*this);
}

void		Span::addNumber(int nbr) {
	if (_vec.size() >= _N) {
		throw std::out_of_range("The class has already reached it maximum storage capacity");
	}
	_vec.push_back(nbr);
}

int	Span::shortestSpan(void) const {
	if (_vec.size() <= 1) {
		throw std::exception();
	}

	std::vector<int>v2 = _vec;

	std::sort(v2.begin(), v2.end());
	int min = -1;
	std::vector<int>::iterator it;
	for (it = v2.begin(); it != v2.end() - 1; it++) {
		if ((*(it + 1) - *it < min) or min == -1) {
			min = *(it + 1) - *it;
		}
	}
	return (min);
}

int	Span::longestSpan(void) const {
	if (_vec.size() <= 1) {
		throw std::exception();
	}

	std::vector<int>::iterator it1;
	std::vector<int>::iterator it2;

	std::vector<int> v2 = _vec;

	it1 = min_element(v2.begin(), v2.end());
	it2 = max_element(v2.begin(), v2.end());

	return (*it2 - *it1);
}

void	Span::addElements(std::vector<int>::iterator const a, std::vector<int>::iterator const b) {
	for (std::vector<int>::iterator i = a; i != b; i++) {
		this->addNumber(*i);
	}
}
