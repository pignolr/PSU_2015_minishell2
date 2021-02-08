/*
** my_strncat.c for strncat in /home/pignol_r/Epitech/rendu/lib
**
** Made by pignol_r
** Login   <pignol_r@epitech.net>
**
** Started on  Sat Jan  2 17:03:01 2016 pignol_r
** Last update Sat Jan  2 17:10:48 2016 pignol_r
*/

#include "my.h"

char    *my_strncat(char *dest, char *src, int nb)
{
  int   c;
  int   d;
  char  *ret;

  c = 0;
  d = 0;
  while (dest[c] != '\0')
    c = c + 1;
  while (src[d] != '\0' && d < nb)
    {
      dest[c] = src[d];
      c = c + 1;
      d = d + 1;
    }
  c = 0;
  while (dest[c] != '\0')
    {
      my_putchar(dest[c]);
      c = c + 1;
    }
  ret = &(dest[0]);
  return (ret);
}
