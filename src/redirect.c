/*
** redirect.c for redirect in /home/pignol_r/Epitech/rendu/PSU_2015_minishell2
**
** Made by pignol_r
** Login   <pignol_r@epitech.net>
**
** Started on  Sun Apr 10 16:23:10 2016 pignol_r
** Last update Sun Apr 10 18:53:30 2016 pignol_r
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include "my.h"
#include "prototype.h"

int		red_open_simple(t_all *all, int i)
{
  int		fd;

  if ((fd = open(all->elem.arg[i + 1], O_RDONLY)) == -1)
    return (my_error(46));
  if (dup2(fd, 0) == -1)
    return (my_error(43));
  if (close(fd) == -1)
    return (my_error(44));
  return (0);
}

int		red_open_double(t_all *all, int i)
{
  char		*str;
  int		fd;

  if ((fd = open("/tmp/minishell", O_RDWR | O_CREAT | O_TRUNC, 0666)) == -1)
    return (my_error(47));
  my_putstr("? ");
  while ((str = get_next_line(0)) && my_strcmp(all->elem.arg[i + 1], str))
    {
      if (write(fd, str, my_strlen(str)) == -1
	  || write(fd, "\n", 1) == -1)
	return (my_error(48));
      my_putstr("? ");
      free(str);
    }
  free(str);
  get_next_line(-1);
  if (lseek(fd, SEEK_SET, 0) == -1)
    return (my_error(49));
  if (dup2(fd, 0) == -1)
    return (my_error(43));
  if (close(fd) == -1 || remove("/tmp/minishell") == -1)
    return (my_error(50));
  return (0);
}

int		red_close_simple(t_all *all, int i)
{
  int		fd;

  if ((fd = open(all->elem.arg[i + 1],
		 O_WRONLY | O_CREAT | O_TRUNC, 0666)) == -1)
    return (my_error(42));
  if (dup2(fd, 1) == -1)
    return (my_error(43));
  if (close(fd) == -1)
    return (my_error(44));
  return (0);
}

int		red_close_double(t_all *all, int i)
{
  int		fd;

  if ((fd = open(all->elem.arg[i + 1],
		 O_WRONLY | O_CREAT | O_APPEND, 0666)) == -1)
    return (my_error(42));
  if (dup2(fd, 1) == -1)
    return (my_error(43));
  if (close(fd) == -1)
    return (my_error(44));
  return (0);
}
