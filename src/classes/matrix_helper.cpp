/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_helper.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fly <fly@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/09 15:17:51 by fly               #+#    #+#             */
/*   Updated: 2018/03/09 16:17:41 by fly              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrix.hpp"

using namespace std;

void	Matrix::retrieve_board(istream &in)
{
	std::string		line;

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
			size = Point(0, cur_y);
		else if (cur_y != size.get_y())
			return;
		size = Point(cur_x + 1, cur_y);
	}
	is_valid = true;
}

void	Matrix::resolve()
{
	for (int x = 1; x < size.get_x(); x++)
		for (int y = 1; y < size.get_y(); y++)
			if(board[x][y] == 1)
				board[x][y] = min(min(
					board[x - 1][y],
					board[x][y - 1]),
					board[x - 1][y - 1]) + 1;
}
