/*
** tabptr.h for tabptr in /home/pignol_r/Epitech/rendu/PSU_2015_tetris
**
** Made by pignol_r
** Login   <pignol_r@epitech.net>
**
** Started on  Tue Mar 15 15:22:37 2016 pignol_r
** Last update Sun Apr 10 17:05:19 2016 pignol_r
*/

#ifndef TABPTR_H_
# define TABPTR_H_

# include "prototype.h"

typedef struct	s_ptr_redirect
{
  char		*flag;
  int		(*ptr)(t_all *all, int i);
}		t_ptr_redirect;

static const t_ptr_redirect g_ptr_redirect[] =
  {
    {">", red_close_simple},
    {">>", red_close_double},
    {"<", red_open_simple},
    {"<<", red_open_double},
    {NULL, NULL}
  };

typedef struct	s_ptr_buil
{
  char		*flag;
  int		(*ptr)(t_all *all);
}		t_ptr_buil;

static const t_ptr_buil	g_ptr_buil[] =
  {
    {EXIT, buil_exit},
    {CD, buil_cd},
    {ENV, buil_env},
    {SETENV, buil_setenv},
    {UNSETENV, buil_unsetenv},
    {NULL, NULL}
  };

#endif /* !TABPTR_H_ */
