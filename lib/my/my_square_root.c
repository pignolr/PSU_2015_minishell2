/*
** my_square_root.c for square_root in /home/pignol_r/Epitech/rendu/lib
**
** Made by pignol_r
** Login   <pignol_r@epitech.net>
**
** Started on  Sat Jan  2 16:22:48 2016 pignol_r
** Last update Sat Jan  2 16:25:46 2016 pignol_r
*/

int     my_square_root(int nb)
{
  int   result;

  result = 1;
  if (nb <= 0)
    return (0);
  while (nb != result * result)
    {
      result = result + 1;
      if (nb < result * result)
	return (0);
    }
  return (result);
}
