/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fly <fly@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/08 01:20:38 by fly               #+#    #+#             */
/*   Updated: 2018/03/09 18:14:14 by fly              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATRIX_H
# define MATRIX_H

#include <vector>
#include <fstream>
#include "generator.hpp"

class	Point	{
	private:
		int	x;
		int	y;
	public:
		Point(int x, int y);
		Point();
		int	get_x();
		int	get_y();
};

class	Square	{
	private:
		Point	pos;
		int		size;
	public:
		Square(Point pos, int size);
		Square();
		Point	get_pos();
		int		get_size();
};

class	Matrix {
	private:
		bool							is_valid;
		Point							size;
		Chars							chars;
		Square							biggest;
		std::vector<std::vector<int>>	board;
		void							retrieve_board(std::istream &in);
		void							retrieve_firstline(std::istream &in);
	public:
		Matrix(std::string path);
		Matrix();
		void							resolve();
		void							print();
};

#endif
