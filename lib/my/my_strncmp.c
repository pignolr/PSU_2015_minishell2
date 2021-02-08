/*
** my_strncmp.c for strncmp in /home/pignol_r/Epitech/rendu/lib
**
** Made by pignol_r
** Login   <pignol_r@epitech.net>
**
** Started on  Sat Jan  2 16:46:10 2016 pignol_r
** Last update Tue Apr  5 21:50:06 2016 pignol_r
*/

int	my_strncmp(char *s1, char *s2, int n)
{
  int	i;

  i = 0;
  if (!s1 || !s2 || n < 0)
    return (1);
  while (i < n && s1[i] && s2[i])
    {
      if (s1[i] != s2[i])
	return (1);
      i++;
    }
  if (i < n && (s1[i] || s2[i]))
    return (1);
  return (0);
}
