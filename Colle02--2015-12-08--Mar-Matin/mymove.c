/****************************************************************************/
/*                                                                          */
/*                                                       :::      ::::::::  */
/* mymove.c                                            :+:      :+:    :+:  */
/*                                                   +:+ +:+         +:+    */
/*  By: malamzad <marvin@42.fr>                    +#+  +:+       +#+       */
/*                                               +#+#+#+#+#+   +#+          */
/*  Created: 2015/12/06 10:48:49 by malamzad          #+#    #+#            */
/*  Updated: 2015/12/06 10:49:34 by malamzad         ###   ########.fr      */
/*                                                                          */
/****************************************************************************/

// #include <stdio.h>
// #include "myincludes.h"

void	move_bottom_to_top(char ** tab, int *nrl)
{
	int	k;
	int	j;
	int	top;
	int	bottom;
	
	top = find_top_row(tab, *nrl);
	bottom = find_bottom_row(tab, *nrl);
	
	j = 0;
	k = top - 1;
	while (++k <= bottom)
		tab[j++] = tab[k];
	while (j < *nrl)
		tab[j++] = NULL;
	*nrl = bottom - top + 1;
	printf("\ntop %d    bottom %d", top, bottom);
	printf("\nnrL %d", *nrl);
}

void	move_right_to_left(char **tab, int nrl, int *nrcol)
{
	int row;
	int col;
	int right;
	int left;
	char *p;
	
	right = find_right_col(tab, nrl);
	printf("\nright : %d", right);
	left = find_left_col(tab, nrl);
	printf("\nleft  : %d", left);
	row = -1;
	while (++row < nrl)
	{
		col = left - 1;

		p = tab[row];
		while (++col <= right)
		{
			*p = *(p + left);
			++p;
		}
		*p = 0x00;
	}
	*nrcol = right - left + 1;
}

void	move_to_top_left(char **tab, int *nrligs, int *nrcols)
{
	dump_tab_char(tab, *nrligs,"** move_to_top_left.tab 1");
	printf("\n*nrligs : %d", *nrligs);
	move_bottom_to_top(tab, nrligs);
	printf("\n*nrligs2 : %d", *nrligs);

	dump_tab_char(tab, *nrligs,"** move_to_top_left.tab 2");
	move_right_to_left(tab, *nrligs, nrcols);
	dump_tab_char(tab, *nrligs,"** move_to_top_left.tab 3");
}
