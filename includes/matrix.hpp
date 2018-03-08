/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fly <fly@flyy.fr>                          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/08 01:20:38 by fly               #+#    #+#             */
/*   Updated: 2018/03/08 02:37:38 by fly              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATRIX_H
# define MATRIX_H

#include "generator.hpp"

class	Point	{
	private:
		int		x = 0;
		int		y = 0;
	public:
		Point(int x, int y);
		int		get_x(void);
		int		get_y(void);
};

class	Square	{
	private:
		Point	pos;
		int		size = 0;
	public:
		Square(Point pos, int size);
		int		get_size(void);
};

struct	Matrix {
	Point	size;
	Chars	chars;
	char	**b;

};

#endif
