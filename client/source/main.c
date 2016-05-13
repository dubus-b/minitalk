/*
** main.c for main in /home/dubus_b/rendu/Unix/PSU_2015_minitalk
** 
** Made by Benjamin Dubus
** Login   <dubus_b@epitech.net>
** 
** Started on  Mon Feb  1 18:58:48 2016 Benjamin Dubus
** Last update Fri Mar  4 18:39:04 2016 Benjamin Dubus
*/

#include <sys/types.h>
#include <unistd.h>
#include <signal.h>
#include <stdlib.h>
#include "myfx.h"

int		g_signal;

void		send_pid(pid_t pid_client, pid_t pid_server)
{
  int		idx;
  int		result;

  idx = 22;
  while (idx >= 0)
    {
      result = (pid_client >> idx) & 1;
      if (result == 0)
        kill(pid_server, SIGUSR1);
      else
        kill(pid_server, SIGUSR2);
      usleep(10000);
      idx--;
    }
}

void		send_eot(pid_t pid_server)
{
  int		idx;
  int		result;
  char		letter;

  idx = 7;
  letter = 4;
  while (idx >= 0)
    {
      result = (letter >> idx) & 1;
      if (result == 0)
        kill(pid_server, SIGUSR1);
      else
        kill(pid_server, SIGUSR2);
      while (g_signal == 0)
        usleep(100);
      g_signal = 0;
      idx--;
    }
}

void		send_str(char *str, pid_t pid_server, int index_str)
{
  int		idx;
  int		result;

  while (str[index_str] != '\0')
    {
      idx = 7;
      while (idx >= 0)
	{
	  result = (str[index_str] >> idx) & 1;
	  if (result == 0)
	    {
	      if (kill(pid_server, SIGUSR1) == -1)
		exit(EXIT_FAILURE);
	    }
	  else
	    if (kill(pid_server, SIGUSR2) == -1)
	      exit(EXIT_FAILURE);
	  while (g_signal == 0)
	    usleep(100);
	  g_signal = 0;
	  idx--;
	}
      index_str++;
    }
}

void		sig_handler(int signal)
{
  g_signal = signal;
}

int		main(int argc, char **argv)
{
  pid_t		pid_client;
  pid_t		pid_server;
  char		*str;

  signal(SIGUSR1, sig_handler);
  g_signal = 0;
  pid_server = my_getnbr(argv[1]);
  pid_client  = getpid();
  str = argv[2];
  if (argc != 3)
    {
      my_putstr("Usage:./client [PID] [String]\n", 2);
      return (0);
    }
  if (pid_client > 4194303)
    {
      my_putstr("Error: pid_client is too big", 2);
      return (0);
    }
  send_pid(pid_client, pid_server);
  send_str(str, pid_server, 0);
  send_eot(pid_server);
  return (0);
}
