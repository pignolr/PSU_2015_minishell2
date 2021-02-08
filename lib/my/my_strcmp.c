/*
** my_strcmp.c for strcmp in /home/pignol_r/Epitech/rendu/lib
**
** Made by pignol_r
** Login   <pignol_r@epitech.net>
**
** Started on  Sat Jan  2 16:44:46 2016 pignol_r
** Last update Sat Jan 23 16:13:07 2016 pignol_r
*/

#include "my.h"

int	my_strcmp(const char *s1, const char *s2)
{
  int	i;

  i = 0;
  if (my_strlen(s1) != my_strlen(s2))
    return (1);
  while (s1[i] != 0 && s2[i] != 0)
    {
      if (s1[i] != s2[i])
	return (1);
      i++;
    }
  if (s1[i] != 0 || s2[i] != 0)
    return (1);
  return (0);
}
