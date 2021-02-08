/*
** disp_stdarg.c for stdarg in /home/pignol_r/rendu/PSU_2015_my_printf_bootstrap
** 
** Made by remi pignol
** Login   <pignol_r@epitech.net>
** 
** Started on  Wed Nov  4 15:32:23 2015 remi pignol
** Last update Wed Nov  4 16:44:58 2015 remi pignol
*/

#include <stdarg.h>
#include "my.h"

int		disp_stdarg(char *s, ...)
{
  va_list	ap;
  int		i;

  va_start(ap, *s);
  i = 0;
  while (i < my_strlen(s))
    {
      if (s[i] == 'c')
	my_putchar(va_arg(ap, int));
      else if (s[i] == 's')
	my_putstr(va_arg(ap, char *));
      else if (s[i] == 'i')
	my_put_nbr(va_arg(ap, int));
      my_putchar('\n');
      i++;
    }
  va_end(ap);
  return (0);
}
