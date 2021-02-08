/*
** struct.h for rip in /home/huyghu_v/Docu/Allum1
**
** Made by Victor Huyghues-Lacour
** Login   <huyghu_v@epitech.net>
**
** Started on  Tue Feb  9 10:27:25 2016 Victor Huyghues-Lacour
** Last update Tue Apr 12 16:42:18 2016 pignol_r
*/

#ifndef STRUCT_H_
# define STRUCT_H_

# include "macro.h"

typedef struct	s_tri
{
  int		i;
  int		father;
  int		pid;
  int		pipefd[2];
}		t_tri;

typedef struct	s_elem
{
  int		fd[2];
  char		**env;
  char		**arg;
  char		**path;
  char		*str;
  char		*prompt;
  char		*home;
  char		*user;
  char		*pwd;
  char		*oldpwd;
  char		red[4];
}		t_elem;

typedef struct	s_free
{
  int		fd[2];
  char		**f_tab[N_TAB];
  char		*f_str[N_STR];
}		t_free;

typedef union	u_all
{
  t_elem	elem;
  t_free	free;
}		t_all;

typedef struct	s_prompt
{
  char		*host;
  char		*home;
  char		*pwd;
  int		len_i;
  int		len_j;
  int		len_k;
}		t_prompt;

#endif /* !STRUCT_H_ */
