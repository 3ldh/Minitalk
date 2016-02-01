/*
** server.c for minitalk in /home/sauvau_m/rendu/PSU_2015_minitalk
**
** Made by Mathieu Sauvau
** Login   <sauvau_m@epitech.net>
**
** Started on  Mon Feb  1 18:16:12 2016 Mathieu Sauvau
** Last update Mon Feb  1 21:33:34 2016 Mathieu Sauvau
*/

#include <signal.h>
#include <unistd.h>
#include "function.h"

void		convert_to_char(int sig)
{
  static char	c;
  static int	i;

  c += sig << i++;
  if (i > 7)
    {
      my_putchar(1, (c == '\0') ? '\n' : c);
      c = 0;
      i = 0;
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
  while (42)
    pause();
  return (0);
}
