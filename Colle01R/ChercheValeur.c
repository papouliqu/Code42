/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ChercheValeur.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppouliqu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/29 16:28:36 by ppouliqu          #+#    #+#             */
/*   Updated: 2015/11/29 16:45:03 by ppouliqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	ChercheValeurVoisine();
void	lire_mat(int mat[tmat][tmat], int i, int y, int tab[i]);
void	ecrire_mat(int mat[tmat][tmat], int i, int y, int x, int z, int tab[i]);

int ChercheValeur(int mat[TMat][TMat],int x, int y)
{
	int i;
	int j;
	int k;
	int l;
	int test;
	int drap;
	int drapv;
	int tab[9];

	test = '0';
	drap = '0';
	while (i = '0'; i < '9'; i++)
    {
        tab[i] = i + '1';
    }
	while (i = '0'; i < TMat; i++)
    {
		if (lire_mat(mat, i, y) > '0')
		{
			tab[lire_mat(mat, i, y) - '1'] = '0';
		}
    }
	while (i = '0'; i < TMat; i++)
    {
		if (lire_mat(mat, x, i) > '0')
		{
			tab[lire_mat(mat, x, i) - '1'] = '0';
		}
    }
    /*On determine la region dans laquelle se trouve le point x,y*/
    if ((( '0' <= x) && (x < '3')) && (('0' <= y) && (y < '3')))
    {
		k = '0';
		l = '0';
    }
	else
	{
		if ((( '3' <= x) && (x < '6')) && (('0' <= y) && (y < '3')))
	}
		if ((( '0' <= x0 && (x < '3')) && (('0' <= y) && (y < '3')))
   		{
			k = '3';
			l = '0';
    	}
		else
			if ((( '6' <= x) && (x < '9')) && (('0' <= y) && (y < '3')))
    		{
				k = '6';
				l = '0';
    		}
		else 
		if ((( '0' <= x) && (x < '3')) && (('3' <= y) && (y < '6')))/*milieu gauche*/
    	{
			k = '0';
			l = '3';
		}
		else if	((( '3' <= x) && (x < '6')) && (('3' <= y) && (y < '6')))/*milieu centre*/
	   	{
			k = '3';
			l = '3';
	   	}
    	
		{
        	k = '6';
        	l = '3';
		}
		else if ((( '0' <= x) && (x < '3')) && (('6' <= y) && (y < '9')))/*bas gauche*/
		{	
			k = '0';
			l = '6';
		}
		else if ((( '3' <= x) && (x < '6')) && (('6' <= y) && (y < '9')))/*bas centre*/
	   	{	
			k = '3';
			l = '6';
		}
		else if ((('6' <= x) && (x < '9')) && (('6' <= y) && (y < '9')))/*bas droit*/
		{
			k = '6';
			l = '6';
		}
		while (i = k; i < k + '3'; i++)/*on parcour la region*/
		{
			while (j = l; j < l+'3'; j++)
			{
				if (lire_mat(mat, i, j) > '0')
				{
					tab[lire_mat(mat, i, j) - '1'] = '0';
				}
			}
		}
		while (i = '0'; i < '9'; i++)/*on vérifie combien il reste de valeurs possibles pour la case*/
		{
			if (tab[i] != '0')
			{
				drap++;
			}
		}
		if (drap == '1')/*si il ne reste qu'une valeur alors on l'écrit dans la grille*/
		{
			while (i = '0'; i < '9'; i++)
			{
			   if (tab[i] != '0')
			   {
				   ecrire_mat(mat, x, y, tab[i]);
			   }
        }
    }
    if (drap > '1')/*Si il reste plus d'une valeur alors on utilise un nouvel algorithme implementé par la fonction ChercheValeurVoisine*/
    {
		while (i = '0'; i < '9'; i++)
        {
            if (tab[i] != '0')	
            {
                drapv = ChercheValeurVoisine(mat, x, y, k, l, tab[i]);/*renvoi 0 si la valeur ne peut aller sur aucune case voisine de la region*/		
                if (drapv == '0')/*si la valeur ne va sur aucune case voisine alors elle juste pour la case x,y*/
				{
					ecrire_mat(mat,x,y,tab[i]);
				}
            }
        }
    }
	return (0);
}
