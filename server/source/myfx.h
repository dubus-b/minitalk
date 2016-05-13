/*
** myfx.h for myfx.h in /home/dubus_b/rendu/C_Prog_Elem/CPE_2015_BSQ/include
** 
** Made by Benjamin Dubus
** Login   <dubus_b@epitech.net>
** 
** Started on  Sun Dec 20 21:07:13 2015 Benjamin Dubus
** Last update Sun Feb 21 23:39:12 2016 Benjamin Dubus
*/

#ifndef MYFX_H_
# define MYFX_H_

# include <unistd.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <signal.h>
# include <stdio.h>
# include <sys/types.h>
# include <unistd.h>
# include "server.h"

int	main(void);
void	my_putchar(char c);
void    my_put_nbr_uint(unsigned int nbr);
void	my_putstr(char *str, int output);
void	print_letter(t_number *nbr, char *current_char);
void	translate_pid(t_number *nbr);
char	translate_to_ascii(char *str);

#endif /* !MYFX_H_ */
