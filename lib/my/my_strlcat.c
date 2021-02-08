/*
** my_strlcat.c for strlcat in /home/pignol_r/Epitech/rendu/lib
**
** Made by pignol_r
** Login   <pignol_r@epitech.net>
**
** Started on  Sat Jan  2 17:03:46 2016 pignol_r
** Last update Sat Jan  2 17:04:00 2016 pignol_r
*/

int     strlcat(char *dest, char *src, int size)
{
  int   c;
  int   d;

  c = 0;
  d = 0;
  while (dest[c] != '\0')
    c = c + 1;
  while (src[d] != '\0' && d < size)
    {
      dest[c] = src[d];
      c = c + 1;
      d = d + 1;
    }
  c = 0;
  while (dest[c] != '\0')
    c = c + 1;
  return (c);
}
