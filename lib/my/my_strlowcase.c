/*
** my_strlowcase.c for strlowcase in /home/pignol_r/Epitech/rendu/lib
**
** Made by pignol_r
** Login   <pignol_r@epitech.net>
**
** Started on  Sat Jan  2 16:52:01 2016 pignol_r
** Last update Sat Jan  2 16:52:19 2016 pignol_r
*/

char    *my_strlowcase(char *str)
{
  int   c;

  c = 0;
  while (str[c] != '\0')
    {
      if (str[c] > 64 && str[c] < 91)
	{
	  str[c] = str[c] - 32;
	  c = c + 1;
	}
      else
	c = c + 1;
    }
  return (str);
}
