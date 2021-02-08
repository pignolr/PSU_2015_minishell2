/*
** my_is_prime.c for my_is_prime.c in /home/pignol_r/Epitech/rendu/lib
**
** Made by pignol_r
** Login   <pignol_r@epitech.net>
**
** Started on  Sat Jan  2 16:27:55 2016 pignol_r
** Last update Sat Jan  2 16:28:30 2016 pignol_r
*/

int     find_prime_or_not(int nb, int var)
{
  int   result;
  int   ret;

  var = var + 1;
  result = nb % var;
  if (result != 0)
    ret = find_prime_or_not(nb, var);
  else
    {
      if (var == nb)
	ret = 1;
      else
	ret = 0;
    }
  return (ret);
}

int     my_is_prime(int nb)
{
  int   var;
  int   ret;

  var = 1;
  if (nb < 2)
    return (0);
  ret = find_prime_or_not(nb, var);
  return (ret);
}
