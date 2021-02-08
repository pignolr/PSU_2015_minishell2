/*
** my_hexa.c for hexadecimal in /home/pignol_r/rendu/PSU_2015_my_printf/lib/my
**
** Made by remi pignol
** Login   <pignol_r@epitech.net>
**
** Started on  Sat Nov  7 14:12:51 2015 remi pignol
** Last update Mon Jan 18 10:51:27 2016 pignol_r
*/

#include <stdarg.h>
#include "print.h"
#include "proto_print.h"
#include "my.h"

void		dec_hexa_min(unsigned int hexa, t_count *count)
{
  char		hexadecimal[16];
  char		str[9];
  int		retenu;
  int		i;

  i = 0;
  my_strcpy(hexadecimal, "0123456789abcdef");
  while (hexa > 0)
    {
      retenu = hexa % 16;
      hexa /= 16;
      str[i] = hexadecimal[retenu];
      i++;
      count->count_put++;
    }
  str[i] = 0;
  my_revstr(str);
  my_putstr(str);
}

void            dec_hexa_maj(unsigned int hexa, t_count *count)
{
  char          hexadecimal[16];
  char          str[9];
  int           retenu;
  int           i;

  i = 0;
  my_strcpy(hexadecimal, "0123456789ABCDEF");
  while (hexa > 0)
    {
      retenu = hexa % 16;
      hexa /= 16;
      str[i] = hexadecimal[retenu];
      i++;
      count->count_put++;
    }
  str[i] = 0;
  my_revstr(str);
  my_putstr(str);
}

void            dec_oct(unsigned int decimal, t_count *count)
{
  char          octal[8];
  char          str[12];
  int           retenu;
  int           i;

  i = 0;
  my_strcpy(octal, "01234567");
  while (decimal > 0)
    {
      retenu = decimal % 8;
      decimal /= 8;
      str[i] = octal[retenu];
      i++;
      count->count_put++;
    }
  str[i] = 0;
  my_revstr(str);
  my_putstr(str);
}

void            dec_bin(unsigned int decimal, t_count *count)
{
  char          bin[2];
  char          str[32];
  int           retenu;
  int           i;

  i = 0;
  my_strcpy(bin, "01");
  while (decimal > 0)
    {
      retenu = decimal % 2;
      decimal /= 2;
      str[i] = bin[retenu];
      i++;
      count->count_put++;
    }
  str[i] = 0;
  my_revstr(str);
  my_putstr(str);
}

void            adr_ptr(unsigned long ptr, t_count *count)
{
  char          hexadecimal[16];
  char          str[13];
  int           retenu;
  int           i;

  i = 0;
  my_strcpy(hexadecimal, "0123456789abcdef");
  my_putstr("0x");
  while (ptr > 0)
    {
      retenu = ptr % 16;
      ptr /= 16;
      str[i] = hexadecimal[retenu];
      i++;
      count->count_put++;
    }
  str[i] = 0;
  my_revstr(str);
  my_putstr(str);
}
