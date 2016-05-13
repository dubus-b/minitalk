/*
** main2.c for norme in /home/dubus_b/rendu/Unix/PSU_2015_minitalk/client/source
** 
** Made by Benjamin Dubus
** Login   <dubus_b@epitech.net>
** 
** Started on  Sun Feb 21 23:19:05 2016 Benjamin Dubus
** Last update Sun Feb 21 23:38:37 2016 Benjamin Dubus
*/

#include "myfx.h"

char		translate_to_ascii(char *str)
{
  int		idx;
  char		lettre;

  idx = 0;
  lettre = 0;
  while (idx <= 7)
    {
      lettre = lettre << 1;
      if (str[idx] == 1)
        lettre++;
      idx++;
    }
  return (lettre);
}

void		translate_pid(t_number *nbr)
{
  nbr->pid_client = nbr->pid_client << 1;
  if (nbr->tmp_sig == SIGUSR2)
    nbr->pid_client++;
}

void		print_letter(t_number *nbr, char *current_char)
{
  char		letter;

  if ((letter = translate_to_ascii(current_char)) == 4)
    nbr->finish = 1;
  else
    my_putchar(letter);
  nbr->idx_str = 0;
}

