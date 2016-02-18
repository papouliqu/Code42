/****************************************************************************/
/*                                                                          */
/*                                                       :::      ::::::::  */
/*  recognition                                        :+:      :+:    :+:  */
/*                                                   +:+ +:+         +:+    */
/*  By: malamzad <marvin@42.fr>                    +#+  +:+       +#+       */
/*                                               +#+#+#+#+#+   +#+          */
/*  Created: 2015/12/06 11:14:17 by malamzad          #+#    #+#            */
/*  Updated: 2015/12/06 11:14:17 by malamzad         ###   ########.fr      */
/*                                                                          */
/****************************************************************************/
#define NR_COLLES	20
const char * colle_codes[NR_COLLES]={
    "o-o| |o-o",
	"oXoXXXoXo",
	"oXo|X|oXo",
	"o-oXXXo-o",
    "/*\\* *\\*/",
	"/X/XXX/X/",
	"/X/*X*\\X\\",
	"/*\\XXX/*\\",
    "ABAB BCBC",
	"AXAXXXAXA",
	"AXABXBCXC",
	"ABAXXXABA",
	"AXABXBAXA",
	"ABCB BABC",
	"ABCXXXABC",
	"o-oXXXo-o",
	"AXAXXXAXA",
	"AXABXBCXC",
	"---------",
	"---------"
};
const char * colle_names[NR_COLLES]={
    "colle 00",
	"colle 00",
	"colle 00",
	"colle 00",
    "colle 01",
	"colle 01",
	"colle 01",
	"colle 01",
    "colle 02",
	"colle 02",
	"colle 02",
	"colle 02",
    "colle 03",
	"colle 03",
	"colle 03",
	"colle 03",
    "colle 04",
	"colle 04",
	"colle 04",
	"colle 04"
};

void recognize(char **tab, int nrligs, int nrcols)
{
	int iscolle;
	char * which;
					dump_tab_char(tab, nrligs,"** recognize");
	iscolle = is_form_of_colle(tab, nrligs, nrcols);
	if(! iscolle)
	{
		printf("\naucune");
		return;
	}
	which = which_colle(tab, nrligs, nrcols);
			        printf("\n** colle : %s [%d , %d]",which, nrcols, nrligs);
}

int is_form_of_colle(char **tab, int nrligs, int nrcols)
{
	int *stat_l;
	int *stat_c;
	int res;
	
	res = TRUE;
	stat_l = stat_lines(tab, nrligs);
	stat_c = stat_cols(tab, nrligs, nrcols);
	                    dump_tab_int(stat_l, nrligs, "Stat_lines");
	                    dump_tab_int(stat_c, nrcols, "Stat_cols");
						printf("\nnrcols, nrligs %d x %d",nrcols, nrligs);
	if(stat_l[0] != nrcols || stat_l[nrligs - 1] != nrcols)
		res = FALSE;
						printf("\n1 -- res : %d",res);
	if(stat_c[0] != nrligs || stat_c[nrcols - 1] != nrligs)
		res = FALSE;
						printf("\n2 -- res : %d",res);
	if (res)
		res = verify_colle_tab(stat_l, nrligs, nrcols);
						printf("\n3 -- res : %d",res);
	if (res)
		res = verify_colle_tab(stat_c, nrcols, nrligs);
						printf("\n4 -- res : %d",res);
	free(stat_l);
	free(stat_c);
	return (res);
}

char * which_colle(char **tab, int nrligs, int nrcols)
{
	char * res;
	char * colle_set = ft_copystr("XXXXXXXXX");

	colle_set[0] = * (tab[0] + 0);
	colle_set[2] = * (tab[0] + nrcols - 1);
	colle_set[6] = * (tab[nrligs - 1] + 0);
	colle_set[8] = * (tab[nrligs - 1] + nrcols - 1);
	if(nrligs > 2)
	{
		colle_set[3] = * (tab[1] + 0);
		colle_set[5] = * (tab[1] + nrcols - 1);
	}
	if(nrcols > 2)
	{
		colle_set[1] = * (tab[0] + 1);
		colle_set[7] = * (tab[nrligs - 1] + 1);
		if(nrligs > 2)
			colle_set[4] = * (tab[1] + 1);
	}
	res = identify_colle(colle_set);
	free(colle_set);
	return(res);
}

char * identify_colle(char * colle_set)
{
	char * res;
	int found;
	int k;
	
	res = "Unknown";
							printf("\n*** identify_colle(%s)",colle_set);
	found = elem_in_tab((char **) colle_codes, NR_COLLES, colle_set);
							printf("\nfound %d",found);
	if(found >= 0)
		res = (char *) colle_names[found];
		
	
	
	return (res);
}
