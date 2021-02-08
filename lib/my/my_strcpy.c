/*
** my_strcpy.c for strcpy in /home/pignol_r/Epitech/rendu/lib
**
** Made by pignol_r
** Login   <pignol_r@epitech.net>
**
** Started on  Sat Jan  2 16:32:51 2016 pignol_r
** Last update Fri Apr  1 18:13:42 2016 pignol_r
*/

void	my_strcpy(char *dest, char *src)
{
  int	i;

  i = 0;
  while (src[i])
    {
      dest[i] = src[i];
      ++i;
    }
  dest[i] = 0;
}
