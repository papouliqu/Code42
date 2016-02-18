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

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "myincludes.h"

int		nr_of_lines(char *fn)
{
	int nrL;
	char *buff;
	
	FILE *f;
	nrL = 0;
	f=fopen(fn, "r");
	buff = (char *) malloc(quatre_k * sizeof(char));
	if(f == NULL)
		return(0);
	while(always)
	{
		if(fgets(buff, quatre_k, f) == NULL) break;
		++nrL;
	}
	fclose(f);
	free(buff);
	return (nrL);
}

char	**text_file_to_str_tab(char *fn, int *nrl)
{
	int ctrL;
	char **ptrLines;
	char *buff;
	char *line;
	FILE *f;
	
	*nrl = nr_of_lines(fn);
	buff = (char *) malloc(quatre_k*sizeof(char));
	ptrLines = (char **) malloc(*nrl * sizeof(char *));
	f = fopen(fn, "r");
	ctrL = 0;
	if (f == NULL) return (NULL);
	while (always)
	{
		if(fgets(buff, quatre_k, f) == NULL)
			break;
		line = ft_copystr(buff);
		delete_cr(line);
		ptrLines[ctrL++] = line;
	}
	fclose(f);
	free(buff);
	return (ptrLines);
}

int nr_lines(char *mem, int size)
{
	int nl;
	int k;
	char *p;

	p = mem;
	k = -1;	
	nl = 0;
	while (++k < size)
	{
		if (*(p++) == 0x0A)
			++nl;
	}
	return(nl);
}

char	**stream_to_str_tab(char *buff, int *nrl)
{
	char **ptr_lines;
	char *p;
	int bytes_read;
	int k;
	int ctrl;

	bytes_read =read(0, buff, seize_k);
	k = -1;
	p = buff;
	*nrl = nr_lines(buff, bytes_read);
	if(*nrl <= 0)
		*nrl = 1;
	ptr_lines = (char **) malloc(*nrl * sizeof(char *));
	k = -1;
	while(++k < *nrl)
		ptr_lines[k] = NULL;
	ctrl = 0;
	k = -1;
	p = buff;
	while (++k < bytes_read)
	{
		if (*(p++) != 0x0A)
			continue;
		buff[k] = 0x00;
		ptr_lines[ctrl++] = p;
		p = buff + k + 1;
	}
	return (ptr_lines);
}

