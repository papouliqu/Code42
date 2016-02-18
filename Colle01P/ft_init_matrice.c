//
//  ft_init_matrice.c
//  
//
//  Created by Patricia POULIQUEN on 28/11/15.
//
//

#include "ft_init_matrice.h"

int init_mat(int mat[TMat][TMat],char *NomFichier)/*initialise la grille a partir du fichier NomFichier*/
{
    
    FILE *F;
    int c;
    char stTemp[2];
    int x=0;
    int y=0;
    int drap=0;
    int drapcolone=0;
    int drapligne=0;
    
    F=fopen(NomFichier,"r");//on ouvre le fichier en lecture
    if(F!=NULL)
    {
        c=fgetc(F);
        if(c==EOF)
        {
            printf("%s est vide\n",NomFichier);
            exit(0);
        }
        
        while (c!=EOF )//on parcourt le fichier
        {
            if(drap!=0)
            {
                y++;
                x=0;
                drap=0;
            }
            if(c=='\n')
                drap++;
            if(c!='\n')
            {
                sprintf(stTemp,"%c",c);
                ecrire_mat(mat, x, y, atoi(stTemp));// on converti la valeur lue en int et on l'ecrit dans la grille aux coordonnes x,y
                x++;
                if(x==9)
                {
                    drapligne++;
                }
            }
            c=fgetc(F);
            
        }
        
        drapcolone=y;
        if(drapcolone!=8||drapligne!=9)//Si le fichier ne contient pas le bon nombre de lignes ou de colones alors on quitte
        {
            printf("%s est au mauvais format\n",NomFichier);
            exit(0);
        }
        
        
        fclose(F);//on ferme le fichier
    }
    else if(F==NULL)
    {
        printf("erreur d'ouverture du fichier %s\n",NomFichier);
        exit(0);
    }
    
    return 0;
}


fclose(F);//on ferme le fichier
}
else if(F==NULL)
{
    printf("erreur d'ouverture du fichier %s\n",NomFichier);
    exit(0);
}
return 0;
}