/*
** main.c for serveur in /home/dubus_b/rendu/Unix/PSU_2015_minitalk/serveur
** 
** Made by Benjamin Dubus
** Login   <dubus_b@epitech.net>
** 
** Started on  Fri Feb  5 18:19:34 2016 Benjamin Dubus
** Last update Mon Apr 25 15:17:31 2016 Benjamin Dubus
*/

#include <stdlib.h>
#include "myfx.h"

int	g_signal;

void		sig_handler(int signal)
{
  g_signal = signal;
}

void		init(t_number *nbr)
{
  nbr->idx_str = 0;
  nbr->idx_pid = 0;
  nbr->pid_client = 0;
  my_put_nbr_uint(getpid());
  my_putchar('\n');
  signal(SIGUSR2, sig_handler);
  signal(SIGUSR1, sig_handler);
}

void		set_char(t_number *nbr)
{
  char		current_char[8];

  if (nbr->tmp_sig == SIGUSR1)
  current_char[nbr->idx_str] = 0;
 else if (nbr->tmp_sig == SIGUSR2)
   current_char[nbr->idx_str] = 1;
 nbr->idx_str++;
 if (nbr->idx_str == 8)
   print_letter(nbr, current_char);
}

void		_pause(t_number *nbr)
{
  if (g_signal == 0)
    pause();
  nbr->tmp_sig = g_signal;
  g_signal = 0;
  nbr->finish = 0;
}

int		main(void)
{
  t_number	nbr;

  init(&nbr);
  while (18)
    {
      _pause(&nbr);
      if (nbr.idx_pid < 23)
        translate_pid(&nbr);
      else
        {
	  set_char(&nbr);
          if (kill(nbr.pid_client, SIGUSR1) == -1)
            {
              my_putstr("Error: Wrong pid_client", 2);
              return (EXIT_FAILURE);
            }
        }
      nbr.idx_pid++;
      if (nbr.finish == 1)
        {
	  my_putchar('\n');
          nbr.pid_client = 0;
          nbr.idx_pid = 0;
        }
    }
  return (EXIT_SUCCESS);
}
