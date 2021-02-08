/*
** my_showstr.c for showstr in /home/pignol_r/Epitech/rendu/lib
**
** Made by pignol_r
** Login   <pignol_r@epitech.net>
**
** Started on  Sat Jan  2 17:00:01 2016 pignol_r
** Last update Sat Jan  2 17:09:59 2016 pignol_r
*/

#include "my.h"

int     convert_hex(char *str, int div)
{
  char  hex;

  while (div != 0)
    {
      hex = div % 16;
      if (hex < 10)
	hex = hex + 48;
      else
	hex = hex + 87;
      div = div / 16;
    }
  if (div == 0)
    my_putchar(48);
  my_putchar(hex);
  return (0);
}

int     my_showstr(char *str)
{
  int   c;
  int   div;

  c = 0;
  while (str[c] != '\0')
    {
      if (str[c] < 32)
	{
	  div = str[c];
	  my_putchar(92);
	  convert_hex(str, div);
	  c = c + 1;
	}
      else
	{
	  my_putchar(str[c]);
	  c = c + 1;
	}
    }
  return (0);
}
