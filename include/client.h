/*
** clent.h for minitalk in /home/sauvau_m/rendu/PSU_2015_minitalk
**
** Made by Mathieu Sauvau
** Login   <sauvau_m@epitech.net>
**
** Started on  Thu Feb  4 18:14:36 2016 Mathieu Sauvau
** Last update Thu Feb  4 18:21:47 2016 Mathieu Sauvau
*/

#ifndef _CLIENT_H_

#define _CLIENT_H_

void	convert_to_bin(int pid, char c);
void	ping_pong(int pid, char c);
void	send_(int pid, int bit);

#endif /* ! _CLIENT_H_ */
