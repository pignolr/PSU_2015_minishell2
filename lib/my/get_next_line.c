/*
** get_next_line.c for get_next_line in /home/pignol_r/Epitech/rendu/CPE_2015_getnextline
**
** Made by pignol_r
** Login   <pignol_r@epitech.net>
**
** Started on  Tue Jan  5 15:44:13 2016 pignol_r
** Last update Sun Apr 10 18:50:42 2016 pignol_r
*/

#include <stdlib.h>
#include <unistd.h>
#include "get_next_line.h"
#include "my.h"

char		*line_end(char *line)
{
  free(line);
  return (NULL);
}

char		*get_line(char *buff, char *line, int *i, int *j)
{
  if (*i == 0 && *j != 0 &&
      !(line = my_realloc(line, sizeof(char) * (*j + READ_SIZE + 2))))
    return (line_end(line));
  line[*j] = buff[*i];
  *j = *j + 1;
  *i = *i + 1;
  line[*j] = 0;
  return (line);
}

int		read_file(const int fd, char *buff, int *i)
{
  int		file;
  int		n;

  n = 0;
  while (n != (READ_SIZE + 1))
    {
      buff[n] = 0;
      n++;
    }
  if ((file = read(fd, buff, READ_SIZE)) == -1)
    return (-1);
  if (file == 0)
    return (1);
  *i = 0;
  return (0);
}

char		*next_line(const int fd, char *buff, int *i, int j)
{
  char		*line;

  if (fd == 0 && *i != 0 && buff[*i] == 0 && *i != READ_SIZE + 2)
    *i = 0;
  if ((*i == 0 && (read_file(fd, buff, i) == -1)) || *i == (READ_SIZE + 2))
    return (NULL);
  if (!(line = malloc(sizeof(char) * (READ_SIZE + 1))))
    return (NULL);
  line[0] = 0;
  while (*i != READ_SIZE + 2 && buff[*i] != '\n')
    {
      if (!(line = (get_line(buff, line, i, &j))))
	return (NULL);
      if (buff[0] == 0)
	*i = READ_SIZE + 2;
      if (*i != (READ_SIZE + 2) && !buff[*i] && (read_file(fd, buff, i) == -1))
	return (line_end(line));
    }
  if (*i != READ_SIZE + 2)
    *i = (*i + 1) % READ_SIZE;
  if (line[0] == 0 && *i == (READ_SIZE + 2))
    return (line_end(line));
  return (line);
}

char		*get_next_line(const int fd)
{
  static t_fd	*first = NULL;
  t_fd		*elem;

  if (!first && !(first = init_list_line(fd)))
    return (NULL);
  elem = first;
  if (fd < 0)
    {
      first = NULL;
      return (free_list_line(elem));
    }
  while (elem->next && elem->fd != fd)
    elem = elem->next;
  if (elem->fd != fd)
    {
      if (!(elem->next = malloc(sizeof(t_fd))))
	return (NULL);
      elem->next->next = NULL;
      elem->next->fd = fd;
      elem->next->i = 0;
      elem = elem->next;
    }
  elem->j = 0;
  return (next_line(fd, elem->buff, &elem->i, elem->j));
}
