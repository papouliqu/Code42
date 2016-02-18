/****************************************************************************/
/*                                                                          */
/*                                                       :::      ::::::::  */
/*  str.c                                              :+:      :+:    :+:  */
/*                                                   +:+ +:+         +:+    */
/*  By: malamzad <marvin@42.fr>                    +#+  +:+       +#+       */
/*                                               +#+#+#+#+#+   +#+          */
/*  Created: 2015/12/06 10:46:21 by malamzad          #+#    #+#            */
/*  Updated: 2015/12/06 14:15:39 by malamzad         ###   ########.fr      */
/*                                                                          */
/****************************************************************************/

// #include <stdlib.h>

int		ft_strlen(char *str)
{
	char	*p;
	int		ln;

	p = str;
	ln = 0;
	while (*(p++))
		++ln;
	return (ln);
}

char		*ft_copystr(char *s)
{
	int		ln;
	char	*retval;
	char	*p1;
	char	*p2;
	
	ln = ft_strlen(s);
	retval = (char *)malloc((ln + 1) * sizeof(char));
	p1 = s;
	p2 = retval;
	while (*p1)
	{
		*p2 = *p1;
		++p1;
		++p2;
	}
	*p2 = 0x00;
	return (retval);
}

void		delete_cr(char *str)
{
	int		ln;
	int		k;
	
	ln = ft_strlen(str);
	                 // printf("\nln : %d",ln);
	k=-1;
	while (++k < 2 && ln > 0)
	{
		if (str[ln - 1] == 0x0A || str[ln - 1] == 0x0D)
		{
			str[ln - 1] = 0x00;
			--ln;
		}
	}
}

int ft_strcmp(char *s1,char *s2) {
   char *p1,*p2,Res;
   p1=s1;
   p2=s2;
   Res=0;
   if(s1==NULL || s2==NULL)
   {
      return(0);
   }
   while(1)
   {
      if(*p1<*p2)
	  {
         Res=-1;
	     break;
	  }
      if(*p1>*p2)
	  {
         Res=+1;
	     break;
	  }
	  if(! *p1 && ! *p2)
	  {
	     break;
	  }
	  ++p1;
	  ++p2;
   }
   return(Res);
}

int elem_in_tab(char **tab, int nrelems, char * elem)
{
	int k;
	int found;
	
	k = -1;
	found = -1;
	while(++k < nrelems)
	{
	                   //printf("\n**COMP %d <%s>/<%s> : %d",k,tab[k],elem,ft_strcmp(tab[k], elem));
		if(ft_strcmp(tab[k], elem)==0)
		{
			found=k;
			break;
		}
	}
	return (found);
}
