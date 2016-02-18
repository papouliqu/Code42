//
//  FT_main.c
//  
//
//  Created by Patricia POULIQUEN on 28/11/15.
//
//

#include <stdio.h>


int main(int argc, char *argv[])
{
    int x,y;
    int i,j;
    char buf[2];
    int n;
    int mat [TMat][TMat];  /*Doit etre initialiser avec TailleMat*/
    FILE * e;
    
    
    for(i=0;i<argc;i++)//argc a la valeur du nombre d'arguments saisi en parametre par l'utilisateur+1
    {
        if(strcmp(argv[i],"?")==0)//si l'utilisateur a saisi comme argument ? alors il accede a une explication sur l'utilisation du programme puis on termine par exit(0)
        {
            printf("\n");
            printf("Ce programme resoud des sudokus de niveau facile, le 1er parametre du programme est le nom de fichier contenant la grille a resoudre\nle 2em parametre est le nom de fichier qui contiendra la grille resolue.\nExemple d'utilisation: ./sudoku sudoku.txt solution.txt\nChaque case vide de la grille aura pour valeur 0");
            printf("\n");
            printf("Exemple de grille a taper dans un fichier texte:\n");
            printf("906080000\n000090764\n073000000\n204100095\n350060047\n160004803\n000000910\n695010000\n000020506\n");
            exit(0);
        }
    }
    
    
    if(argc!=3)/*si le nombre d'argument est different de 2 alors on averti l'utilisateur et on termine le programme par exit(0)*/
    {
        //printf("argc =%d",argc);
        printf("\n");
        printf("nombre d'arguments insuffisant tapez ./sudoku ? pour plus d'informations\n");
        printf("\n");
        exit(0);
    }
    
    e=fopen(argv[2],"w");/*on ouvre le fichier saisi par l'utilisateur en ecriture*/
    if(e==NULL)
    {
        printf("erreur d'ouverture du fichier %s\n",argv[2]);
        exit(0);
    }
    
    
    init_mat(mat,argv[1]);//on initialise la grille avec le fichier passé en argument
    
    for(i=0;i<nb_execution_algorithme;i++)/*on applique l'algorithme pour chaque case de la grille qui est differente de 0 jusqu'a ce que le compteur de boucle soit égal à nb_execution_algorithme */
    {
        for(x=0;x<TMat;x++)
        {
            for(y=0;y<TMat;y++)
            {
                if(lire_mat(mat,x,y)==0)
                    ChercheValeur(mat,x,y);
            }
            y=0;
        }
        
    }
    /*on ecrit la grille dans le fichier passé en parametre par l'utilisateur*/
    for(y=0;y<TMat;y++)
    {
        for(x=0;x<TMat;x++)
        {
            n=lire_mat(mat,x,y);
            sprintf(buf,"%d",n);
            fwrite(buf,sizeof(char),1,e);
        }
        fwrite("\n",sizeof(char),1,e);
    }
    fclose(e);
    return 0;
}
