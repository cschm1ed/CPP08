/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschmied <cschmied@student.42wolfsburg.d>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 13:15:28 by cschmied          #+#    #+#             */
/*   Updated: 2023/08/06 13:15:28 by cschmied         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <MutantStack.tpp>
#include <iostream>
#include <colors.hpp>

int main() {
	MutantStack<int> stack;

	for (int i = 0; i < 10; i++) {
		stack.push(i);
	}

	std::cout << "\n\n";
	std::cout << BLUE"----iterator test----\n"R;
	std::cout << GREEN"content of stack:\n"R;

	MutantStack<int>::iterator it;
	MutantStack<int>::iterator ite = stack.end();

	for (it = stack.begin(); it != ite; it++) {
		std::cout << *it << ", ";
	}

	std::cout << "\n\n";
	std::cout << BLUE"----test copy constructor and assignment----\n"R;
	MutantStack<int> stackCopy(stack);

	MutantStack<int>::iterator itC;
	MutantStack<int>::iterator iteC = stackCopy.end();

	std::cout << GREEN"content of stackCopy:\n"R;
	for (itC = stackCopy.begin(); itC != iteC; itC++) {
		std::cout << *itC << ", ";
	}
	std::cout << "\n";

	MutantStack<int> cpy = stack;

	MutantStack<int>::iterator itCpy;
	MutantStack<int>::iterator iteCpy = stackCopy.end();

	std::cout << GREEN"content of copied stack:\n"R;
	for (itCpy = stackCopy.begin(); itCpy != iteCpy; itCpy++) {
		std::cout << *itCpy << ", ";
	}

	std::cout << "\n\n";

	std::cout << BLUE"----test some operations----\n"R;

	MutantStack<std::string> strStack;

	strStack.push("Hello World");
	strStack.push("Climate crisis");
	strStack.push("Goodbye World");

	std::cout << "stack: Hello World, Climate crisis, Goodbye World\n";
	std::cout << YELLOW"stack.top(): "R << strStack.top() << "\n";
	std::cout << YELLOW"stack.size(): "R << strStack.size() << "\n";
	std::cout << MAGENTA"stack.pop() x3\n"R;
	strStack.pop();
	strStack.pop();
	strStack.pop();
	std::cout << YELLOW"stack.empty(): "R << strStack.empty() << "\n";

	std::cout << "\n\n";

	return 0;
}
