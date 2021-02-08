/*
** env.c for env in /home/pignol_r/Epitech/rendu/PSU_2015_minishell2
**
** Made by pignol_r
** Login   <pignol_r@epitech.net>
**
** Started on  Thu Mar 31 18:11:38 2016 pignol_r
** Last update Wed Apr  6 18:07:29 2016 pignol_r
*/

#include <stdlib.h>
#include "my.h"
#include "prototype.h"

char		**env_free(char **env)
{
  int		i;

  i = 0;
  if (env)
    while (env[i])
      {
	free(env[i]);
	++i;
      }
  free(env);
  return (NULL);
}

char		*env_cpy(const char *old_env)
{
  char		*new_env;
  int		i;

  if (!(new_env = malloc(sizeof(char) * (my_strlen(old_env) + 1))))
    return (NULL);
  i = 0;
  while (old_env[i])
    {
      new_env[i] = old_env[i];
      ++i;
    }
  new_env[i] = 0;
  return (new_env);
}

char		**env_init(const char **old_env)
{
  char		**new_env;
  int		i;

  if (!(new_env = malloc(sizeof(char *) * (my_tablen(old_env) + 1))))
    return (NULL);
  i = 0;
  while (old_env[i])
    {
      if (!(new_env[i] = env_cpy(old_env[i])))
	return (env_free(new_env));
      ++i;
    }
  new_env[i] = NULL;
  return (new_env);
}
