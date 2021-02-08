/*
** my_flag2.c for flag2 in /home/pignol_r/rendu/PSU_2015_my_printf
** 
** Made by remi pignol
** Login   <pignol_r@epitech.net>
** 
** Started on  Sat Nov  7 13:15:23 2015 remi pignol
** Last update Mon Nov 16 13:31:30 2015 remi pignol
*/

#include <stdarg.h>
#include <stdlib.h>
#include "print.h"
#include "proto_print.h"
#include "my.h"

void            flag_o_(va_list ap, t_count *count)
{
  int           nb;

  nb = va_arg(ap, int);
  dec_oct(nb, count);
  count->count_put -= 2;
}

void            flag_x_(va_list ap, t_count *count)
{
  int           nb;

  nb = va_arg(ap, unsigned int);
  dec_hexa_min(nb, count);
  count->count_put -= 2;
}

void            flag_X_(va_list ap, t_count *count)
{
  int           nb;

  nb = va_arg(ap, unsigned int);
  dec_hexa_maj(nb, count);
  count->count_put -= 2;
}

void            flag_p_(va_list ap, t_count *count)
{
  unsigned long nb;

  nb = va_arg(ap, unsigned long);
  if (nb == 0)
    {
      my_putstr("(nil)");
      count->count_put += 3;
    }
  else
    adr_ptr(nb, count);
}

void            flag_b_(va_list ap, t_count *count)
{
  int           nb;

  nb = va_arg(ap, int);
  dec_bin(nb, count);
  count->count_put -= 2;
}
