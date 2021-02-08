/*
** my_strstr.c for strstr in /home/pignol_r/Epitech/rendu/lib
**
** Made by pignol_r
** Login   <pignol_r@epitech.net>
**
** Started on  Sat Jan  2 16:43:36 2016 pignol_r
** Last update Sat Jan  2 17:11:43 2016 pignol_r
*/

#include <stdlib.h>

char    *my_strstr(char *str, char *to_find)
{
  int   c;
  int   j;
  char  *ret;

  c = 0;
  while (str[c] != '\0')
    {
      j = 0;
      while (str[c] == to_find[j])
	{
	  c = c + 1;
	  j = j + 1;
	  if (to_find[j] == '\0')
	    {
	      c = c - j;
	      ret = &(str[c]);
	      return (ret);
	    }
	}
      c = c + 1;
    }
  return (NULL);
}
