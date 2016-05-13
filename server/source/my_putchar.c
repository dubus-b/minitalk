/*
** my_putchar.c for putchar in /home/dubus_b/rendu/Unix/PSU_2015_my_printf/src
** 
** Made by Benjamin Dubus
** Login   <dubus_b@epitech.net>
** 
** Started on  Mon Nov 16 17:12:29 2015 Benjamin Dubus
** Last update Sun Feb 21 14:57:45 2016 Benjamin Dubus
*/
#include "myfx.h"

void	my_putchar(char letter)
{
  write(1, &letter, 1);
}

void	my_putchar_error(char letter)
{
  write(2, &letter, 1);
}

void	my_putstr(char *str, int output)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    {
      if (output == 1)
	my_putchar(str[i]);
      else
	my_putchar_error(str[i]);
      i++;
    }
}
