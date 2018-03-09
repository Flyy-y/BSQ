/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fly <fly@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/08 23:42:24 by fly               #+#    #+#             */
/*   Updated: 2018/03/09 16:34:23 by fly              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrix.hpp"

using namespace std;

Matrix::Matrix(string path) : is_valid(false)
{
	chars.obstacle = 'o';
	chars.empty = '1';
	
	ifstream file;
	file.open(path);
	if (!file.is_open())
		return;
	retrieve_board(file);
	resolve();
}

Matrix::Matrix() : is_valid(false)
{
	chars.obstacle = '^';
	chars.empty = 'Y';
	retrieve_board(cin);
}
