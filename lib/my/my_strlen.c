/*
** my_strlen.c for my_strlen in /home/pignol_r/Epitech/rendu/PSU_2015_minishell1
**
** Made by pignol_r
** Login   <pignol_r@epitech.net>
**
** Started on  Sat Jan 23 16:15:24 2016 pignol_r
** Last update Fri Apr  1 18:14:24 2016 pignol_r
*/

int	my_strlen(const char *str)
{
  int	i;

  i = 0;
  if (!str)
    return (0);
  while (str[i])
    ++i;
  return (i);
}

int	my_tablen(const char **tab)
{
  int	i;

  i = 0;
  if (!tab)
    return (0);
  while (tab[i])
    ++i;
  return (i);
}
