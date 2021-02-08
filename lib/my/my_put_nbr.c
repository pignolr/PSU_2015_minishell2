/*
** my_put_nbr.c for put_nbr in /home/pignol_r/Epitech/rendu/lib
**
** Made by pignol_r
** Login   <pignol_r@epitech.net>
**
** Started on  Sat Jan  2 15:37:40 2016 pignol_r
** Last update Sat Jan  2 15:48:38 2016 pignol_r
*/

#include "my.h"

void	my_put_nbr(int n)
{
  if (n < 0)
    {
      my_putchar('-');
      n *= -1;
    }
  if (n > 9)
    {
      my_put_nbr(n / 10);
      my_putchar(48 + (n % 10));
    }
  else
    my_putchar(n + 48);
}
