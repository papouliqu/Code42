//
//  ft_init_matrice.h
//  
//
//  Created by Patricia POULIQUEN on 28/11/15.
//
//

#ifndef ft_init_matrice_h
#define ft_init_matrice_h

#include <stdio.h>

#endif /* ft_init_matrice_h */


int ChercheValeur(int mat[TMat][TMat],int x, int y)/*cherche la valeur possible de la case de coordonnes x,y*/
{
    int i;
    int j;
    int k;
    int l;
    int test=0;
    int drap=0;
    int drapv;
    int tab[9];
    for(i=0;i<9;i++)
    {
        tab[i]=i+1;//on initialise le tableau avec toute les valeurs possibles pour la case x,y (1 à 9) et tab[0]=1,tab[1]=2...tab[8]=9
    }
    
    
    for(i=0;i<TMat;i++)
    {
        
        
        if(lire_mat(mat,i,y)>0)
            tab[lire_mat(mat,i,y)-1]=0;// on parcour la ligne sur laquelle est le point x,y, on elimine les valeurs possibles en mettant la valeur correspondante de tab à 0
        
        
    }
    for(i=0;i<TMat;i++)
    {
        
        
        if(lire_mat(mat,x,i)>0)// on parcour la colone sur laquelle est le point x,y, on elimine les valeurs possibles dans tab comme pour le parcour de la ligne
            tab[lire_mat(mat,x,i)-1]=0;
        
    }
    /*On determine la region dans laquelle se trouve le point x,y*/
    
    
    if(((0<=x)&&(x<3))&&((0<=y)&&(y<3)))/*haut gauche*/
    {
        k=0;
        l=0;
        
    }
    
    else if(((3<=x)&&(x<6))&&((0<=y)&&(y<3)))/*haut centre*/
    {
        k=3;
        l=0;
    }
    
    else if(((6<=x)&&(x<9))&&((0<=y)&&(y<3)))/*haut droit*/
    {
        k=6;
        l=0;
        
    }
    
    else if(((0<=x)&&(x<3))&&((3<=y)&&(y<6)))/*milieu gauche*/
    {
        k=0;
        l=3;
    }
    
    else if(((3<=x)&&(x<6))&&((3<=y)&&(y<6)))/*milieu centre*/
    {
        k=3;
        l=3;
    }
    
    else if(((6<=x)&&(x<9))&&((3<=y)&&(y<6)))/*milieu droit*/
    {
        k=6;
        l=3;
    }
    
    else if(((0<=x)&&(x<3))&&((6<=y)&&(y<9)))/*bas gauche*/
    {
        k=0;
        l=6;
    }
    
    else if(((3<=x)&&(x<6))&&((6<=y)&&(y<9)))/*bas centre*/
    {
        k=3;
        l=6;
    }
    
    else if(((6<=x)&&(x<9))&&((6<=y)&&(y<9)))/*bas droit*/
    {
        k=6;
        l=6;
    }
    
    for(i=k;i<k+3;i++)/*on parcour la region*/
    {
        for(j=l;j<l+3;j++)
        {
            if(lire_mat(mat,i,j)>0)
            {
                tab[lire_mat(mat,i,j)-1]=0;
            }
        }
  
    }
    
    for(i=0;i<9;i++)/*on vérifie combien il reste de valeurs possibles pour la case*/
    {
        if(tab[i]!=0)
            drap++;
    }
    
    if(drap==1)/*si il ne reste qu'une valeur alors on l'écrit dans la grille*/
    {
        for(i=0;i<9;i++)
        {
            
            if(tab[i]!=0)
                ecrire_mat(mat,x,y,tab[i]);
        }
    }
    
    if(drap>1)/*Si il reste plus d'une valeur alors on utilise un nouvel algorithme implementé par la fonction ChercheValeurVoisine*/
    {
        for(i=0;i<9;i++)
        {
            if(tab[i]!=0)	
            {
                drapv=ChercheValeurVoisine(mat,x,y,k,l,tab[i]);/*renvoi 0 si la valeur ne peut aller sur aucune case voisine de la region*/		
                if(drapv==0)/*si la valeur ne vas sur aucune case voisine alors elle juste pour la case x,y*/			
                    ecrire_mat(mat,x,y,tab[i]);
            }
        }
    }
    
    return 0;
}

