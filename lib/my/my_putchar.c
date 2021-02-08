/*
** my_putchar.c for putchar in /home/pignol_r/Epitech/rendu/lib
**
** Made by pignol_r
** Login   <pignol_r@epitech.net>
**
** Started on  Sat Jan  2 14:53:21 2016 pignol_r
** Last update Sat Jan  2 14:59:06 2016 pignol_r
*/

#include <unistd.h>

void	my_putchar(char c)
{
  write(1, &c, 1);
}
