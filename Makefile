##
## Makefile for Makefile in /home/pignol_r/Epitech/rendu/PSU_2015_tetris
## 
## Made by pignol_r
## Login   <pignol_r@epitech.net>
## 
## Started on  Fri Mar 18 10:40:44 2016 pignol_r
## Last update Sun Apr 10 17:28:24 2016 pignol_r
##

CC		= gcc

RM		= rm -f

MY_MAKE		= $(MAKE) -C

LIB		= -L./lib/my -lmy

NAME		= mysh

CFLAGS		+= -D _BSD_SOURCE -D _POSIX_SOURCE -Wextra -Wall
CFLAGS		+= -ansi -pedantic -Iinclude

DEBUG		?= 0
ifeq ($(DEBUG), 1)
	CFLAGS += -g
endif

SRCS		=	src/main.c \
			src/env.c \
			src/buil.c \
			src/init.c \
			src/path.c \
			src/path_next.c \
			src/free.c \
			src/mini_epur.c \
			src/prompt.c \
			src/direct_exec.c \
			src/buil_exec.c \
			src/error.c \
			src/exec.c \
			src/buil_next.c \
			src/arg.c \
			src/pipe.c \
			src/fd.c \
			src/check_redirect.c \
			src/redirect.c

OBJS		= $(SRCS:.c=.o)

all:		runlib $(NAME)

$(NAME):	$(OBJS)
			$(CC) -o $(NAME) $(OBJS) $(LIB)

runlib:
		$(MY_MAKE) ./lib/my

clean:
		$(RM) $(OBJS)

libclean:
		$(MY_MAKE) ./lib/my fclean

fclean:		clean libclean
			$(RM) $(NAME)

re:		fclean all

.PHONY:		all clean fclean re
