/*
** my_realloc.c for my_realloc in /home/pignol_r/Epitech/rendu/PSU_2015_minishell2
**
** Made by pignol_r
** Login   <pignol_r@epitech.net>
**
** Started on  Thu Mar 31 20:19:06 2016 pignol_r
** Last update Sat Apr  2 14:17:58 2016 pignol_r
*/

#include <stdlib.h>
#include "my.h"

char		*my_realloc(char *old_ptr, int size)
{
  char		*new_ptr;

  if (!(new_ptr = malloc(size + 1)))
    {
      free(old_ptr);
      return (NULL);
    }
  my_strncpy(new_ptr, old_ptr, size);
  free(old_ptr);
  old_ptr = new_ptr;
  return (new_ptr);
}
