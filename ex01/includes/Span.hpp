/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschmied <cschmied@student.42wolfsburg.d>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 12:48:15 by cschmied          #+#    #+#             */
/*   Updated: 2023/08/10 12:48:27 by cschmied         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CPP08_SPAN_HPP
#define CPP08_SPAN_HPP

#include <iostream>
#include <vector>
#include <colors.hpp>

class Span {

public:
	Span(unsigned int const size);
	Span(Span const &other);
	~Span();

	Span &operator=(Span const &rhs);

	void addNumber(int n);
	void addRange(std::vector<int>::const_iterator it, std::vector<int>::const_iterator ite);

	const std::vector<int> &getVec() const;

	int	shortestSpan() const;
	int	longestSpan() const;

	unsigned int getCount() const;

class SpanOverflowException : public std::exception {
	const char *what() const _NOEXCEPT;
};

private:

	std::vector<int> _vec;
	unsigned int	_size;
	unsigned int	_count;

	Span();
};


#endif //CPP08_SPAN_HPP
