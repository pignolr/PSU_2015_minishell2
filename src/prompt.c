/*
** prompt.c for prompt in /home/pignol_r/Epitech/rendu/PSU_2015_minishell2/src
**
** Made by pignol_r
** Login   <pignol_r@epitech.net>
**
** Started on  Sat Apr  2 19:23:46 2016 pignol_r
** Last update Thu Apr  7 14:21:34 2016 pignol_r
*/

#include <stdlib.h>
#include "my.h"
#include "prototype.h"

void		env_strcpy(char *dest, char *env)
{
  int		i;
  int		j;

  i = 0;
  j = 0;
  while (env[i] && env[i] != '=')
    ++i;
  ++i;
  while (env[i])
    {
      dest[j] = env[i];
      ++i;
      ++j;
    }
  dest[j] = 0;
}

void		prompt_cpy(t_all *all, t_prompt *prompt)
{
  int		i;
  int		j;

  my_strcat(all->elem.prompt, "[");
  my_strcat(all->elem.prompt, prompt->host);
  my_strcat(all->elem.prompt, "]:");
  if (my_strncmp(prompt->home, prompt->pwd, prompt->len_j - 1))
    my_strcat(all->elem.prompt, prompt->pwd);
  else
    {
      my_strcat(all->elem.prompt, "~");
      i = prompt->len_j - 1;
      j = my_strlen(all->elem.prompt);
      while (prompt->pwd[i])
	{
	  all->elem.prompt[j] = prompt->pwd[i];
	  ++i;
	  ++j;
	}
      all->elem.prompt[j] = 0;
    }
  my_strcat(all->elem.prompt, "$> ");
}

int		set_prompt(t_all *all, t_prompt *prompt)
{
  int		size;

  size = prompt->len_i + prompt->len_j + prompt->len_k + 7;
  free(all->elem.prompt);
  all->elem.prompt = NULL;
  if (!(all->elem.prompt = malloc(sizeof(char) * size)))
    return (1);
  all->elem.prompt[0] = 0;
  prompt_cpy(all, prompt);
  return (0);
}

int		get_prompt(t_all *all)
{
  t_prompt	prompt;

  prompt.host = all->elem.user;
  prompt.home = all->elem.home;
  prompt.pwd = all->elem.pwd;
  prompt.len_i = my_strlen(prompt.host) + 1;
  prompt.len_j = my_strlen(prompt.home) + 1;
  prompt.len_k = my_strlen(prompt.pwd) + 1;
  if (set_prompt(all, &prompt))
    return (my_error(3));
  return (0);
}
