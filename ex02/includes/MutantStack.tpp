/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschmied <cschmied@student.42wolfsburg.d>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 12:02:32 by cschmied          #+#    #+#             */
/*   Updated: 2023/08/09 10:52:25 by cschmied         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_TPP
#define MUTANTSTACK_TPP

#include <MutantStack.hpp>

template<typename T>
MutantStack<T>::MutantStack() {
	std::cout << "MutantStack default constructor called\n";
}

template<typename T>
MutantStack<T>::~MutantStack() {
	std::cout << "MutantStack destructor called\n";
}

template<typename T>
MutantStack<T>::MutantStack(const MutantStack<T> &other) : std::stack<T>(other) {
	std::cout << "MutantStack copy constructor called\n";
}

template<typename T>
MutantStack<T> &MutantStack<T>::operator=(const MutantStack<T> &rhs) {
	if (this != rhs) {
		return std::stack<T>::operator=(rhs);
	}
	return *this;
}


template<typename T>
typename MutantStack<T>::iterator MutantStack<T>::begin() {
	return this->c.begin();
}

template<typename T>
typename MutantStack<T>::iterator MutantStack<T>::end() {
	return this->c.end();
}

template<typename T>
typename MutantStack<T>::const_iterator MutantStack<T>::begin() const {
	return this->c.begin();
}

template<typename T>
typename MutantStack<T>::const_iterator MutantStack<T>::end() const {
	return this->c.end();
}

#endif
