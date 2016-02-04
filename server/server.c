/*
** server.c for minitalk in /home/sauvau_m/rendu/PSU_2015_minitalk
**
** Made by Mathieu Sauvau
** Login   <sauvau_m@epitech.net>
**
** Started on  Mon Feb  1 18:16:12 2016 Mathieu Sauvau
** Last update Thu Feb  4 18:08:56 2016 Mathieu Sauvau
*/

#include <signal.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include "function.h"

void		check_pid(int *pid, bool *pid_done, char c)
{
  if (c == '\0')
    {
      if (!(*pid_done))
	{
	  *pid_done = true;
	  if (kill(*pid, SIGUSR1) == -1)
	    {
	      my_putstr(2, "kill failed\n");
	      exit(1);
	    }
	  return ;
	}
      else
	{
	  *pid_done = false;
	  *pid = 0;
	}
    }
}

void		convert_to_char(int sig)
{
  static char	c;
  static int	i;
  static bool	pid_done;
  static int	pid;

  c += sig << i++;
  if (i > 7)
    {
      if (!pid_done && c != 0)
	pid = pid * 10 + (c - 48);
      if (pid_done)
	my_putchar(1, (c == '\0') ? '\n' : c);
      check_pid(&pid, &pid_done, c);
      c = 0;
      i = 0;
    }
  if (pid_done)
    {
      if (kill(pid, SIGUSR1) == -1)
	{
	  my_putstr(2, "kill failed\n");
	  exit(1);
	}
    }
}

void		handle_sig(int sig)
{
  (sig == SIGUSR1) ? convert_to_char(0) : convert_to_char(1);
}

int		main()
{
  my_put_nbr(getpid());
  my_putchar(1, '\n');
  if (signal(SIGUSR1, handle_sig) == SIG_ERR
      || signal(SIGUSR2, handle_sig) == SIG_ERR)
    my_putstr(2, "signal error\n");
  while (42);
  return (0);
}
