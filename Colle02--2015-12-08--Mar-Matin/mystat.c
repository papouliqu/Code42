int * stat_lines(char **tab, int nrligs)
{
	int *stat_l;
	int col;
	int lig;
	char *p;
	
	stat_l = (int *) malloc(nrligs * sizeof(int));
	set_tab(stat_l, nrligs, 0);
	lig = -1;
	while (++lig < nrligs)
	{
		p = tab[lig];
		while(*p)
		{
			if(*p != ' ') ++stat_l[lig];
			++p;
		}
	}
	return(stat_l);
}

int * stat_cols(char **tab, int nrligs, int nrcols)
{
	int *stat_c;
	int lig;
	int col;
	char *p;
	
	stat_c = (int *) malloc(nrcols * sizeof(int));
	set_tab(stat_c, nrcols, 0);
	lig = -1;
	while (++lig < nrligs)
	{
		p = tab[lig];
		col = -1;
		while(*p)
		{
			++col;
			if(*p != ' ') ++stat_c[col];
			++p;
		}
	}
	return(stat_c);
}

