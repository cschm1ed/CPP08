/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschmied <cschmied@student.42wolfsburg.d>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 12:47:56 by cschmied          #+#    #+#             */
/*   Updated: 2023/08/10 12:47:56 by cschmied         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <Span.hpp>

int main()
{
	srand(time(NULL));
	{
		std::cout << BLUE"-----test from the subject-----\n"R;
		Span sp = Span(5);
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	}
	std::cout << "\n";
	{
		std::cout << BLUE"------test with 10 000 random numbers-----\n"R;
		Span sp = Span(10000);

		for (int i = 0; i < 10000; i++) {
			try {
				sp.addNumber(rand());
			} catch (std::exception & e) {
				std::cerr << RED"an exception occured: " << e.what() << "\n"R;
				return 1;
			}
		}

		int maxElement = *std::max_element(sp.getVec().begin(), sp.getVec().end());
		int minElement = *std::min_element(sp.getVec().begin(), sp.getVec().end());
		std::cout << "shortest span: " << sp.shortestSpan() << "\n";
		std::cout << "longest span: " << sp.longestSpan() << "\n";
		std::cout << "largest - smallest: " << maxElement - minElement << "\n";
	}
	std::cout << "\n";
	{
		std::cout << BLUE"-----tests using range to add numbers------\n";
		Span sp(10000);

		std::vector<int>vec(10000);
		std::generate(vec.begin(), vec.end(), std::rand);
		try {
			sp.addRange(vec.begin(), vec.end());
		} catch (std::exception & e) {
			std::cerr << RED"an exception occured: " << e.what() << "\n"R;
		}
		int maxElement = *std::max_element(sp.getVec().begin(), sp.getVec().end());
		int minElement = *std::min_element(sp.getVec().begin(), sp.getVec().end());
		std::cout << "shortest span: " << sp.shortestSpan() << "\n";
		std::cout << "longest span: " << sp.longestSpan() << "\n";
		std::cout << "largest - smallest: " << maxElement - minElement << "\n";
	}
	return 0;
}
