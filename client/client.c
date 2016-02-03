/*
** client.c for minitalk in /home/sauvau_m/rendu/PSU_2015_minitalk
**
** Made by Mathieu Sauvau
** Login   <sauvau_m@epitech.net>
**
** Started on  Mon Feb  1 18:00:12 2016 Mathieu Sauvau
** Last update Wed Feb  3 14:39:28 2016 Mathieu Sauvau
*/

#include <signal.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include "function.h"

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

void	convert_to_bin(int pid, char c)
{
  int	i;

  i = 0;
  while (i < 8)
    {
      usleep(150);
      send_(pid, 1 & (c >> i++));
    }
}

void	do_(int pid, char *str)
{
  while (*str)
    convert_to_bin(pid, *str++);
  convert_to_bin(pid, *str);
}

int	main(int ac, char **av)
{
  int	pid;

  if (ac != 3)
    {
      my_putstr(2, "Usage : [Server PID] [String]\n");
      return (1);
    }
  pid = my_getnbr(av[1]);
  if (pid <= 0)
    {
      my_putstr(2, "Server PID must be positive\n");
      return (1);
    }
  do_(pid, av[2]);
  return (0);
}
