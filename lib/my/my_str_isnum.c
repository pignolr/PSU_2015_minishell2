/*
** my_str_isnum.c for isnum in /home/pignol_r/Epitech/rendu/lib
**
** Made by pignol_r
** Login   <pignol_r@epitech.net>
**
** Started on  Sat Jan  2 16:55:50 2016 pignol_r
** Last update Sat Apr  9 18:58:27 2016 pignol_r
*/

int	my_str_isnum(char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    {
      if (str[i] < '0' || str[i] > '9')
	return (1);
      ++i;
    }
  return (0);
}
