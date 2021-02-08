/*
** check_redirect.c for check_redirect in /home/pignol_r/Epitech/rendu/PSU_2015_minishell2
**
** Made by pignol_r
** Login   <pignol_r@epitech.net>
**
** Started on  Sat Apr  9 21:09:00 2016 pignol_r
** Last update Tue Apr 12 16:14:04 2016 pignol_r
*/

#include <unistd.h>
#include <stdlib.h>
#include "my.h"
#include "tabptr.h"

void		red_new_tab(t_all *all, int *pos)
{
  int		i;

  i = *pos;
  free(all->elem.arg[i]);
  free(all->elem.arg[i + 1]);
  while (all->elem.arg[i + 2])
    {
      all->elem.arg[i] = all->elem.arg[i + 2];
      ++i;
    }
  all->elem.arg[i] = NULL;
  *pos -= 1;
}

int		redirect(t_all *all)
{
  int		i;
  int		j;

  i = 0;
  while (all->elem.arg[i])
    {
      if (my_strlen(all->elem.arg[i]) <= 2)
	{
	  j = 0;
	  while (g_ptr_redirect[j].flag &&
		 my_strcmp(all->elem.arg[i], g_ptr_redirect[j].flag))
	    ++j;
	  if (g_ptr_redirect[j].flag && !all->elem.arg[i + 1])
	    return (my_error(41));
	  else if (g_ptr_redirect[j].flag && g_ptr_redirect[j].ptr(all, i))
	    return (1);
	  if (g_ptr_redirect[j].flag)
	    red_new_tab(all, &i);
	}
      ++i;
    }
  return (0);
}

void		reset_redirect(int *redirect, int *pipe)
{
  redirect[0] = 0;
  redirect[1] = 0;
  *pipe = 0;
}

int		check_redirect(char *word, int *redirect, int *pipe)
{
  if (!my_strcmp(word, "|"))
    {
      if (redirect[0])
	return (1);
      *pipe = 1;
    }
  else if (!my_strcmp(word, ">") || !my_strcmp(word, ">>"))
    {
      if (redirect[0])
	return (1);
      redirect[0] = 1;
    }
  else if (!my_strcmp(word, "<") || !my_strcmp(word, "<<"))
    {
      if (redirect[1] || *pipe)
	return (1);
      redirect[1] = 1;
    }
  else if (!my_strcmp(word, ";"))
    reset_redirect(redirect, pipe);
  return (0);
}

int		str_isredirect(char *str)
{
  char		word[4];
  int		redirect[2];
  int		pipe;
  int		i;
  int		j;

  reset_redirect(redirect, &pipe);
  i = 0;
  while (str[i])
    {
      j = 0;
      while (str[i] && str[i] != ' ' && j != 4)
	{
	  word[j] = str[i];
	  ++j;
	  ++i;
	}
      word[j] = 0;
      while (str[i] && str[i - 1] != ' ')
	++i;
      if (check_redirect(word, redirect, &pipe))
	return (1);
    }
  return (0);
}
