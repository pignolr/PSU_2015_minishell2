/*
** mini_epur.c for mini_epur in /home/pignol_r/Epitech/rendu/PSU_2015_minishell2
**
** Made by pignol_r
** Login   <pignol_r@epitech.net>
**
** Started on  Sat Apr  2 17:00:07 2016 pignol_r
** Last update Tue Apr 12 16:15:01 2016 pignol_r
*/

#include <stdlib.h>
#include "my.h"

void		my_epurstr(char *str)
{
  int		i;
  int		j;

  i = 0;
  j = 0;
  while (str[i])
    {
      while (str[i] && (str[i] == ' ' || str[i] == '\t'))
	++i;
      if (str[i] && j)
	str[j++] = ' ';
      while (str[i] && str[i] != ' ' && str[i] != '\t')
	{
	  str[j] = str[i];
	  ++i;
	  ++j;
	}
    }
  str[j] = 0;
}

int		mini_epurlen(char *str)
{
  int		i;
  int		len;

  i = 0;
  len = 0;
  while (str[i])
    {
      if (str[i] == ';' || str[i] == '<' || str[i] == '|' || str[i] == '>')
	++len;
      ++i;
    }
  return (i + len * 2);
}

void		mini_epurcpy(char *str, char *new_str, int *i, int *j)
{
  if ((str[*i] == ';' || str[*i] == '|'
       || (str[*i] == '<' && (*j && (str[*j - 1] != '<')))
       || (str[*i] == '>' && (*j && (str[*j - 1] != '>'))))
      && (!*i || str[*i - 1] != '\\'))
    {
      new_str[*j] = ' ';
      *j = *j + 1;
    }
  new_str[*j] = str[*i];
  *j = *j + 1;
  if ((str[*i] == ';' || str[*i] == '|'
       || (str[*i] == '<' && (str[*i + 1] != '<' || (*j && str[*j - 1] == '<')))
       || (str[*i] == '>' && (str[*i + 1] != '>'
			      || (*j && str[*j - 1] == '<'))))
      && (!*i || str[*i - 1] != '\\'))
    {
      new_str[*j] = ' ';
      *j = *j + 1;
    }
  *i = *i + 1;
}

char		*mini_epur(char *str)
{
  char		*new_str;
  int		i;
  int		j;

  if (!(new_str = malloc(sizeof(char) * (mini_epurlen(str) + 1))))
    return (NULL);
  i = 0;
  j = 0;
  while (str[i])
    mini_epurcpy(str, new_str, &i, &j);
  new_str[j] = 0;
  free(str);
  my_epurstr(new_str);
  str = new_str;
  return (new_str);
}
