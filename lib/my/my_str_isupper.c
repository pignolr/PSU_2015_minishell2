/*
** my_str_isupper.c for isupper in /home/pignol_r/Epitech/rendu/lib
**
** Made by pignol_r
** Login   <pignol_r@epitech.net>
**
** Started on  Sat Jan  2 16:57:15 2016 pignol_r
** Last update Sat Jan  2 16:57:30 2016 pignol_r
*/

int     my_str_isupper(char *str)
{
  int   c;

  c = 0;
  while (str[c] != '\0')
    {
      if (str[c] < 65 && str[c] > 90)
	return (0);
      c = c + 1;
    }
  return (1);
}
