/*
** path_next.c for path in /home/pignol_r/Epitech/rendu/PSU_2015_minishell2
**
** Made by pignol_r
** Login   <pignol_r@epitech.net>
**
** Started on  Fri Apr  1 15:39:21 2016 pignol_r
** Last update Wed Apr  6 19:51:03 2016 pignol_r
*/

#include <stdlib.h>
#include "my.h"
#include "prototype.h"

int		get_home(t_all *all)
{
  int		i;
  int		j;

  if ((i = get_envstr(all->elem.env, "HOME=")) < 0)
    return (0);
  free(all->elem.home);
  if (!(all->elem.home = malloc(my_strlen(all->elem.env[i]) - 4)))
    return (my_error(13));
  j = 0;
  while (all->elem.env[i][j + 5])
    {
      all->elem.home[j] = all->elem.env[i][j + 5];
      ++j;
    }
  all->elem.home[j] = 0;
  return (0);
}

int		get_user(t_all *all)
{
  int		i;
  int		j;

  if ((i = get_envstr(all->elem.env, "USER=")) < 0)
    return (0);
  free(all->elem.user);
  if (!(all->elem.user = malloc(my_strlen(all->elem.env[i]) - 4)))
    return (my_error(13));
  j = 0;
  while (all->elem.env[i][j + 5])
    {
      all->elem.user[j] = all->elem.env[i][j + 5];
      ++j;
    }
  all->elem.user[j] = 0;
  return (0);
}

void		put_tab_path(char *path, char **tab_path)
{
  int		i;
  int		j;
  int		k;

  i = 5;
  j = 0;
  k = 0;
  while (path[i])
    {
      if (path[i] == ':')
	{
	  k = -1;
	  ++j;
	}
      else
	tab_path[j][k] = path[i];
      k++;
      i++;
    }
}
