/*
** function.c for minitalk in /home/sauvau_m/rendu/PSU_2015_minitalk
**
** Made by Mathieu Sauvau
** Login   <sauvau_m@epitech.net>
**
** Started on  Mon Feb  1 18:01:09 2016 Mathieu Sauvau
** Last update Mon Feb  1 21:11:41 2016 Mathieu Sauvau
*/

#include <unistd.h>

int	my_strlen(char *str)
{
  int	i;

  i = 0;
  while (str[i])
    i++;
  return (i);
}

void	my_putstr(int fd, char *str)
{
  write(fd, str, my_strlen(str));
}

void	my_putchar(int fd, char c)
{
  write(fd, &c, 1);
}
