//
// Created by Christian Schmiedt on 8/6/23.
//

#ifndef CPP08_SPAN_HPP
#define CPP08_SPAN_HPP

#include <iostream>
#include <colors.hpp>
#include <vector>

class Span {

public:
	Span(unsigned int n);

	Span(Span const &other);

	~Span();

	Span &operator=(Span const &rhs);

	void addNumber(int);

	unsigned int	shortestSpan();
	unsigned int	longestSpan();
class spanOverflowException : public std::exception {
	const char *what() const _NOEXCEPT;
};

private:
	Span();
	std::vector<int> _vec;

	unsigned int _size;
	unsigned int _contains;
};


#endif //CPP08_SPAN_HPP
