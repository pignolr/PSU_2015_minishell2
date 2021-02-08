/*
** proto_print.h for prototype_print in /home/pignol_r/rendu/PSU_2015_my_printf/lib/my
**
** Made by remi pignol
** Login   <pignol_r@epitech.net>
**
** Started on  Thu Nov 12 11:43:46 2015 remi pignol
** Last update Mon Jan 18 10:53:23 2016 pignol_r
*/

#ifndef PROTO_PRINT_H_
# define PROTO_PRINT_H_

void            flag_c_(va_list ap, t_count *count);
void            flag_d_(va_list ap, t_count *count);
void            flag_o_(va_list ap, t_count *count);
void            flag_u_(va_list ap, t_count *count);
void            flag_x_(va_list ap, t_count *count);
void            flag_X_(va_list ap, t_count *count);
void            flag_p_(va_list ap, t_count *count);
void            flag_s_(va_list ap, t_count *count);
void            flag_S_(va_list ap, t_count *count);
void            flag_b_(va_list ap, t_count *count);
void            dec_hexa_min(unsigned int hexa, t_count *count);
void            dec_hexa_maj(unsigned int hexa, t_count *count);
void            dec_oct(unsigned int decimal, t_count *count);
void            dec_bin(unsigned int decimal, t_count *count);
void            adr_ptr(unsigned long ptr, t_count *count);
void            my_put_print(char *str, t_count *count);
void            my_putchar(char c);

#endif /* !PROTO_PRINT_H_ */
