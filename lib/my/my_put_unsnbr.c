/*
** my_put_unsnbr.c for unsigned int in /home/pignol_r/rendu/PSU_2015_my_printf/lib/my
** 
** Made by remi pignol
** Login   <pignol_r@epitech.net>
** 
** Started on  Sat Nov  7 12:54:30 2015 remi pignol
** Last update Sat Nov  7 13:18:02 2015 remi pignol
*/

#include "my.h"

int		my_put_unsnbr(unsigned int nb)
{
  unsigned int	reste;

  if (nb >= 0)
    {
      if (nb > 9)
        {
          reste = nb % 10;
          nb = nb / 10;
          my_put_unsnbr(nb);
          my_putchar(48 + reste);
        }
      else
        my_putchar(48 + nb);
    }
  return (0);
}
