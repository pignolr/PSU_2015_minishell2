/*
** free.c for free in /home/pignol_r/Epitech/rendu/PSU_2015_minishell2
**
** Made by pignol_r
** Login   <pignol_r@epitech.net>
**
** Started on  Fri Apr  1 13:08:32 2016 pignol_r
** Last update Sun Apr 10 16:15:48 2016 pignol_r
*/

#include <stdlib.h>
#include <unistd.h>
#include "my.h"
#include "prototype.h"

void		free_all(t_all *all)
{
  int		i;

  i = 0;
  while (i < N_TAB)
    {
      free_tab(all->free.f_tab[i]);
      all->free.f_tab[i] = NULL;
      ++i;
    }
  i = 0;
  while (i < N_STR)
    {
      free(all->free.f_str[i]);
      all->free.f_str[i] = NULL;
      ++i;
    }
  close(all->elem.fd[0]);
  close(all->elem.fd[1]);
}

void		free_tab(char **tab)
{
  int		i;

  i = 0;
  if (tab)
    while (tab[i])
      {
	free(tab[i]);
	tab[i] = NULL;
	++i;
      }
  free(tab);
  tab = NULL;
}
