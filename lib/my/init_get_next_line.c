/*
** init_get_next_line.c for get in /home/pignol_r/Epitech/rendu/PSU_2015_minishell2
**
** Made by pignol_r
** Login   <pignol_r@epitech.net>
**
** Started on  Sat Apr  2 14:02:18 2016 pignol_r
** Last update Sun Apr 10 18:49:36 2016 pignol_r
*/

#include <stdlib.h>
#include "get_next_line.h"

t_fd		*init_list_line(int fd)
{
  t_fd		*first;

  if (!(first = malloc(sizeof(t_fd))))
    return (NULL);
  first->next = NULL;
  first->fd = fd;
  first->i = 0;
  return (first);
}

char		*free_list_line(t_fd *first)
{
  t_fd		*tmp;
  t_fd		*elem;

  elem = first;
  while (elem)
    {
      tmp = elem;
      elem = elem->next;
      free(tmp);
      tmp = NULL;
    }
  first = NULL;
  return (NULL);
}
