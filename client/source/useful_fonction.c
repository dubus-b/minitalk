/*
** my_putstr.c for putstr in /home/dubus_b/rendu/Unix/PSU_2015_minitalk/client/source
** 
** Made by Benjamin Dubus
** Login   <dubus_b@epitech.net>
** 
** Started on  Mon Feb  8 18:12:19 2016 Benjamin Dubus
** Last update Sun Feb 21 20:06:08 2016 Benjamin Dubus
*/

#include <unistd.h>
#include "myfx.h"

void	my_putchar(char c)
{
  write(1, &c, 1);
}

int	my_strlen(char *str)
{
  int	index;

  index = 0;
  while (str[index] != '\0')
    index = index + 1;
  return (index);
}

void	my_putstr(char *str, int output)
{
  write(output, str, my_strlen(str));
}

void	my_put_nbr(int nbr)
{
  if (nbr == -2147483648)
    {
      my_putstr("-2147483648", 1);
      return ;
    }
  if (nbr < 0)
    {
      my_putchar('-');
      nbr = nbr * -1;
    }
  if (nbr >= 10)
    {
      my_put_nbr(nbr / 10);
      my_putchar(nbr % 10 + '0');
    }
  else
    my_putchar(nbr + '0');
}

int	my_getnbr(char *str)
{
  int	var;
  int	inv;
  int	i;

  inv = 1;
  var = 0;
  i = 0;
  if (str == NULL)
    return (0);
  while ((*str < 47 || *str > 58) && *str != 0)
    {
      str = str + 1;
      i = i + 1;
    }
  if (i > 0 && *(str - 1) == 45)
    inv = -1;
  while (*str != 0 && *str >= '0' && *str <= '9')
    {
      var = var * 10;
      var = var + *str - 48;
      str = str + 1;
    }
  var = var * inv;
  return (var);
}
