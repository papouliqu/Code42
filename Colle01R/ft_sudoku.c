/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sudoku.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppouliqu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/28 17:21:57 by ppouliqu          #+#    #+#             */
/*   Updated: 2015/11/29 17:16:58 by ppouliqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

char	ft_putchar(char c);

#DEFINE tmat 9
#DEFINE nb_execution_algorithme 10

int	ecrire_mat(int mat[tmat][tmat], int x, int y, int val)
{
	if ((('0' <= x) && (x < tmat)) && (('0' <= y) && (y < tmat)) &&
			(('0' <= val) && (val <= '9')))
	{
		mat[x][y] = val;
		return (0);
	}
	else
	{
		return (-1);
	}
}

int	lire_mat(int mat[tmat][tmat], int x, int y)
{
	if ((('0' <= x) && (x < tmat)) && (('0' <= y) && (y < tmat)))
	{
		return (mat[x][y]);
	}
	else
	{
		return (-1);
	}
}

void	ft_sudoku(void)
{
	char	b1;
	char	b2;
	char	b3;

	b1 = '0' - '1';
	while (b1++ <= '9')
	{
		b2 = b1 + '1';
		while (b2 <= '9')
		{
			b3 = b2 + '1';
			while (b3 <= '9')
			{
				ft_putchar(b1);
				ft_putchar(b2);
				ft_putchar(b3++);
				if (b1 != '7')
				{
					ft_putchar(',');
					ft_putchar(' ');
				}
			}
			b2++;
		}
	}
}
