/*
** my_flag.c for flag in /home/pignol_r/rendu/PSU_2015_my_printf
**
** Made by remi pignol
** Login   <pignol_r@epitech.net>
**
** Started on  Fri Nov  6 18:31:46 2015 remi pignol
** Last update Mon Jan 18 10:45:49 2016 pignol_r
*/

#include <stdarg.h>
#include <stdlib.h>
#include "print.h"
#include "proto_print.h"
#include "my.h"

void		flag_c_(va_list ap, t_count *count)
{
  my_putchar(va_arg(ap, int));
  count->count_put--;
}

void		flag_d_(va_list ap, t_count *count)
{
  int		nb;

  nb = va_arg(ap, int);
  my_put_nbr(nb);
  count->count_put -= 2;
  while (nb != 0)
    {
      nb /= 10;
      count->count_put++;
    }
}

void		flag_s_(va_list ap, t_count *count)
{
  char		*str;

  str = va_arg(ap, char *);
  if (str == NULL)
    {
      my_putstr("(null)");
      count->count_put += 4;
    }
  else
    {
      my_putstr(str);
      count->count_put -= 2;
      count->count_put += my_strlen(str);
    }
}

void            flag_u_(va_list ap, t_count *count)
{
  unsigned int  nb;

  nb = va_arg(ap, unsigned int);
  my_put_unsnbr(nb);
  count->count_put -= 2;
  while (nb != 0)
    {
      nb /= 10;
      count->count_put++;
    }
}

void		flag_S_(va_list ap, t_count *count)
{
  char          *str;

  str = va_arg(ap, char *);
  if (str == NULL)
    {
      my_putstr("(null)");
      count->count_put += 4;
    }
  else
    {
      my_put_print(str, count);
      count->count_put -= 2;
      count->count_put += my_strlen(str);
    }
}
