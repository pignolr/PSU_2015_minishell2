/*
** my_printf.c for printf in /home/pignol_r/rendu/PSU_2015_my_printf
**
** Made by remi pignol
** Login   <pignol_r@epitech.net>
**
** Started on  Fri Nov  6 13:21:55 2015 remi pignol
** Last update Thu Mar 10 15:45:59 2016 pignol_r
*/

#include <stdlib.h>
#include <stdarg.h>
#include <errno.h>
#include "print.h"
#include "proto_print.h"

t_ptrf		g_tabptr[] =
  {
    {flag_c_, 'c'},
    {flag_d_, 'd'},
    {flag_d_, 'i'},
    {flag_o_, 'o'},
    {flag_u_, 'u'},
    {flag_x_, 'x'},
    {flag_X_, 'X'},
    {flag_p_, 'p'},
    {flag_s_, 's'},
    {flag_S_, 'S'},
    {flag_b_, 'b'},
    {NULL, 0},
  };

int		flag(va_list ap, char *s, int i, t_count *count)
{
  int		j;

  i++;
  j = 0;
  while (s[i] == ' ' && s[i] != 0)
    i++;
  while (g_tabptr[j].flag != s[i] && g_tabptr[j].flag != 0)
    j++;
  if (g_tabptr[j].flag == s[i])
    g_tabptr[j].ptr(ap, count);
  else
    {
      my_putchar('%');
      if (s[i] != '%')
	count->count_put--;
    }
  return (i);
}

int 		my_printf(char *s, ...)
{
  va_list	ap;
  int		i;
  t_count	count;

  va_start(ap, *s);
  count.count_put = 0;
  i = 0;
  while (s[i] != 0)
    {
      if (s[i] != '%')
	my_putchar(s[i]);
      else
	i = flag(ap, s, i, &count);
      i++;
    }
  va_end(ap);
  count.count_put += i;
  return (count.count_put);
}
