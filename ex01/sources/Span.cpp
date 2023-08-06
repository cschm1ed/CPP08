

#include <Span.hpp>

Span::Span(unsigned int n) : _size(n), _contains(0){
	std::cout << BLACK"Span constructor called\n"R;
}

Span::Span() {
	std::cout << BLACK"Span default constructor called\n"R;
}

Span::~Span() {
	std::cout << BLACK"Span default destructor called\n"R;
}

Span::Span(Span const &other) : _vec(other._vec) {
	std::cout << "Span copy constructor called\n";
}

Span &Span::operator=(Span const &rhs) {
	_vec = rhs._vec;
	return *this;
}

void Span::addNumber(int n) {
	if (_contains == _size) {
		throw spanOverflowException();
	}
	_vec.push_back(n);
	_contains += 1;
}

unsigned int Span::shortestSpan() {
	if (_size == 1) {
		return 0;
	}

	unsigned int tmp;
	unsigned int shortest = std::numeric_limits<unsigned int>::max();
	std::vector<int> sorted = _vec;
	std::sort(sorted.begin(), sorted.end());

	std::vector<int>::const_iterator it;
	std::vector<int>::const_iterator ite = sorted.end();

	for (it = sorted.begin(); it + 1 != ite; it++) {
		tmp = *it < *(it + 1) ? *(it + 1) - *it : *it - *(it + 1);
		if (tmp < shortest) {
			shortest = tmp;
		}
	}

	return shortest;
}

unsigned int Span::longestSpan() {
	std::vector<int> sorted = _vec;

	std::sort(sorted.begin(), sorted.end());
	return *(sorted.end() - 1) - *sorted.begin();
}

const char *Span::spanOverflowException::what() const throw() {
	return "cannot add number to container";
}
