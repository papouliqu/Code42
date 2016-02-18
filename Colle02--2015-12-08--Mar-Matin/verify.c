/****************************************************************************/
/*                                                                          */
/*                                                       :::      ::::::::  */
/*  verify.c                                           :+:      :+:    :+:  */
/*                                                   +:+ +:+         +:+    */
/*  By: malamzad <marvin@42.fr>                    +#+  +:+       +#+       */
/*                                               +#+#+#+#+#+   +#+          */
/*  Created: 2015/12/06 11:14:17 by malamzad          #+#    #+#            */
/*  Updated: 2015/12/06 11:14:17 by malamzad         ###   ########.fr      */
/*                                                                          */
/****************************************************************************/

int verify_colle_tab(int *stat, int dim1, int dim2)
{
	int mid_val;
	int k;
	int res;

	if (dim1 == 1)
		if (stat[0] == dim2)
			return (TRUE);
		else
			return (FALSE);
	mid_val = (dim2 > 1 ? 2 : 1);
	k = 0;
	res = TRUE;
	while(++k < dim1 - 1)
	{
		if (stat[k] != mid_val)
		{
			res = FALSE;
			break;
		}
	}
	return(res);
}


