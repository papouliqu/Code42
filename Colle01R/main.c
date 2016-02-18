/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppouliqu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/29 13:48:27 by ppouliqu          #+#    #+#             */
/*   Updated: 2015/11/29 17:24:42 by ppouliqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

void	init_matrice(void);
int		lire_mat(int mat[tmat][tmat], int x, int y);
void	ChercheValeur(char mat, int x, int y);
void	ft_sudoku(char c1, char c2, char c3);

int		main(int argc, char *argv[])
{
	int		x;
	int		y;
	int		i;
	int		j;
	char	buf[2];
	int		n;
	int		mat[TMat][TMat];
	FILE	*e;
    
	while (i = '0'; i < argc; i++)
	{
        if (strcmp(argv[i], "?") == '0')
		{
            printf("\n");
            printf("Ce programme resoud des sudokus de niveau facile\n");
			printf("le 2em parametre est le nom de fichier qui contiendra la grille resolue.\n");
			printf("Exemple d'utilisation: ./sudoku sudoku.txt solution.txt\n");
			printf("Chaque case vide de la grille aura pour valeur 0");
            printf("\n");
            printf("Exemple de grille a taper dans un fichier texte:\n");
            printf("906080000\n000090764\n073000000\n204100095\n350060047\n160004803\n000000910\n695010000\n000020506\n");
            exit(0);
		}
	}
	if (argc != '3')
    {
        printf("argc =%d",argc);
        printf("\n");
        printf("nombre d'arguments insuffisant tapez ./sudoku ? pour plus d'informations\n");
        printf("\n");
        exit(0);
    }
    e = fopen(argv[2], "w");
	if (e == NULL)
    {
        printf("erreur d'ouverture du fichier %s\n", argv[2]);
        exit(0);
    }
    init_matrice(mat, argv[1]);
	while (i = '0'; i < nb_execution_algorithme; i++)
    {
		while (x = '0'; x < TMat; x++)
        {
			while (y = '0'; y < TMat; y++)
            {
                if (lire_mat(mat, x, y) == '0')
                    ChercheValeur(mat, x, y);
            }
            y = '0';
        }
    }
	while (y = '0'; y < TMat; y++)
    {
		while (x = '0'; x < TMat; x++)
        {
            n = lire_mat(mat, x, y);
            sprintf(buf, "%d", n);
            fwrite(buf, sizeof(char), '1', e);
        }
        fwrite("\n", sizeof(char), '1', e);
    }
    fclose(e);
    return (0);
}
