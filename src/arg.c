/*
** arg.c for arg in /home/pignol_r/Epitech/rendu/PSU_2015_minishell2
**
** Made by pignol_r
** Login   <pignol_r@epitech.net>
**
** Started on  Wed Apr  6 17:29:03 2016 pignol_r
** Last update Thu Apr  7 18:47:13 2016 pignol_r
*/

#include <stdlib.h>
#include "prototype.h"
#include "my.h"

int		free_arg_son(t_all *all, int i)
{
  int		j;

  j = 0;
  while (j != i)
    {
      free(all->elem.arg[j]);
      all->elem.arg[j] = NULL;
      ++j;
    }
  while (all->elem.arg[j])
    ++j;
  return (j);
}

int		new_arg_son(t_all *all, int i)
{
  char		**new;
  int		j;

  ++i;
  if (!all->elem.arg[i])
    return (my_error(31));
  j = free_arg_son(all, i);
  if (!(new = malloc(sizeof(char *) * ((j - i) + 1))))
    return (my_error(32));
  j = 0;
  while (all->elem.arg[i])
    {
      new[j] = all->elem.arg[i];
      ++i;
      ++j;
    }
  new[j] = NULL;
  free(all->elem.arg);
  all->elem.arg = new;
  return (0);
}

void		free_arg_father(t_all *all, int i)
{
  while (all->elem.arg[i])
    {
      free(all->elem.arg[i]);
      all->elem.arg[i] = NULL;
      ++i;
    }
}

int		new_arg_father(t_all *all, int i)
{
  char		**new;
  int		j;

  if (!i)
    return (my_error(31));
  if (!(new = malloc(sizeof(char *) * (i + 1))))
    return (my_error(33));
  j = 0;
  while (j != i)
    {
      new[j] = all->elem.arg[j];
      ++j;
    }
  new[j] = NULL;
  free_arg_father(all, i);
  free(all->elem.arg);
  all->elem.arg = new;
  return (0);
}
