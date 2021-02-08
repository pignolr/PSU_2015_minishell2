/*
** main.c for main in /home/pignol_r/Epitech/rendu/PSU_2015_minishell2
**
** Made by pignol_r
** Login   <pignol_r@epitech.net>
**
** Started on  Fri Apr  1 17:44:14 2016 pignol_r
** Last update Wed Apr 13 13:28:34 2016 pignol_r
*/

#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include "prototype.h"
#include "my.h"

int		nb_arg(char *str)
{
  int		i;
  int		nb;

  i = 0;
  nb = 1;
  while (str[i] && (str[i] != ';' || (i && str[i - 1] == '\\')))
    {
      if (str[i] == ' ')
	++nb;
      ++i;
    }
  return (i);
}

char		*parsing_arg(char *str, int i, int j)
{
  char		*tab;

  if (!(tab = malloc(sizeof(char) * ((i - j) + 1))))
    return (NULL);
  i = 0;
  while (str[j] && str[j] != ' ')
    {
      tab[i] = str[j];
      ++i;
      ++j;
    }
  tab[i] = 0;
  return (tab);
}

int		launcher_next(t_all *all, int i)
{
  char		*str;
  int		j;
  int		k;

  str = all->elem.str;
  if (!(all->elem.arg = malloc(sizeof(char *) * (nb_arg(str) + 1))))
    return (my_error(4) - 2);
  k = 0;
  if (str[i] == ' ')
    ++i;
  while (str[i] && (str[i] != ';' || (i && str[i - 1] == '\\')))
    {
      j = i;
      while (str[i] && str[i] != ' ')
	++i;
      if (!(all->elem.arg[k] = parsing_arg(str, i, j)))
	return (my_error(4) - 2);
      if (str[i] == ' ')
	++i;
      ++k;
    }
  all->elem.arg[k] = NULL;
  if ((str[i] == ';' && (!i || str[i - 1] != '\\')))
    ++i;
  return (i);
}

int		launcher(t_all *all)
{
  int		i;

  if (!(all->elem.str = mini_epur(all->elem.str)))
    return (my_error(2));
  if (str_isredirect(all->elem.str))
    return (my_error(40));
  i = 0;
  while (all->elem.str && all->elem.str[i])
    {
      if ((i = launcher_next(all, i)) == -1)
	return (1);
      tri_exec(all);
      free_tab(all->elem.arg);
      all->elem.arg = NULL;
    }
  return (0);
}

int		main(int ac, char **av, const char **env)
{
  t_all		all;

  (void)ac;
  (void)av;
  if (!init_all(&all) && (all.elem.env = env_init(env)) && !get_path(&all))
    {
      my_printf("\033[1;34m%s\033[0;00m", all.elem.prompt);
      while ((all.elem.str = get_next_line(0)))
	{
	  launcher(&all);
	  free(all.elem.str);
	  my_printf("\033[1;34m%s\033[0;00m", all.elem.prompt);
	}
      my_putstr("exit\n");
    }
  get_next_line(-1);
  free_all(&all);
  return (0);
}
