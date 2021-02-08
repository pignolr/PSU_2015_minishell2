/*
** sum_stdarg.c for stdarg in /home/pignol_r/rendu/PSU_2015_my_printf_bootstrap
** 
** Made by remi pignol
** Login   <pignol_r@epitech.net>
** 
** Started on  Wed Nov  4 14:52:47 2015 remi pignol
** Last update Wed Nov  4 16:02:48 2015 remi pignol
*/

#include <stdarg.h>
#include "my.h"

int		sum_stdarg(int i, int nb, ...)
{
  va_list	ap;
  int		value;
  int		count;

  va_start(ap, nb);
  value = 0;
  if (i == 0)
    {
      while (count < nb)
	{
	  value = value + va_arg(ap, int);
	  count++;
	}
    }
  if (i == 1)
    {
      while (count < nb)
        {
	  value = value + my_strlen(va_arg(ap, char *));
	  count++;
	}
    }
  va_end(ap);
  return (value);
}
