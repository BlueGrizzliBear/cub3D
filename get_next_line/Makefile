# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    Makefile                                         .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: cbussier <marvin@le-101.fr>                +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2019/10/13 12:28:23 by cbussier     #+#   ##    ##    #+#        #
#    Updated: 2020/01/07 12:40:38 by cbussier    ###    #+. /#+    ###.fr      #
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #

HEADER	= get_next_line.h

NAME	= get_next_line.a

SRCS	=	get_next_line.c
SRCS	+=	get_next_line_utils.c

OBJS	= ${SRCS:.c=.o}

AR		= ar rcs
RM		= rm -rf

CFLAGS	= -Wall -Wextra -Werror

CC		= gcc

all:		$(NAME)

%.o:%.c		$(HEADER)
			@$(CC) $(CFLAGS) -c $< -o $@

$(NAME):	$(OBJS)
			@$(AR) $(NAME) $(OBJS)
			@echo "\033[1;32m" $(NAME) " OK\033[0m"
			@cp $(NAME) ../$(NAME)

clean:		
			@$(RM) $(OBJS)

fclean:		clean
			@$(RM) $(NAME)

re:			fclean all

.PHONY:		all re fclean clean
