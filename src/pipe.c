/*
** pipe.c for pipe in /home/pignol_r/Epitech/rendu/PSU_2015_minishell2
**
** Made by pignol_r
** Login   <pignol_r@epitech.net>
**
** Started on  Thu Apr  7 16:44:38 2016 pignol_r
** Last update Wed Apr 13 13:14:27 2016 pignol_r
*/

#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <unistd.h>
#include "my.h"
#include "prototype.h"

int		is_pipe(char **arg)
{
  int		i;

  i = 0;
  while (arg[i] && my_strcmp(arg[i], "|"))
    ++i;
  if (!arg[i])
    return (0);
  else
    return (i);
}

int		pipe_init(t_all *all, t_tri *tri)
{
  if (!tri->pid)
    {
      if (new_arg_son(all, tri->i))
	return (1);
      if (close(tri->pipefd[1]) == -1)
	return (my_error(27));
      if (dup2(tri->pipefd[0], 0) == -1)
	return (my_error(28));
      if (close(tri->pipefd[0]) == -1)
	return (my_error(27));
    }
  else
    {
      if (new_arg_father(all, tri->i))
	return (1);
      if (close(tri->pipefd[0]) == -1)
	return (my_error(27));
      if (dup2(tri->pipefd[1], 1) == -1)
	return (my_error(28));
      if (close(tri->pipefd[1]) == -1)
	return (my_error(27));
    }
  return (0);
}

int		exec_father(t_all *all)
{
  int		err;

  err = direct_exec(all);
  if (err == -1)
    return (1);
  else if (err && !(err = other_exec(all)))
    return (0);
  else if (err == 1)
    {
      write(2, "\033[1;35m", my_strlen("\033[1;31m"));
      write(2, all->elem.arg[0], my_strlen(all->elem.arg[0]));
      write(2, "\033[0;35m: command not found\n\033[00m",
	    my_strlen("\033[0;35m: command not found\n\033[00m"));
    }
  return (0);
}

void		my_exit(t_all *all)
{
  free_all(all);
  get_next_line(-1);
  exit(0);
}

int		tri_exec(t_all *all)
{
  t_tri		tri;

  tri.father = 0;
  tri.pid = 0;
  while (!tri.pid)
    {
      tri.pid = 1;
      if ((tri.i = is_pipe(all->elem.arg))
	  && ((pipe(tri.pipefd) == -1) || (tri.pid = fork()) == -1))
	return (is_father(all, tri.father));
      if (tri.pid != 1 && pipe_init(all, &tri))
	return (is_father(all, tri.father));
      ++tri.father;
    }
  if (redirect(all))
    return (is_father2(all, tri));
  exec_father(all);
  fd_stand_restor(all, tri.father, tri.pid);
  if (tri.father != 1)
    my_exit(all);
  return (0);
}
