/*
** get_next_line.h for macro in /home/pignol_r/Epitech/rendu/CPE_2015_getnextline
**
** Made by pignol_r
** Login   <pignol_r@epitech.net>
**
** Started on  Tue Jan  5 15:46:31 2016 pignol_r
** Last update Sat Apr  2 14:15:16 2016 pignol_r
*/

#ifndef GET_NEXT_LINE_H_
# define GET_NEXT_LINE_H_

# ifndef READ_SIZE
#  define READ_SIZE (10)
# endif /* !READ_SIZE */

typedef struct	s_fd
{
  int		fd;
  int		i;
  int		j;
  char		buff[READ_SIZE + 1];
  struct s_fd	*next;
}		t_fd;

char		*free_list_line(t_fd *elem);
t_fd		*init_list_line(int fd);

#endif /* !GET_NEXT_LINE_H_ */
