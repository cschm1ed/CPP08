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

#include <easyfind.hpp>
#include <easyfind.tpp>
#include <colors.hpp>
#include <vector>
#include <stack>
#include <array>

int main() {
	std::vector<int> vec;

	vec.push_back(1);
	vec.push_back(2);
	vec.push_back(3);
	std::cout << GREEN"----test int vector----\n";
	std::cout << BLUE"vector: 1, 2, 3\n"R;
	std::cout << "find(vec, 2): " << ::find(vec, 2) << "\n";
	std::cout << "find(vec, 5): " << ::find(vec, 5) << "\n";
	return 0;
}
