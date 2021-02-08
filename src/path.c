/*
** path.c for path in /home/pignol_r/Epitech/rendu/PSU_2015_minishell2
**
** Made by pignol_r
** Login   <pignol_r@epitech.net>
**
** Started on  Fri Apr  1 14:24:00 2016 pignol_r
** Last update Sun Apr 10 19:02:55 2016 pignol_r
*/

#include <stdlib.h>
#include "my.h"
#include "prototype.h"

int		get_nbr_path(char *path)
{
  int		i;
  int		n;

  i = 5;
  n = 1;
  while (path[i])
    {
      if (path[i] == ':')
	++n;
      ++i;
    }
  return (i);
}

char		*malloc_path(char *path, int *i, int j, int *tmp)
{
  char		*str;
  int		k;

  if (!(str = malloc(sizeof(char) * ((j - *tmp) + 1))))
    return (NULL);
  k = 0;
  while (*tmp < j)
    {
      str[k] = path[*tmp];
      ++k;
      ++*tmp;
    }
  str[k] = 0;
  *tmp = j + 1;
  *i = *i + 1;
  return (str);
}

char		**init_path(char *path)
{
  char		**tab_path;
  int		i;
  int		j;
  int		tmp;

  if (!(tab_path = malloc(sizeof(char *) * (get_nbr_path(path) + 1))))
    return (NULL);
  i = 0;
  j = 5;
  tmp = 5;
  while (path[j])
    {
      if (path[j] == ':' && !(tab_path[i] = malloc_path(path, &i, j, &tmp)))
	return (NULL);
      ++j;
    }
  if (!(tab_path[i] = malloc_path(path, &i, j, &tmp)))
    return (NULL);
  tab_path[i] = NULL;
  return (tab_path);
}

int		get_envstr(char **env, char *str)
{
  int		i;
  int		size;
  int		equal;

  i = 0;
  size = my_strlen(str);
  equal = (str[size - 1] == '=') ? 1 : 0;
  while (env[i])
    {
      if (!my_strncmp(env[i], str, size)
	  && (equal || env[i][size] == '='))
	return (i);
      ++i;
    }
  return (-1);
}

int		get_path(t_all *all)
{
  int		i;

  free_tab(all->elem.path);
  all->elem.path = NULL;
  if (get_home(all) || get_user(all) || get_prompt(all))
    return (1);
  if ((i = get_envstr(all->elem.env, "PATH=")) == -1)
    return (0);
  if (!(all->elem.path = init_path(all->elem.env[i])))
    return (my_error(1));
  return (0);
}
