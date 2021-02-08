/*
** error.c for error in /home/pignol_r/Epitech/rendu/PSU_2015_minishell2
**
** Made by pignol_r
** Login   <pignol_r@epitech.net>
**
** Started on  Wed Apr  6 17:47:21 2016 pignol_r
** Last update Wed Apr 13 12:58:11 2016 pignol_r
*/

#include <stdlib.h>
#include <unistd.h>
#include "my.h"
#include "prototype.h"

void		err_init3(char **message)
{
  message[47] = ERR_47;
  message[48] = ERR_48;
  message[49] = ERR_49;
  message[50] = ERR_50;
  message[51] = ERR_51;
}

void		err_init2(char **message)
{
  message[24] = ERR_24;
  message[25] = ERR_25;
  message[26] = ERR_26;
  message[27] = ERR_27;
  message[28] = ERR_28;
  message[29] = ERR_29;
  message[30] = ERR_30;
  message[31] = ERR_31;
  message[32] = ERR_32;
  message[33] = ERR_33;
  message[34] = ERR_34;
  message[35] = ERR_35;
  message[36] = ERR_36;
  message[37] = ERR_37;
  message[38] = ERR_38;
  message[39] = ERR_39;
  message[40] = ERR_40;
  message[40] = ERR_40;
  message[41] = ERR_41;
  message[42] = ERR_42;
  message[43] = ERR_43;
  message[44] = ERR_44;
  message[45] = ERR_45;
  message[46] = ERR_46;
  err_init3(message);
}

void		err_init(char **message)
{
  message[0] = ERR_00;
  message[1] = ERR_01;
  message[2] = ERR_02;
  message[3] = ERR_03;
  message[4] = ERR_04;
  message[5] = ERR_05;
  message[6] = ERR_06;
  message[7] = ERR_07;
  message[8] = ERR_08;
  message[9] = ERR_09;
  message[10] = ERR_10;
  message[11] = ERR_11;
  message[12] = ERR_12;
  message[13] = ERR_13;
  message[14] = ERR_14;
  message[15] = ERR_15;
  message[16] = ERR_16;
  message[17] = ERR_17;
  message[18] = ERR_18;
  message[19] = ERR_19;
  message[20] = ERR_20;
  message[21] = ERR_21;
  message[22] = ERR_22;
  message[23] = ERR_23;
  err_init2(message);
}

int		my_error(int err)
{
  char		*message[N_ERR];

  err_init(message);
  write(2, "\033[1;31mError \033[0;31m",
	my_strlen("\033[1;31mError \033[0;31m"));
  if (err < N_ERR)
    write(2, message[err], my_strlen(message[err]));
  write(2, "\n\033[0;00m", my_strlen("\n\033[0;00m"));
  return (1);
}

char		*my_error_null(int err)
{
  char		*message[N_ERR];

  err_init(message);
  write(2, "\033[1;31mError \033[0;31m",
	my_strlen("\033[1;31mError \033[0;31m"));
  if (err <= N_ERR)
    write(2, message[N_ERR], my_strlen(message[N_ERR]));
  write(2, "\n\033[0;00m", my_strlen("\n\033[0;00m"));
  return (NULL);
}
