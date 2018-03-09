/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   square.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fly <fly@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/08 02:31:57 by fly               #+#    #+#             */
/*   Updated: 2018/03/09 13:48:12 by fly              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrix.hpp"

Square::Square(Point pos, int size) : pos(pos), size(size) {}

Square::Square() : size(0) {}

Point	Square::get_pos()
{
	return (pos);
}

int		Square::get_size()
{
	return (size);
}
