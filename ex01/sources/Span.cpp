/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschmied <cschmied@student.42wolfsburg.d>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 12:48:15 by cschmied          #+#    #+#             */
/*   Updated: 2023/08/10 12:49:00 by cschmied         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span() {
	std::cout << "Span default constructor called\n";
}

Span::Span(unsigned int const size) : _size(size), _count(0) {
	std::cout << BLACK"Span constructor called\n"R;
	_vec.reserve(size);
}

Span::~Span() {
	std::cout << BLACK"Span default destructor called\n"R;
}

Span::Span(Span const &other) : _size(other._size){
	std::cout << "Span copy constructor called\n";
}

Span &Span::operator=(Span const &rhs) {
	_size = rhs._size;
	_vec = rhs._vec;
	return *this;
}

const std::vector<int> &Span::getVec() const {
	return _vec;
}

unsigned int Span::getCount() const {
	return _count;
}

void Span::addNumber(int n) {
	if (_count == _size) {
		throw SpanOverflowException();
	}
	_count ++;
	_vec.push_back(n);
}

void Span::addRange(std::vector<int>::const_iterator it, std::vector<int>::const_iterator ite) {
	if (_size - _count < ite - it) {
		throw SpanOverflowException();
	}
	_count += ite - it;
	_vec.insert(_vec.end(), it, ite);
}

const char *Span::SpanOverflowException::what() const throw() {
	return "SpanOverflowException";
}

int	Span::shortestSpan() const {
	int shortest = INT_MAX;
	std::vector<int> sorted;
	if (_count <= 1) {
		return 0;
	}

	sorted = _vec;
	std::sort(sorted.begin(), sorted.end());
	std::vector<int>::const_iterator	it;
	std::vector<int>::const_iterator ite = sorted.end();
	for (it = sorted.begin(); it + 1 != ite; it++) {
		if (*(it + 1) - *it < shortest)
			shortest = *(it + 1) - *it;
	}
	return shortest;
}

int Span::longestSpan() const {
	return *std::max_element(_vec.begin(), _vec.end()) -*std::min_element(_vec.begin(), _vec.end());
}
