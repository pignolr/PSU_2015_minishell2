/*
** my_find_prime_sup.c for my_find_prime_sup in /home/pignol_r/Epitech/rendu/lib
**
** Made by pignol_r
** Login   <pignol_r@epitech.net>
**
** Started on  Sat Jan  2 16:31:42 2016 pignol_r
** Last update Sat Jan  2 17:06:13 2016 pignol_r
*/

#include "my.h"

int     find_the_prime(int nb, int count)
{
  if (count == 1)
    return (nb);
  else
    {
      if (count > 1)
	{
	  nb = nb + 1;
	  if (nb > 214748367)
	    {
	      my_putstr("Enter a smaller number : int overflow");
	      return (1);
	    }
	  else
	    my_find_prime_sup(nb);
	}
    }
  return (0);
}

int     my_find_prime_sup(int nb)
{
  int   var;
  int   result;
  int   count;
  int   ret;

  var = 2;
  count = 0;
  if (nb < 2)
    return (2);
  while (var <= nb)
    {
      result = nb % var;
      if (result == 0)
	count = count + 1;
      var = var + 1;
    }
  ret = find_the_prime(nb, count);
  return (ret);
}
