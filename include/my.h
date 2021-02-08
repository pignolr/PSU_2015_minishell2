/*
** my.h for my in /home/noguei_b/rendu/Piscine_C_J09/include
**
** Made by Anthony Nogueira
** Login   <noguei_b@epitech.net>
**
** Started on  Thu Oct  8 18:32:22 2015 Anthony Nogueira
** Last update Sat Apr  2 14:08:24 2016 pignol_r
*/

#ifndef MY_H_
# define MY_H_

void	my_putchar(char c);
char	*my_realloc(char *old_ptr, int size);
int	my_isneg(int nb);
void	my_put_nbr(int nb);
void	my_swap(int *a, int *b);
void	my_putstr(char *str);
int	my_strlen(const char *str);
int	my_tablen(const char **tab);
int	my_getnbr(char *str);
int	my_power_rec(int nb, int power);
int	my_square_root(int nb);
int	my_is_prime(int nb);
int	my_find_prime_sup(int nb);
void	my_strcpy(char *dest, char *src);
char	*my_strncpy(char *dest, char *src, int nb);
char	*my_revstr(char *str);
char	*my_strstr(char *str, char *to_find);
int	my_strcmp(const char *s1, const char *s2);
int	my_strncmp(char *s1, char *s2, int nb);
char	*my_strupcase(char *str);
char	*my_strlowcase(char *str);
char	*my_strcapitalize(char *str);
int	my_str_isalpha(char *str);
int	my_str_isnum(char *str);
int	my_str_islower(char *str);
int	my_str_isupper(char *str);
int	my_str_isprintable(char *str);
int	my_showstr(char *str);
int	my_showmem(char *str, int size);
char	*my_strcat(char *dest, char *src);
char	*my_strncat(char *dest, char *src, int nb);
int	my_strlcat(char *dest, char *src, int size);
int     sum_stdarg(int i, int nb, ...);
int     disp_stdarg(char *s, ...);
int	my_put_unsnbr(unsigned int nb);
int     my_printf(char *s, ...);
char	*get_next_line(const int fd);

#endif /* !MY_H_ */
