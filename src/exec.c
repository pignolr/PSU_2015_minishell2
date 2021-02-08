/*
** exec.c for exec in /home/pignol_r/Epitech/rendu/PSU_2015_minishell2
**
** Made by pignol_r
** Login   <pignol_r@epitech.net>
**
** Started on  Tue Apr  5 22:27:34 2016 pignol_r
** Last update Wed Apr 13 13:18:16 2016 pignol_r
*/

#include <unistd.h>
#include <stdlib.h>
#include "my.h"
#include "prototype.h"

char		*get_path_exec(t_all *all, int i)
{
  char		*path;
  int		size;

  size = my_strlen(all->elem.path[i]) + my_strlen(all->elem.arg[0]);
  if (!(path = malloc(sizeof(char) * (size + 2))))
    return (NULL);
  my_strcpy(path, all->elem.path[i]);
  my_strcat(path, "/");
  my_strcat(path, all->elem.arg[0]);
  return (path);
}

int		path_exec_next(t_all *all, int i)
{
  char		*path;

  if (!(path = get_path_exec(all, i)))
    return (my_error(17));
  if (access(path, X_OK))
    return (my_error(45));
  if (execve(path, all->elem.arg, all->elem.env) == -1)
    {
      free(path);
      free_all(all);
      my_error(18);
      exit(1);
    }
  free(path);
  free_all(all);
  exit(0);
}
