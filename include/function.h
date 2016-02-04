/*
** function.h for function in /home/sauvau_m/rendu/PSU_2015_minitalk
**
** Made by Mathieu Sauvau
** Login   <sauvau_m@epitech.net>
**
** Started on  Mon Feb  1 18:05:38 2016 Mathieu Sauvau
** Last update Wed Feb  3 22:42:54 2016 Mathieu Sauvau
*/

#ifndef _FUNCTION_H_

#define _FUNCTION_H_

typedef enum{false, true} bool;
bool gl_ping;

/*
**function
*/
int	my_strlen(char *str);
void	my_putstr(int fd, char *str);
void	my_putchar(int fd, char c);
int	my_getnbr(char *str);
int	my_put_nbr(int nb);
char	*itoa(int, char*, int);
char	*my_revstr(char *);
char	*my_strcat(char *, char *);

#endif /* ! _FUNCTION_H_ */
