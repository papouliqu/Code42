/****************************************************************************/
/*                                                                          */
/*                                                       :::      ::::::::  */
/*  dumperr.c                                          :+:      :+:    :+:  */
/*                                                   +:+ +:+         +:+    */
/*  By: malamzad <marvin@42.fr>                    +#+  +:+       +#+       */
/*                                               +#+#+#+#+#+   +#+          */
/*  Created: 2015/12/06 11:07:48 by malamzad          #+#    #+#            */
/*  Updated: 2015/12/06 11:07:48 by malamzad         ###   ########.fr      */
/*                                                                          */
/****************************************************************************/

#include <stdlib.h>
#include <stdio.h>

void	my_error(char *point)
{
	printf("\n<%s>", point);
	exit(-1);
}

void	dump_tab_char(char **tab, int size, char *name)
{
	int k;
	
	printf("\n### dump de : %s",name);
	k = -1;
	while (++k < size)
	{
		if (tab[k] != NULL)
			printf("\n%d <%s>", k, tab[k]);
		else
			printf("\n%d <NULL>", k);
	}
}

void	dump_tab_int(int *tab, int size, char *name)
{
	int k;
	
	printf("\n### dump de : %s",name);
	k = -1;
	while (++k < size)
		printf("\n%d - %6d",k,tab[k]);
}

