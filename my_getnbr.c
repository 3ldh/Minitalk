/*
** my_getnbr.c for getnbr in /home/sauvau_m/rendu/Piscine_C_J04
**
** Made by Mathieu Sauvau
** Login   <sauvau_m@epitech.net>
**
** Started on  Fri Oct  2 09:31:48 2015 Mathieu Sauvau
** Last update Mon Feb  1 18:13:55 2016 Mathieu Sauvau
*/

int	my_getnbr(char *str)
{
  int	nb;
  int	i;

  i = 0;
  nb = 0;
  while ((str[i] == '-' || str[i] == '+') && str[1] != '\0')
    i++;
  while (str[i] != '\0')
    {
      if ((str[i] < '0' || str[i] > '9'))
	return (nb / 10);
      nb = nb + str[i] - '0';
      nb *= 10;
      i++;
    }
  nb /= 10;
  if (str[0] == '-')
    nb *= -1;
  return (nb);
}
