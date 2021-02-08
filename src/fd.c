/*
** fd.c for fd in /home/pignol_r/Epitech/rendu/PSU_2015_minishell2
**
** Made by pignol_r
** Login   <pignol_r@epitech.net>
**
** Started on  Sat Apr  9 15:10:09 2016 pignol_r
** Last update Wed Apr 13 13:17:09 2016 pignol_r
*/

#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <unistd.h>
#include "my.h"
#include "prototype.h"

int		fd_stand_restor(t_all *all, int father, int pid)
{
  if (father != 1 && close(0) == -1)
    return (my_error(36));
  if (pid != 1 && close(1) == -1)
    return (my_error(36));
  if (father == 1 && (dup2(all->elem.fd[1], 1) == -1
		      || dup2(all->elem.fd[0], 0) == -1))
    return (my_error(37));
  if (pid != 1 && wait(NULL) == -1)
    return (my_error(38));
  return (0);
}

int		is_father(t_all *all, int father)
{
  if (father)
    my_exit(all);
  return (1);
}

int		is_father2(t_all *all, t_tri tri)
{
  fd_stand_restor(all, tri.father, tri.pid);
  if (tri.father != 1)
    my_exit(all);
  return (1);
}
