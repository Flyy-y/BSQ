/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fly <fly@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/08 01:20:47 by fly               #+#    #+#             */
/*   Updated: 2018/03/09 18:16:26 by fly              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.hpp"
#include "matrix.hpp"

using namespace std;

int	main(int argc, char **argv)
{
	if (argc == 1)
	{
		Matrix m;
		m.resolve();
		m.print();
	}
	if (argc > 1)
	{
		if (string(argv[1]) == string("-g"))
			return (generator());
		for (int i = 1; i < argc; i++)
		{
			Matrix m(argv[i]);
			m.resolve();
			m.print();
		}
	}
}