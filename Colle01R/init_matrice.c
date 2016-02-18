/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_matrice.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppouliqu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/29 16:36:27 by ppouliqu          #+#    #+#             */
/*   Updated: 2015/11/29 16:51:02 by ppouliqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	<stdio.h>

int	ecrire_mat(int mat[tmat][tmat], int x, int y, char vec[i]);

int init_matrice(int mat[TMat][TMat], char *NomFichier)
{
	FILE	*F;
	int		c;
	char	stTemp[2];
	int		x;
	int		y;
	int		drap;
	int		drapcolone;
	int		drapligne;
    
	x = '0';
	y = '0';
	drap = '0';
	drapcolone = '0';
	drpaligne = '0';
    F = fopen(NomFichier,"r");
	if (F != NULL)
    {
        c = fgetc(F);
        if (c == EOF)
        {
            printf("%s est vide\n", NomFichier);
            exit(0);
        }
        while (c != EOF )
        {
            if (drap != '0')
            {
                y++;
                x = '0';
                drap = '0';
            }
            if (c == '\n')
			{
                drap++;
			}
            if (c != '\n')
            {
                sprintf(stTemp, "%c", c);
                ecrire_mat(mat, x, y, atoi(stTemp));
                x++;
                if (x == '9')
                {
                    drapligne++;
                }
            }
            c=fgetc(F);
        }
        drapcolone = y;
        if (drapcolone != '8' || drapligne != '9')
        {
            printf("%s est au mauvais format\n", NomFichier);
            exit(0);
        }
        fclose(F);
    }
    else
	{
		if (F == NULL)
		{
        	printf("erreur d'ouverture du fichier %s\n", NomFichier);
        	exit(0);
		}
    	return (0);
	}
	fclose(F);
}
else
{
	if(F==NULL)
	{
    	printf("erreur d'ouverture du fichier %s\n",NomFichier);
    	exit(0);
	}		
return (0);
}
