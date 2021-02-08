/*
** buil_exec.c for buil_exec in /home/pignol_r/Epitech/rendu/PSU_2015_minishell2
**
** Made by pignol_r
** Login   <pignol_r@epitech.net>
**
** Started on  Tue Apr  5 15:06:10 2016 pignol_r
** Last update Tue Apr 12 14:47:46 2016 pignol_r
*/

#include <stdlib.h>
#include "my.h"
#include "tabptr.h"

int		buil_env(t_all *all)
{
  aff_tab(all->elem.env);
  return (0);
}

int		buil_exit(t_all *all)
{
  int		nb;

  nb = 0;
  if (all->elem.arg[1])
    {
      if (my_str_isnum(all->elem.arg[1]) || all->elem.arg[2])
	return (my_error(39) - 1);
      else
	nb = my_getnbr(all->elem.arg[1]);
    }
  free_all(all);
  get_next_line(-1);
  my_putstr("exit\n");
  exit(nb);
}

int		buil_exec(t_all *all)
{
  int		i;

  i = 0;
  while (g_ptr_buil[i].flag && my_strcmp(g_ptr_buil[i].flag, all->elem.arg[0]))
    ++i;
  if (g_ptr_buil[i].flag)
    return (g_ptr_buil[i].ptr(all));
  return (1);
}
