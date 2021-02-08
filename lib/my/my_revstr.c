/*
** my_revstr.c for revstr in /home/pignol_r/Epitech/rendu/lib
**
** Made by pignol_r
** Login   <pignol_r@epitech.net>
**
** Started on  Sat Jan  2 16:36:55 2016 pignol_r
** Last update Sat Jan  2 17:08:55 2016 pignol_r
*/

#include "my.h"

char    *my_revstr(char *str)
{
  int   i;
  int   j;
  char	tmp;

  i = my_strlen(str) - 1;
  j = 0;
  while (i > j)
    {
      tmp = str[i];
      str[i] = str[j];
      str[j] = tmp;
      i--;
      j++;
    }
  return (str);
}
