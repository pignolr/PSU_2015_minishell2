/*
** my_power_rec.c for power in /home/pignol_r/Epitech/rendu/lib
**
** Made by pignol_r
** Login   <pignol_r@epitech.net>
**
** Started on  Sat Jan  2 15:54:03 2016 pignol_r
** Last update Sat Jan  2 16:06:12 2016 pignol_r
*/

int     recurse(int nb, int power, int result)
{
  int   ret;

  if (power == 1)
    return (result);
  power = power - 1;
  result = result * nb;
  if (result > 214748367 || result < -214748368)
    ret = 0;
  else
    ret = recurse(nb, power, result);
  return (ret);
}

int     my_power_rec(int nb, int power)
{
  int   result;
  int   ret;

  result = nb;
  if (nb == 0 || power < 0)
    ret = 0;
  if (power == 0)
    ret = 1;
  else
    ret = recurse(nb, power, result);
  return (ret);
}
