/*
** init.c for init in /home/pignol_r/Epitech/rendu/PSU_2015_minishell2
**
** Made by pignol_r
** Login   <pignol_r@epitech.net>
**
** Started on  Fri Apr  1 13:32:56 2016 pignol_r
** Last update Sun Apr 10 16:16:58 2016 pignol_r
*/

#include <stdlib.h>
#include <unistd.h>
#include "prototype.h"
#include "my.h"

int		init_home(t_all *all)
{
  if (!(all->elem.home = malloc(sizeof(char) * 6)))
    return (my_error(0));
  my_strcpy(all->elem.home, "/home");
  return (0);
}

int		init_pwd(t_all *all)
{
  all->elem.pwd = NULL;
  if (!(all->elem.pwd = getcwd(all->elem.pwd, 0)))
    return (my_error(0));
  return (0);
}

int		init_user(t_all *all)
{
  if (!(all->elem.user = malloc(sizeof(char) * 5)))
    return (my_error(0));
  my_strcpy(all->elem.user, "toto");
  return (0);
}

int		init_all(t_all *all)
{
  int		i;

  i = 0;
  while (i < N_TAB)
    {
      all->free.f_tab[i] = NULL;
      i++;
    }
  i = 0;
  while (i < N_STR)
    {
      all->free.f_str[i] = NULL;
      i++;
    }
  if ((all->elem.fd[0] = dup(0)) == -1 || (all->elem.fd[1] = dup(1)) == -1
      || init_home(all) || init_pwd(all) || init_user(all))
    return (1);
  return (0);
}
