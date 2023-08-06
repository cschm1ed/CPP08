/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschmied <cschmied@student.42wolfsburg.d>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 13:18:00 by cschmied          #+#    #+#             */
/*   Updated: 2023/08/06 13:18:00 by cschmied         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_TPP
#define EASYFIND_TPP

#include <easyfind.hpp>

template <typename T>
int	find(const T& container, int n) {
	typename T::const_iterator	it;
	typename T::const_iterator	ite = container.end();

	for (it = container.begin(); it != ite; it++) {
		if (*it == n) {
			return it - container.begin();
		}
	}
	return -1;
}

#endif
