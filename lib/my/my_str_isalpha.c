/*
** my_str_isalpha.c for str_isalphe in /home/pignol_r/Epitech/rendu/lib
**
** Made by pignol_r
** Login   <pignol_r@epitech.net>
**
** Started on  Sat Jan  2 16:54:31 2016 pignol_r
** Last update Sun Apr 10 19:12:43 2016 pignol_r
*/

int	my_str_isalpha(char *str)
{
  int	i;

  i = 0;
  while (str[i])
    {
      if ((str[i] < '0' || str[i] > '9')
	  && (str[i] < 'a' || str[i] > 'z')
	  && (str[i] < 'A' || str[i] > 'Z'))
	return (1);
      ++i;
    }
  return (0);
}
