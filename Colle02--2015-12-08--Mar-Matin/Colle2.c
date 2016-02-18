/****************************************************************************/
/*                                                                          */
/*                                                       :::      ::::::::  */
/*  colle2.c                                           :+:      :+:    :+:  */
/*                                                   +:+ +:+         +:+    */
/*  By: malamzad <marvin@42.fr>                    +#+  +:+       +#+       */
/*                                               +#+#+#+#+#+   +#+          */
/*  Created: 2015/12/06 11:14:17 by malamzad          #+#    #+#            */
/*  Updated: 2015/12/06 11:14:17 by malamzad         ###   ########.fr      */
/*                                                                          */
/****************************************************************************/
#include <stdio.h>
#include <stdlib.h>

#include "myincludes.h"
#include "mystr.c"
#include "myfiles.c"
#include "dumperr.c"
#include "myfind.c"
#include "mymove.c"
#include "mymem.c"
#include "recognition.c"
#include "mystat.c"
#include "verify.c"


void test_read()
{
	

}
int	main(int argc, char *argv[])
{
	int nrligs;
	int nrcols;
	char **image_in_mem;

	test_read();
	
	
	
	if (argc < 2)
		return (ABNORMAL_END);
	image_in_mem = text_file_to_str_tab(argv[1], &nrligs);
	if (image_in_mem == NULL)
	return (ABNORMAL_END);
	move_to_top_left(image_in_mem, &nrligs, &nrcols);
	             printf("\n %d x %d",nrligs, nrcols);
	recognize(image_in_mem, nrligs, nrcols);
	free_tab_mem(image_in_mem, nrligs);
	return (NORMAL_END);
}
