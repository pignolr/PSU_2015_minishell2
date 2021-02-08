/*
** macro.h for macro.h in /home/pignol_r/Epitech/rendu/PSU_2015_tetris
**
** Made by pignol_r
** Login   <pignol_r@epitech.net>
**
** Started on  Sat Mar  5 18:03:42 2016 pignol_r
** Last update Wed Apr 13 15:14:36 2016 remi pignol
*/

#ifndef MACRO_H_
# define MACRO_H_

# define EXIT "exit"
# define CD "cd"
# define ENV "env"
# define SETENV "setenv"
# define UNSETENV "unsetenv"
# define N_TAB 3
# define N_STR 6
# define N_ERR 52
# define ERR_EXEC "\033[1;31mError :\033[0;31m exec fail\033[0;00m\n"
# define ERR_00 "fail with malloc"
# define ERR_01 "fail with malloc of newpath"
# define ERR_02 "fail with malloc of epuration"
# define ERR_03 "fail with malloc of prompt"
# define ERR_04 "fail with malloc of tab arg"
# define ERR_05 "fail with fork of direct_exec"
# define ERR_06 "fail with wait of direct_exec"
# define ERR_07 "fail with opendir of other_exec"
# define ERR_08 "fail with closedir of other_exec"
# define ERR_09 "home not found"
# define ERR_10 "too many arguments `cd path`"
# define ERR_11 "folder not found"
# define ERR_12 "fail with malloc of env_replace"
# define ERR_13 "fail with malloc of home"
# define ERR_14 "fail with closedir of path_exec"
# define ERR_15 "fail with fork of path_exec"
# define ERR_16 "fail with wait of path_exec"
# define ERR_17 "fail with malloc of path_exec"
# define ERR_18 "fail with execve of path_exec"
# define ERR_19 "not enought arguments `setenv arg1 arg2`"
# define ERR_20 "Variable name must contain alphanumeric characters."
# define ERR_21 "fail with malloc new_tab of env_add"
# define ERR_22 "fail with malloc new_env of env_add"
# define ERR_23 "not enought arguments `unsetenv arg`"
# define ERR_24 "fail with malloc env of env_delete"
# define ERR_25 "fail with realloc pwd"
# define ERR_26 "fail with fork of pipe"
# define ERR_27 "fail with close of pipe"
# define ERR_28 "fail with dup2 of pipe"
# define ERR_29 "fail with pipe"
# define ERR_30 "fail with wait of tri_exec"
# define ERR_31 "Invalide command"
# define ERR_32 "fail with malloc of new_arg_son"
# define ERR_33 "fail with malloc of new_arg_father"
# define ERR_34 "fail with fork"
# define ERR_35 "fail with copy of standart fd"
# define ERR_36 "fail with close pipe"
# define ERR_37 "fail with dup2 standart fd"
# define ERR_38 "fail with wait of pipe"
# define ERR_39 "exit: expression syntax"
# define ERR_40 "Ambiguous redirect."
# define ERR_41 "Missing name for redirect."
# define ERR_42 "fail open new file for redirection"
# define ERR_43 "fail dup2 for redirection"
# define ERR_44 "fail close redirection"
# define ERR_45 "Access denied"
# define ERR_46 "fail open file of redirection "
# define ERR_47 "fail open file tmp"
# define ERR_48 "fail with write on tmp file"
# define ERR_49 "fail with lseek"
# define ERR_50 "fail with close tmp file"
# define ERR_51 "too many arguments `setenv arg1 arg2`"

#endif /* !MACRO_H_ */
