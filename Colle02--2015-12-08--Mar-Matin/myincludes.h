/****************************************************************************/
/*                                                                          */
/*                                                       :::      ::::::::  */
/*  myincludes.h                                       :+:      :+:    :+:  */
/*                                                   +:+ +:+         +:+    */
/*  By: malamzad <marvin@42.fr>                    +#+  +:+       +#+       */
/*                                               +#+#+#+#+#+   +#+          */
/*  Created: 2015/12/06 11:14:17 by malamzad          #+#    #+#            */
/*  Updated: 2015/12/06 11:14:17 by malamzad         ###   ########.fr      */
/*                                                                          */
/****************************************************************************/
#define TRUE	1
#define FALSE	0
#define QUATRE_K 4196
#define ALWAYS TRUE
#define NORMAL_END 0
#define ABNORMAL_END - 1

int	find_left_col(char **, int);
int	find_right_col(char **, int);
int	find_top_row(char **, int);
int	find_bottom_row(char **, int);
void dump_tab_char(char **, int, char *);
void dump_tab_int(int *, int, char *);
int	ft_strlen(char *);
void delete_cr(char *);
char *ft_copystr(char *);
void move_to_top_left(char **, int *, int *);
void move_bottom_to_top(char ** tab, int *nrl);
void move_right_to_left(char **tab, int, int *);
char ** text_file_to_str_tab(char *, int *);
void recognize(char **, int, int);
int is_form_of_colle(char **, int, int);
void set_tab(int *, int, int);
int * stat_lines(char **, int);
int * stat_cols(char **, int, int);
char * which_colle(char **, int, int);
char * identify_colle(char *);
int ft_strcmp(char *,char *);
int elem_in_tab(char **, int, char *);
int verify_colle_tab(int *, int, int);
