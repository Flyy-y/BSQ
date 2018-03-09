/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generator.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fly <fly@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/08 01:20:45 by fly               #+#    #+#             */
/*   Updated: 2018/03/09 16:50:34 by fly              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "generator.hpp"

using namespace std;

float	random_float()
{
	return ((float)rand() / RAND_MAX);
}

Chars	get_chars()
{
	Chars	c;

	c.empty = 0;
	c.obstacle = 0;
	c.filling = 0;
	while (c.empty == c.obstacle || c.empty == c.filling || c.obstacle == c.filling)
	{
		c.empty = (random_float() * 94) + 32;
		c.obstacle = (random_float() * 94) + 32;
		c.filling = (random_float() * 94) + 32;
	}
	return (c);
}

void	print_board(Chars c, int size_x, int size_y, float density)
{
	string line("");

	cout << size_x << c.empty << c.obstacle << c.filling << endl;
	for (int i = 0; i < size_x; i++)
	{
		line = "";
		for (int j = 0; j < size_y; j++)
		{
			if (random_float() > density)
				line.append(&c.empty, 1);
			else
				line.append(&c.obstacle, 1);
		}
		cout << line << endl;
	}
}

int		generator()
{
	int		size_x;
	int		size_y;
	float	density;

	srand(time(0) * clock());
	cerr << "Vertical size" << endl;
	cin >> size_x;
	cerr << "Horizontal size" << endl;
	cin >> size_y;
	cerr << "Density in percents" << endl;
	cin >> density;
	density /= 100;
	print_board(get_chars(), size_x, size_y, density);
	return (0);
}
