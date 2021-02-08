/*
** buil.c for buil in /home/pignol_r/Epitech/rendu/PSU_2015_minishell2
**
** Made by pignol_r
** Login   <pignol_r@epitech.net>
**
** Started on  Fri Apr  1 18:14:53 2016 pignol_r
** Last update Tue Apr 12 14:47:39 2016 pignol_r
*/

#include <stdlib.h>
#include <unistd.h>
#include "my.h"
#include "prototype.h"

void		aff_tab(char **tab)
{
  int		i;

  i = 0;
  while (tab[i])
    {
      my_putstr(tab[i]);
      my_putchar('\n');
      ++i;
    }
}

void		set_pwd(t_all *all, char *pwd)
{
  free(all->elem.oldpwd);
  all->elem.oldpwd = all->elem.pwd;
  all->elem.pwd = pwd;
}

int		buil_cd(t_all *all)
{
  char		*pwd;

  if (!all->elem.arg[1] && all->elem.home)
    {
      if (chdir(all->elem.home) == -1)
	return (my_error(9) - 1);
    }
  else if (all->elem.arg[2])
    return (my_error(10) - 1);
  else if ((!my_strcmp("-", all->elem.arg[1]) && chdir(all->elem.oldpwd) == -1)
	   || (my_strcmp("-", all->elem.arg[1])
	       && chdir(all->elem.arg[1]) == -1))
    return (my_error(11) - 1);
  pwd = NULL;
  pwd = getcwd(pwd, 0);
  if (!(pwd = (realloc(pwd, my_strlen(pwd) + 1))))
    return (my_error(25));
  if (env_replace(all, "PWD", pwd, get_envstr(all->elem.env, "PWD=")) ||
      env_replace(all, "OLDPWD", all->elem.pwd, get_envstr
		  (all->elem.env, "OLDPWD=")))
    return (0);
  set_pwd(all, pwd);
  get_prompt(all);
  return (0);
}

int		buil_setenv(t_all *all)
{
  if (!all->elem.arg[1])
    return (my_error(19) - 1);
  else if (all->elem.arg[2] && all->elem.arg[3])
    return (my_error(51) - 1);
  else if (my_str_isalpha(all->elem.arg[1]))
    return (my_error(20) - 1);
  env_replace(all, all->elem.arg[1], all->elem.arg[2],
	      get_envstr(all->elem.env, all->elem.arg[1]));
  get_path(all);
  return (0);
}

int		buil_unsetenv(t_all *all)
{
  int		j;
  int		i;

  if (!all->elem.arg[1])
    return (my_error(23) - 1);
  j = 1;
  while (all->elem.arg[j])
    {
      if (my_str_isalpha(all->elem.arg[j]))
	return (my_error(20) - 1);
      if ((i = get_envstr(all->elem.env, all->elem.arg[j])) > 0)
	env_delete(all, i);
      ++j;
    }
  get_path(all);
  return (0);
}
