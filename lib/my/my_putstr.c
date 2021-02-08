/*
** my_putstr.c for my_putstr in /home/pignol_r/Epitech/rendu/lib
**
** Made by pignol_r
** Login   <pignol_r@epitech.net>
**
** Started on  Sat Jan  2 15:01:51 2016 pignol_r
** Last update Sat Jan  2 15:08:38 2016 pignol_r
*/

#include <unistd.h>
#include "my.h"

void	my_putstr(char *str)
{
  write(1, str, my_strlen(str));
}
