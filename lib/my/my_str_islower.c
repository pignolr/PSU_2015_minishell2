/*
** my_str_islower.c for islower in /home/pignol_r/Epitech/rendu/lib
**
** Made by pignol_r
** Login   <pignol_r@epitech.net>
**
** Started on  Sat Jan  2 16:56:22 2016 pignol_r
** Last update Sat Jan  2 16:56:36 2016 pignol_r
*/

int     my_str_islower(char *str)
{
  int   c;

  c = 0;
  while (str[c] != '\0')
    {
      if (str[c] < 97 && str[c] > 122)
	return (0);
      c = c + 1;
    }
  return (1);
}
