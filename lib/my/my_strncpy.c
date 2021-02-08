/*
** my_strncpy.c for strncpy in /home/pignol_r/Epitech/rendu/lib
**
** Made by pignol_r
** Login   <pignol_r@epitech.net>
**
** Started on  Sat Jan  2 16:34:50 2016 pignol_r
** Last update Fri Apr  1 14:58:34 2016 pignol_r
*/

char    *my_strncpy(char *dest, char *src, int n)
{
  int   i;

  i = 0;
  while (src[i] && i < n)
    {
      dest[i] = src[i];
      ++i;
    }
  while (i < n)
    {
      dest[i] = 0;
      ++i;
    }
  dest[n] = 0;
  return (dest);
}
