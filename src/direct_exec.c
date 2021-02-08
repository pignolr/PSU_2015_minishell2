/*
** direct_exec.c for direct_exec in /home/pignol_r/Epitech/rendu/PSU_2015_minishell2
**
** Made by pignol_r
** Login   <pignol_r@epitech.net>
**
** Started on  Sun Apr  3 20:17:13 2016 pignol_r
** Last update Wed Apr 13 15:12:33 2016 remi pignol
*/

#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <unistd.h>
#include <dirent.h>
#include "prototype.h"
#include "my.h"

int		is_path(char *str)
{
  int		i;

  i = 0;
  while (str[i])
    {
      if (str[i] == '/')
	return (0);
      ++i;
    }
  return (1);
}

int		direct_exec(t_all *all)
{
  pid_t		pid;
  int		status;

  if (!is_path(all->elem.arg[0]) && !access(all->elem.arg[0], X_OK))
    {
      if ((pid = fork()) == -1)
	return (my_error(5) - 2);
      if (!pid)
	{
	  if (execve(all->elem.arg[0], all->elem.arg, all->elem.env) == -1)
	    write(2, ERR_EXEC, my_strlen(ERR_EXEC));
	  free_all(all);
	  exit(1);
	}
      else if (wait(&status) == -1)
	return (my_error(6) - 2);
      if ((status % 32) == 11)
	write(2, "Segmentation Fault\n", my_strlen("Segmentation Fault\n"));
      return (0);
    }
  else
    return (1);
}

int		path_exec(t_all *all, DIR *path, int i)
{
  pid_t		pid;
  int		status;

  if (closedir(path) == -1)
    return (my_error(14) - 2);
  if ((pid = fork()) == -1)
    return (my_error(15) - 2);
  if (!pid && path_exec_next(all, i))
    return (-1);
  if (wait(&status) == -1)
    return (my_error(16) - 2);
  if ((status % 32) == 11)
    write(2, "Segmentation Fault\n", my_strlen("Segmentation Fault\n"));
  return (0);
}

int		other_exec(t_all *all)
{
  DIR		*path;
  struct dirent	*prog;
  int		i;

  if (!buil_exec(all))
    return (0);
  i = 0;
  prog = NULL;
  if (!all->elem.path)
    return (1);
  while (all->elem.path[i])
    {
      if (!(path = opendir(all->elem.path[i])))
	return (my_error(7) - 2);
      while ((prog = readdir(path)))
	if (!my_strcmp(prog->d_name, all->elem.arg[0]))
	  return (path_exec(all, path, i));
      if ((closedir(path)) == -1)
	return (my_error(8) - 2);
      ++i;
    }
  return (1);
}
