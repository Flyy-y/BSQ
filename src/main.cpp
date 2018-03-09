/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fly <fly@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/08 01:20:47 by fly               #+#    #+#             */
/*   Updated: 2018/03/09 16:36:20 by fly              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.hpp"
#include "matrix.hpp"

using namespace std;

int	main(int argc, char **argv)
{
	Matrix t(string("test"));
	if (argc == 2)
		if (string(argv[1]) == string("-g"))
			return (generator());
}