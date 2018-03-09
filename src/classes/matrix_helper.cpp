/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_helper.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fly <fly@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/09 15:17:51 by fly               #+#    #+#             */
/*   Updated: 2018/03/09 18:30:20 by fly              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrix.hpp"

using namespace std;

void	Matrix::retrieve_firstline(istream &in)
{
	string	line;

	getline(in, line);
	chars.empty = line.c_str()[line.size() - 3];
	chars.obstacle = line.c_str()[line.size() - 2];
	chars.filling = line.c_str()[line.size() - 1];
	line.resize(line.size() - 3);
	size = Point(atoi(line.c_str()), 0);
}

void	Matrix::retrieve_board(istream &in)
{
	string	line;

	for (int cur_x = 0; getline(in, line); cur_x++)
	{
		int cur_y = 0;
		for(; cur_y < (int)line.length(); cur_y++)
		{
			board.resize(cur_x + 1);
			if (line[cur_y] != chars.empty && line[cur_y] != chars.obstacle)
				return;
			if (line[cur_y] == chars.obstacle)
				board[cur_x].push_back(0);
			else
				board[cur_x].push_back(1);
		}
		if (cur_x == 0)
			size = Point(size.get_x(), cur_y);
		else if (cur_y != size.get_y())
			return;
	}
	is_valid = true;
}

void	Matrix::resolve()
{
	for (int x = 1; x < size.get_x(); x++)
		for (int y = 1; y < size.get_y(); y++)
			if(board[x][y] == 1)
			{
				board[x][y] = min(min(
					board[x - 1][y],
					board[x][y - 1]),
					board[x - 1][y - 1]) + 1;
				if(board[x][y] > biggest.get_size())
				{
					Point pos(x - (board[x][y] - 1), y - (board[x][y] - 1));
					biggest = Square(pos, board[x][y]);
				}
			}
}

void	Matrix::print()
{
	string line;
	if (!is_valid)
	{
		cerr << "map error" << endl;
		return;
	}
	for (int x = 0; x < size.get_x(); x++)
	{
		line = "";
		for (int y = 0; y < size.get_y(); y++)
		{
			if (board[x][y] < 1)
				line.append(&chars.obstacle, 1);
			else if (x >= biggest.get_pos().get_x() &&
					x < biggest.get_pos().get_x() + biggest.get_size() &&
					y >= biggest.get_pos().get_y() &&
					y < biggest.get_pos().get_y() + biggest.get_size()
			)
				line.append(&chars.filling, 1);
			else
				line.append(&chars.empty, 1);
		}
		cout << line << endl;
	}
}
