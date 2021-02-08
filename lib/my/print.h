/*
** print.h for print in /home/pignol_r/rendu/PSU_2015_my_printf
**
** Made by remi pignol
** Login   <pignol_r@epitech.net>
**
** Started on  Fri Nov  6 17:55:08 2015 remi pignol
** Last update Fri Feb  5 14:37:16 2016 pignol_r
*/

#ifndef PRINT_H_
# define PRINT_H_

typedef struct	s_count
{
  int		count_put;
}		t_count;

typedef struct	s_ptrf
{
  void		(*ptr)(va_list ap, t_count *count);
  char		flag;
}		t_ptrf;

#endif /* !PRINT_H_ */
