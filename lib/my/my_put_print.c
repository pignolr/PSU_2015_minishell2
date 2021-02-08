/*
** my_put_print.c for print in /home/pignol_r/rendu/PSU_2015_my_printf
** 
** Made by remi pignol
** Login   <pignol_r@epitech.net>
** 
** Started on  Sat Nov  7 16:07:32 2015 remi pignol
** Last update Thu Nov 12 11:56:59 2015 remi pignol
*/

#include <stdarg.h>
#include "print.h"
#include "proto_print.h"
#include "my.h"

char		check_print(char c)
{
  if (c < 32 || c == 127)
    return (1);
  else
    return (0);
}

void            put_oct(char decimal)
{
  char          octal[] = "01234567";
  char          str[3];
  int           retenu;
  int           i;

  i = 0;
  while (decimal > 0)
    {
      retenu = decimal % 8;
      decimal /= 8;
      str[i] = octal[retenu];
      i++;
    }
  str[i] = 0;
  my_revstr(str);
  my_putstr(str);
}

void		my_put_print(char *str, t_count *count)
{
  int		i;

  i = 0;
  while (str[i] != '\0')
    {
      if (check_print(str[i]) == 0)
	my_putchar(str[i]);
      else
	{
	  if (str[i] >= 127)
	    my_putstr("\\177");
	  else if (str[i] < 8)
	    {
	      my_putstr("\\00");
	      put_oct(str[i]);
	    }
	  else
	    {
	      my_putstr("\\0");
              put_oct(str[i]);
	    }
	  count->count_put += 3;
	}
      i = i + 1;
    }
}
