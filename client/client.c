/*
** client.c for minitalk in /home/sauvau_m/rendu/PSU_2015_minitalk
**
** Made by Mathieu Sauvau
** Login   <sauvau_m@epitech.net>
**
** Started on  Mon Feb  1 18:00:12 2016 Mathieu Sauvau
** Last update Thu Feb  4 18:20:55 2016 Mathieu Sauvau
*/

#include <signal.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include "function.h"
#include "client.h"

void	send_(int pid, int bit)
{
  int	sig;

  (bit == 0) ? (sig = SIGUSR1) : (sig = SIGUSR2);
  if (kill(pid, sig) == -1)
    {
      my_putstr(2, "kill failed\n");
      exit(1);
    }
}

void	do_(int pid, char *str, bool _ping_pong)
{
  if (!_ping_pong)
    {
      while (*str)
	convert_to_bin(pid, *str++);
      convert_to_bin(pid, *str);
    }
  else
    {
      while (*str)
	ping_pong(pid, *str++);
      ping_pong(pid, *str);
    }
}

void	handle_sig(int sig)
{
  if (sig == SIGUSR1)
    gl_ping = true;
}

int	main(int ac, char **av)
{
  int	server_pid;
  char	*client_pid;

  if (signal(SIGUSR1, handle_sig) == SIG_ERR)
    my_putstr(2, "signal error\n");
  if ((client_pid = malloc(10)) == NULL)
    return (1);
  if (itoa(getpid(), client_pid, 10) == NULL)
    return (1);
  if (ac != 3)
    {
      my_putstr(2, "Usage : [Server PID] [String]\n");
      return (1);
    }
  server_pid = my_getnbr(av[1]);
  if (server_pid <= 0)
    {
      my_putstr(2, "Server PID must be positive\n");
      return (1);
    }
  do_(server_pid, client_pid, false);
  while (!gl_ping);
  do_(server_pid, av[2], true);
  free(client_pid);
  return (0);
}
