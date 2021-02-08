/*
** my_strupcase.c for my_strupcase in /home/pignol_r/Epitech/rendu/lib
**
** Made by pignol_r
** Login   <pignol_r@epitech.net>
**
** Started on  Sat Jan  2 16:47:44 2016 pignol_r
** Last update Sat Jan  2 16:51:25 2016 pignol_r
*/

char    *my_strupcase(char *str)
{
  int   c;

  c = 0;
  while (str[c] != '\0')
    {
      if (str[c] > 96 && str[c] < 123)
	{
	  str[c] = str[c] - 32;
	  c = c + 1;
	}
      else
	c = c + 1;
    }
  return (str);
}
