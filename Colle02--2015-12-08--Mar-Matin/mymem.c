/****************************************************************************/
/*                                                                          */
/*                                                       :::      ::::::::  */
/*  mymem.c                                            :+:      :+:    :+:  */
/*                                                   +:+ +:+         +:+    */
/*  By: malamzad <marvin@42.fr>                    +#+  +:+       +#+       */
/*                                               +#+#+#+#+#+   +#+          */
/*  Created: 2015/12/06 10:46:21 by malamzad          #+#    #+#            */
/*  Updated: 2015/12/06 14:15:39 by malamzad         ###   ########.fr      */
/*                                                                          */
/****************************************************************************/

// #include <stdlib.h>

void	free_tab_mem(char **tab, int nrl)
{
	int k=-1;
	while (++k < nrl)
		free(tab[k]);
	free(tab);
}

void	set_tab(int *t, int nrelem, int val)
{
	int k;
	int *pi;
	
	k = -1;
	pi = t;
	while(++k<nrelem)
		*(pi++) = val;
}
