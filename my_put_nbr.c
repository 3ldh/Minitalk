/*
** my_put_nbr.c for putnbr in /home/sauvau_m/rendu/Piscine_C_J07/lib/my
**
** Made by Mathieu Sauvau
** Login   <sauvau_m@epitech.net>
**
** Started on  Tue Oct  6 17:44:34 2015 Mathieu Sauvau
** Last update Mon Feb  1 21:16:23 2016 Mathieu Sauvau
*/

#include "function.h"

int		my_put_nbr(int nb)
{
  int		div;

  if (nb < 0)
    {
      my_putchar(1, '-');
      nb = -nb;
    }
  if (nb >= 10)
    {
      div = nb % 10;
      nb = (nb - div) / 10;
      my_put_nbr(nb);
      my_putchar(1, div + '0');
    }
  else
    my_putchar(1, nb % 10 + '0');
  return (nb);
}
