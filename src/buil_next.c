/*
** buil_next.c for buil_next in /home/pignol_r/Epitech/rendu/PSU_2015_minishell2
**
** Made by pignol_r
** Login   <pignol_r@epitech.net>
**
** Started on  Wed Apr  6 11:27:35 2016 pignol_r
** Last update Wed Apr  6 18:30:18 2016 pignol_r
*/

#include <stdlib.h>
#include "my.h"
#include "prototype.h"

int		env_add(t_all *all, char *env, char *str, int size)
{
  int		i;
  char		**new;

  i = 0;
  while (all->elem.env[i])
    ++i;
  if (!(new = malloc(sizeof(char *) * (i + 2))))
    return (my_error(21));
  i = 0;
  while (all->elem.env[i])
    {
      new[i] = all->elem.env[i];
      ++i;
    }
  free(all->elem.env);
  all->elem.env = new;
  if (!(new[i] = malloc(sizeof(char) * (size + 2))))
    return (my_error(22));
  new[i + 1] = NULL;
  my_strcpy(all->elem.env[i], env);
  my_strcat(all->elem.env[i], "=");
  my_strcat(all->elem.env[i], str);
  return (0);
}

int		env_replace(t_all *all, char *env, char *str, int i)
{
  int		size;

  size = my_strlen(env) + my_strlen(str);
  if (i == -1)
    return (env_add(all, env, str, size));
  if (all->elem.env[i] && !(all->elem.env[i] = my_realloc
			    (all->elem.env[i], sizeof(char) * (size + 1))))
    return (my_error(12));
  my_strcpy(all->elem.env[i], env);
  my_strcat(all->elem.env[i], "=");
  my_strcat(all->elem.env[i], str);
  return (0);
}

void		env_delete(t_all *all, int del)
{
  char		**new;
  int		i;
  int		next;

  i = 0;
  while (all->elem.env[i])
    ++i;
  if (!(new = malloc(sizeof(char *) * (i + 1))))
    {
      my_error(24);
      return ;
    }
  i = 0;
  next = 0;
  while (all->elem.env[i] && all->elem.env[i + next])
    {
      next = (i < del) ? 0 : 1;
      if (i == del)
	free(all->elem.env[i]);
      new[i] = all->elem.env[i + next];
      ++i;
    }
  new[i] = NULL;
  free(all->elem.env);
  all->elem.env = new;
}
