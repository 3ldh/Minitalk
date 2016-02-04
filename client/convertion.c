/*
** convertion.c for minitalk in /home/sauvau_m/rendu/PSU_2015_minitalk
**
** Made by Mathieu Sauvau
** Login   <sauvau_m@epitech.net>
**
** Started on  Thu Feb  4 18:12:16 2016 Mathieu Sauvau
** Last update Thu Feb  4 18:22:25 2016 Mathieu Sauvau
*/

#include <unistd.h>
#include <stdlib.h>
#include "function.h"
#include "client.h"

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

void	ping_pong(int pid, char c)
{
  int	i;

  i = 0;
  while (i < 8)
    {
      while (!gl_ping);
      gl_ping = false;
      send_(pid, 1 & (c >> i++));
    }
}
