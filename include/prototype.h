/*
** prototype.h for prototypr.h in /home/pignol_r/Epitech/rendu/PSU_2015_tetris
**
** Made by pignol_r
** Login   <pignol_r@epitech.net>
**
** Started on  Sat Mar  5 14:44:28 2016 pignol_r
** Last update Tue Apr 12 15:31:15 2016 pignol_r
*/

#ifndef PROTOTYPE_H_
# define PROTOTYPE_H_

# include "struct.h"

int		is_father2(t_all *all, t_tri tri);
int		red_open_simple(t_all *all, int i);
int		red_open_double(t_all *all, int i);
int		red_close_simple(t_all *all, int i);
int		red_close_double(t_all *all, int i);
int		redirect(t_all *all);
int		str_isredirect(char *str);
void		my_exit(t_all *all);
int		is_father(t_all *all, int father);
int		fd_stand_cpy(t_all *all);
int		fd_stand_restor(t_all *all, int father, int pid);
void		aff_tab(char **tab);
int		new_arg_father(t_all *all, int i);
int		new_arg_son(t_all *all, int i);
int		path_exec_next(t_all *all, int i);
int		get_home(t_all *all);
int		get_user(t_all *all);
int		env_replace(t_all *all, char *env, char *str, int i);
int		buil_exec(t_all *all);
int		buil_exit(t_all *all);
int		buil_cd(t_all *all);
int		buil_env(t_all *all);
int		buil_setenv(t_all *all);
int		buil_unsetenv(t_all *all);
int		tri_exec(t_all *all);
int		get_prompt(t_all *all);
int		get_envstr(char **env, char *str);
char		*mini_epur(char *str);
int		get_path(t_all *all);
int		init_all(t_all *all);
char		**env_init(const char **env);
char		**env_free(char **env);
void		free_tab(char **tab);
void		free_all(t_all *all);
int		my_error(int err);
char		*my_error_null(int err);
void		put_tab_path(char *path, char **tab_path);
void		env_delete(t_all *all, int i);
char		**buil_init();
int		direct_exec(t_all *all);
int		other_exec(t_all *all);

#endif /* !PROTOTYPE_H_ */
