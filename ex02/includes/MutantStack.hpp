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

#ifndef CPP08_MUTANTSTACK_HPP
#define CPP08_MUTANTSTACK_HPP

#include <iostream>
#include <stack>


template<typename T>
class MutantStack : public std::stack<T> {
public:

	MutantStack();

	MutantStack(MutantStack<T> const &other);

	~MutantStack();

	MutantStack<T> &operator=(MutantStack<T> const &rhs);

	typedef typename std::stack<T>::container_type::iterator iterator;
	typedef typename std::stack<T>::container_type::const_iterator const_iterator;

	iterator begin();

	iterator end();

	const_iterator begin() const;

	const_iterator end() const;


private:

};


#endif //CPP08_MUTANTSTACK_HPP
