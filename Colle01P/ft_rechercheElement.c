//
//  ft_rechercheElement.c
//  
//
//  Created by Patricia POULIQUEN on 28/11/15.
//
//

#include "ft_rechercheElement.h"

int ChercheValeurVoisine(int mat[TMat][TMat], int x, int y, int k, int l, int val)/*Cherche la valeur des cases voisines de x,y.renvoi 0 si les cases voisines sont bloques par val(6em param) 1 sinon*/
{
    int h,i,j;
    int d;
    int nbcasevide=0;
    int drap=0;
    int drapc,drapl;
    for(i=k;i<k+3;i++)
    {
        for(j=l;j<l+3;j++)
        {
            if(lire_mat(mat,i,j)==0)/*on applique l'algorithme uniquement sur les cases voisines vides*/
            {
                
                d=0;
                if(i==x)
                {
                    if(j==y)
                        d=1;
                }
                if(d==0)/*test pour eviter de parcourir ligne et colone correspondant à x,y*/
                {
                    nbcasevide++;
                    drapc=0;
                    drapl=0;
                    for(h=0;h<9;h++)
                    {
                        if(lire_mat(mat,h,j)!=val)//on parcour la ligne de la case voisine
                            drapl++;	//si la ligne de la case voisine ne contient pas val alors on incremente drapl++
                    }
                    for(h=0;h<9;h++)
                    {
                        if(lire_mat(mat,i,h)!=val)//on parcour la colone de la case voisine
                            drapc++;//si la colone de la case voisine ne contient pas val alors on incremente drapc++
                    }
                    if(drapc<9)//drapc ou drapl<9 implique que la ligne ou la colone est bloquée par val
                        drap++;
                    
                    else if (drapl<9)
                        drap++;			
                }
            }
        }
    }
    if(nbcasevide!=drap)/*le nombre de cases non bloquees par val doit etre identique au nombre de cases vide de la region si il est different on retourne 1*/
        return 1;
    else return 0;
    
}

