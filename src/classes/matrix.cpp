/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fly <fly@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/08 23:42:24 by fly               #+#    #+#             */
/*   Updated: 2018/03/09 18:17:42 by fly              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrix.hpp"

using namespace std;

Matrix::Matrix(string path) : is_valid(false)
{
	ifstream file;
	file.open(path);
	if (!file.is_open())
		return;
	retrieve_firstline(file);
	retrieve_board(file);
}

Matrix::Matrix() : is_valid(false)
{
	retrieve_firstline(cin);
	retrieve_board(cin);
}
