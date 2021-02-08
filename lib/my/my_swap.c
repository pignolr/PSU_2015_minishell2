/*
** my_swap.c for swap in /home/pignol_r/Epitech/rendu/lib
**
** Made by pignol_r
** Login   <pignol_r@epitech.net>
**
** Started on  Sat Jan  2 15:31:20 2016 pignol_r
** Last update Sat Jan  2 15:32:57 2016 pignol_r
*/

void	my_swap(int *a, int *b)
{
  int	c;

  c = *a;
  *a = *b;
  *b = c;
}
