/****************************************************************************/
/*                                                                          */
/*                                                       :::      ::::::::  */
/*  myfind.c                                           :+:      :+:    :+:  */
/*                                                   +:+ +:+         +:+    */
/*  By: malamzad <marvin@42.fr>                    +#+  +:+       +#+       */
/*                                               +#+#+#+#+#+   +#+          */
/*  Created: 2015/12/06 11:42:24 by malamzad          #+#    #+#            */
/*  Updated: 2015/12/06 11:42:24 by malamzad         ###   ########.fr      */
/*                                                                          */
/****************************************************************************/

// #include "myincludes.h"

int		find_top_row(char **tab, int nrl)
{
	int top;

	top = -1;
	while (++top < nrl)
	{
		if (ft_strlen(tab[top]) > 0)
			break;
	}
	return (top);
}

int		find_bottom_row(char **tab, int nrl)
{
	int bottom;

	bottom = nrl;
	while (--bottom >= 0)
	{
		if (ft_strlen(tab[bottom]) > 0)
			break;
	}
	return (bottom);
}

int		find_right_col(char **tab, int nrl)
{
	int k;
	int right;
	int ln;

	k = -1;
	right = -100;
	while (++k < nrl)
	{
		ln = ft_strlen(tab[k]) - 1;
		if (ln > right)
			right = ln;
	}
	return (right);
}

int		find_left_col(char **tab, int nrl)
{
	int lig;
	int col;
	int left;
	char *p;

	left = -1;
	col = -1;
	while (ALWAYS)
	{
		lig = -1;
		++col;

		while (++lig < nrl)
		{
			p = tab[lig];
			if (p[col] == 0x00 || p[col] != ' ')
			{
				left = col;
				break;
			}
		}
		if (left >= 0)
			break;
	}
	return (left);
}
