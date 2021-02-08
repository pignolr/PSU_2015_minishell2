/*
** my_strcapitalize.c for my_strcapitalize in /home/pignol_r/Epitech/rendu/lib
**
** Made by pignol_r
** Login   <pignol_r@epitech.net>
**
** Started on  Sat Jan  2 16:52:38 2016 pignol_r
** Last update Sat Jan  2 17:10:31 2016 pignol_r
*/

#include "my.h"

char    capitalizer_conditionner(char *str, int c)
{
  if (str[c - 1] < 48 && str[c - 1] > 0)
    str[c] = str[c] - 32;
  if (str[c - 1] > 57 && str[c - 1] < 65)
    str[c] = str[c] - 32;
  if (str[c - 1] > 91 && str[c - 1] < 97)
    str[c] = str[c] - 32;
  if (str[c - 1] > 122)
    str[c] = str[c] - 32;
  return (str[c]);
}

char    *my_strcapitalize(char *str)
{
  int   c;

  c = 0;
  while (str[c] != '\0')
    {
      if (str[c] > 96 && str[c] < 123)
	{
	  if (c == 0)
	    {
	      str[c] = str[c] - 32;
	      c = c + 1;
	    }
	  capitalizer_conditionner(str, c);
	}
      c = c + 1;
    }
  my_putstr(str);
  return (str);
}
