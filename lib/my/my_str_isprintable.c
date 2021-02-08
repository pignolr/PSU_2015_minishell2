/*
** my_str_isprintable.c for isprintable in /home/pignol_r/Epitech/rendu/lib
**
** Made by pignol_r
** Login   <pignol_r@epitech.net>
**
** Started on  Sat Jan  2 16:59:07 2016 pignol_r
** Last update Sat Jan  2 16:59:24 2016 pignol_r
*/

int     my_str_isprintable(char *str)
{
  int   c;

  c = 0;
  while (str[c] != '\0')
    {
      if (str[c] < 32)
	return (0);
      c = c + 1;
    }
  return (1);
}
