# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    Makefile                                         .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: cbussier <marvin@le-101.fr>                +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2019/10/13 12:28:23 by cbussier     #+#   ##    ##    #+#        #
#    Updated: 2020/01/07 15:23:29 by cbussier    ###    #+. /#+    ###.fr      #
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #

HEADER	= libft.h

NAME	= libft.a

SRCS	=	ft_atoi.c
SRCS	+=	ft_bzero.c
SRCS	+=	ft_calloc.c
SRCS	+=	ft_isalnum.c
SRCS	+=	ft_isalpha.c
SRCS	+=	ft_isascii.c
SRCS	+=	ft_isdigit.c
SRCS	+=	ft_isprint.c
SRCS	+=	ft_itoa.c
SRCS	+=	ft_itoa_base.c
SRCS	+=	ft_ltoa_base.c
SRCS	+=	ft_utoa_base.c
SRCS	+=	ft_memchr.c
SRCS	+=	ft_memcmp.c
SRCS	+=	ft_memccpy.c
SRCS	+=	ft_memcpy.c
SRCS	+=	ft_memmove.c
SRCS	+=	ft_memset.c
SRCS	+=	ft_putchar_fd.c
SRCS	+=	ft_putendl_fd.c
SRCS	+=	ft_putnbr_fd.c
SRCS	+=	ft_putstr_fd.c
SRCS	+=	ft_split.c
SRCS	+=	ft_strchr.c
SRCS	+=	ft_strdup.c
SRCS	+=	ft_strjoin.c
SRCS	+=	ft_strjoinfree.c
SRCS	+=	ft_strlcat.c
SRCS	+=	ft_strlcpy.c
SRCS	+=	ft_strlen.c
SRCS	+=	ft_strmapi.c
SRCS	+=	ft_strncmp.c
SRCS	+=	ft_strnstr.c
SRCS	+=	ft_strrchr.c
SRCS	+=	ft_strtrim.c
SRCS	+=	ft_substr.c
SRCS	+=	ft_tolower.c
SRCS	+=	ft_toupper.c

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
