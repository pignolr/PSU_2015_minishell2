/*
** my_strcat.c for strcat in /home/pignol_r/Epitech/rendu/lib
**
** Made by pignol_r
** Login   <pignol_r@epitech.net>
**
** Started on  Sat Jan  2 17:02:05 2016 pignol_r
** Last update Sat Apr  2 20:50:23 2016 pignol_r
*/

#include <stdlib.h>

void	my_strcat(char *dest, char *src)
{
  int	i;
  int	j;

  if (src == NULL)
    return ;
  i = 0;
  j = 0;
  while (dest[i])
    ++i;
  while (src[j])
    {
      dest[i] = src[j];
      ++i;
      ++j;
    }
  dest[i] = 0;
}
