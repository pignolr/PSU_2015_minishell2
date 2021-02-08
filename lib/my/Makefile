##
## Makefile for MAKEFILE in /home/pignol_r/rendu/PSU_2015_my_printf_bootstrap/lib/my
## 
## Made by remi pignol
## Login   <pignol_r@epitech.net>
## 
## Started on  Wed Nov  4 16:01:50 2015 remi pignol
## Last update Sun Apr 10 17:28:28 2016 pignol_r
##

CMP		= ar rc

RM		= rm -f

CFLAGS		= -Wall -Werror -ansi -pedantic -I.

DEBUG		?= 0
ifeq ($(DEBUG), 1)
	CFLAGS += -g
endif

NAME		= libmy.a

SRCS		= my_find_prime_sup.c \
			get_next_line.c \
			init_get_next_line.c \
			my_getnbr.c \
			my_isneg.c \
			my_is_prime.c \
			my_power_rec.c \
			my_putchar.c \
			my_put_nbr.c \
			my_putstr.c \
			my_revstr.c \
			my_showmem.c \
			my_showstr.c \
			my_sort_int_tab.c \
			my_square_root.c \
			my_strcapitalize.c \
			my_strcat.c \
			my_strcmp.c \
			my_strcpy.c \
			my_str_isalpha.c \
			my_str_islower.c \
			my_str_isnum.c \
			my_str_isprintable.c \
			my_str_isupper.c \
			my_strlcat.c \
			my_strlen.c \
			my_strlowcase.c \
			my_strncat.c \
			my_strncmp.c \
			my_strncpy.c \
			my_strstr.c \
			my_strupcase.c \
			my_swap.c \
			sum_stdarg.c \
			disp_stdarg.c \
			my_put_unsnbr.c \
			my_flag2.c \
			my_flag.c \
			my_hexa.c \
			my_printf.c \
			my_put_print.c \
			my_realloc.c

OBJS		= $(SRCS:.c=.o)

H		= my.h


all:		$(NAME) ran cph

$(NAME):	$(OBJS)
			$(CMP) $(NAME) $(OBJS)

ran:
		ranlib $(NAME)

cph:
		cp $(H) ../../include

clean:
		$(RM) $(OBJS)

fclean:		clean
			$(RM) $(NAME)

re:		fclean all

.PHONY:		all clean fclean re
