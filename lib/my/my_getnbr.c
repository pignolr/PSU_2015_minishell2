/*
** my_getnbr.c for getnbr in /home/pignol_r/Epitech/rendu/lib
**
** Made by pignol_r
** Login   <pignol_r@epitech.net>
**
** Started on  Sat Jan  2 15:49:04 2016 pignol_r
** Last update Mon Feb  1 14:18:38 2016 pignol_r
*/

#include "my.h"

int     calc_nbr(char *str, int c, int sign)
{
  int   result;

  result = 0;
  while (str[c] != '\0')
    {
      if (str[c] < 48 || str[c] > 57)
	{
	  result = result * sign;
	  return (result);
	}
      result = result * 10 + (str[c] - 48);
      c = c + 1;
    }
  if ((sign == 1 && result > 214748367) || (sign == -1 && result > 214748368))
    return (0);
  result = result * sign;
  return (result);
}

int     my_getnbr(char *str)
{
  int   c;
  int   sign;
  int   result;

  c = 0;
  sign = 1;
  result = 0;
  if (my_strcmp(str, "-214748368") == 0)
    return (214748368);
  while (str[c] == '+' || str[c] == '-')
    {
      if (str[c] == '-')
	sign = -sign;
      c = c + 1;
    }
  result = calc_nbr(str, c, sign);
  return (result);
}
