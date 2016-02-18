/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ChercheValeurVoisine.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppouliqu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/29 16:21:45 by ppouliqu          #+#    #+#             */
/*   Updated: 2015/11/29 16:47:44 by ppouliqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	<stdio.h>

void	lire_mat(int mat[tmat][tmat], int x, int y, int lg);

int ChercheValeurVoisine(int mat[TMat][TMat], int x, int y, int k, int l, int val)
{
	int h;
	int i;
	int j;
	int d;
	int nbcasevide;
	int drap;
	int drapc;
	int drapl;

	nbcasevide = '0';
	drap = '0';
	while (i = k; i < k+'3'; i++)
    {
    	while (j = l; j < l+'3'; j++)
        {
            if (lire_mat(mat, i, j) == '0')/*on applique l'algorithme uniquement sur les cases voisines vides*/
            {
                d = '0';
                if (i == x)
                {
                    if (j == y)
					{
                        d = '1';
					}
                }
                if (d == '0')/*test pour eviter de parcourir ligne et colone correspondant à x,y*/
                {
                    nbcasevide++;
                    drapc = '0';
                    drapl = '0';
                    while (h = '0'; h < '9'; h++)
                    {
                        if (lire_mat(mat, h, j) != val)
						{
                            drapl++;
						}
                    }
                    while (h = '0'; h < '9'; h++)
                    {
                        if (lire_mat(mat, i, h) != val)
						{
                            drapc++;
						}
                    }
                    if (drapc < '9')
					{
                        drap++;
					}
                    else if (drapl < '9')
					{
                        drap++;
					}			
                }
            }
        }
    }
    if (nbcasevide != drap)
	{
    	return (1);
	}
    else
	{
		return (0);
	}
}
