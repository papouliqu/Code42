/****************************************************************************/
/*                                                                          */
/*                                                       :::      ::::::::  */
/*  myfiles.c                                          :+:      :+:    :+:  */
/*                                                   +:+ +:+         +:+    */
/*  By: malamzad <marvin@42.fr>                    +#+  +:+       +#+       */
/*                                               +#+#+#+#+#+   +#+          */
/*  Created: 2015/12/06 11:03:51 by malamzad          #+#    #+#            */
/*  Updated: 2015/12/06 11:03:51 by malamzad         ###   ########.fr      */
/*                                                                          */
/****************************************************************************/

/*
#include <stdlib.h>
#include <stdio.h>
#include "myincludes.h"
*/

int		nrOfLines(char *fn)
{
	int nrL;
	char *buff;
	
	FILE *f;
	nrL = 0;
	f=fopen(fn, "r");
	buff = (char *) malloc(QUATRE_K*sizeof(char));
	if(f == NULL)
		return(0);
	while(ALWAYS)
	{
		if(fgets(buff, QUATRE_K, f) == NULL) break;
		++nrL;
	}
	fclose(f);
	free(buff);
	return (nrL);
}

char	**text_file_to_str_tab(char *fn, int *nrL)
{
	int ctrL;
	char **ptrLines;
	char *buff;
	char *line;
	FILE *f;
	
	*nrL = nrOfLines(fn);
	buff = (char *) malloc(QUATRE_K*sizeof(char));
	ptrLines = (char **) malloc(*nrL * sizeof(char *));
	f = fopen(fn, "r");
	ctrL = 0;
	if (f == NULL) return (NULL);
	while (ALWAYS)
	{
		if(fgets(buff, QUATRE_K, f) == NULL)
			break;
		line = ft_copystr(buff);
		delete_cr(line);
		ptrLines[ctrL++] = line;
	}
	fclose(f);
	free(buff);
	return (ptrLines);
}
