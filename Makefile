# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cbussier <cbussier@student.le-101.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/13 12:28:23 by cbussier          #+#    #+#              #
#    Updated: 2020/02/28 13:42:49 by cbussier         ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

HEADER		=	./srcs/cub3d.h

HEADER_BONUS	=	./srcs_bonus/cub3d_bonus.h

LIBHEADER	=	libft/libft.h

LIBFT		=	libft.a

GNL			=	get_next_line.a

LIBXNAME	=	minilibx_opengl_20191021/libmlx.a

NAME		=	cub3d.a

NAME_BONUS	=	cub3d_bonus.a

EXEC		=	Cub3D

SRCS		=	./srcs/cub3d.c
SRCS		+=	./srcs/ft_utilities.c
SRCS		+=	./srcs/ft_free.c
SRCS		+=	./srcs/ft_free2.c
SRCS		+=	./srcs/ft_free3.c
SRCS		+=	./srcs/ft_error.c
SRCS		+=	./srcs/parse_general.c
SRCS		+=	./srcs/parse_identify_elements.c
SRCS		+=	./srcs/parse_identify_elements2.c
SRCS		+=	./srcs/parse_f_c_colors.c
SRCS		+=	./srcs/parse_map_lines.c
SRCS		+=	./srcs/parse_map_integrity.c
SRCS		+=	./srcs/parse_map_integrity2.c
SRCS		+=	./srcs/parse_map_integrity3.c
SRCS		+=	./srcs/create_structure.c
SRCS		+=	./srcs/create_structure2.c
SRCS		+=	./srcs/create_structure3.c
SRCS		+=	./srcs/color_pixels.c
SRCS		+=	./srcs/npc.c
SRCS		+=	./srcs/player.c
SRCS		+=	./srcs/init_structure.c
SRCS		+=	./srcs/init_structure2.c
SRCS		+=	./srcs/init_structure3.c
SRCS		+=	./srcs/init_structure4.c
SRCS		+=	./srcs/analyse_move.c
SRCS		+=	./srcs/raycasting_global.c
SRCS		+=	./srcs/raycasting_ray_length.c
SRCS		+=	./srcs/raycasting_wall_impact.c
SRCS		+=	./srcs/raycasting_wall_impact2.c
SRCS		+=	./srcs/raycasting_npc_impact.c
SRCS		+=	./srcs/draw_ray_on_minimap.c
SRCS		+=	./srcs/draw_3d_bkg.c
SRCS		+=	./srcs/draw_3d_npc.c
SRCS		+=	./srcs/maths_functions.c
SRCS		+=	./srcs/screenshot.c
SRCS		+=	./srcs/screenshot2.c

SRCS_BONUS	=	./srcs_bonus/cub3d_bonus.c
SRCS_BONUS	+=	./srcs_bonus/ft_utilities_bonus.c
SRCS_BONUS	+=	./srcs_bonus/ft_free_bonus.c
SRCS_BONUS	+=	./srcs_bonus/ft_free2_bonus.c
SRCS_BONUS	+=	./srcs_bonus/ft_free3_bonus.c
SRCS_BONUS	+=	./srcs_bonus/ft_error_bonus.c
SRCS_BONUS	+=	./srcs_bonus/parse_general_bonus.c
SRCS_BONUS	+=	./srcs_bonus/parse_identify_elements_bonus.c
SRCS_BONUS	+=	./srcs_bonus/parse_identify_elements2_bonus.c
SRCS_BONUS	+=	./srcs_bonus/parse_f_c_colors_bonus.c
SRCS_BONUS	+=	./srcs_bonus/parse_map_lines_bonus.c
SRCS_BONUS	+=	./srcs_bonus/parse_map_integrity_bonus.c
SRCS_BONUS	+=	./srcs_bonus/parse_map_integrity2_bonus.c
SRCS_BONUS	+=	./srcs_bonus/parse_map_integrity3_bonus.c
SRCS_BONUS	+=	./srcs_bonus/create_structure_bonus.c
SRCS_BONUS	+=	./srcs_bonus/create_structure2_bonus.c
SRCS_BONUS	+=	./srcs_bonus/create_structure3_bonus.c
SRCS_BONUS	+=	./srcs_bonus/color_pixels_bonus.c
SRCS_BONUS	+=	./srcs_bonus/cursor_bonus.c
SRCS_BONUS	+=	./srcs_bonus/hud_bonus.c
SRCS_BONUS	+=	./srcs_bonus/minimap_bonus.c
SRCS_BONUS	+=	./srcs_bonus/npc_bonus.c
SRCS_BONUS	+=	./srcs_bonus/player_bonus.c
SRCS_BONUS	+=	./srcs_bonus/init_structure_bonus.c
SRCS_BONUS	+=	./srcs_bonus/init_structure2_bonus.c
SRCS_BONUS	+=	./srcs_bonus/init_structure3_bonus.c
SRCS_BONUS	+=	./srcs_bonus/init_structure4_bonus.c
SRCS_BONUS	+=	./srcs_bonus/analyse_move_bonus.c
SRCS_BONUS	+=	./srcs_bonus/collision_bonus.c
SRCS_BONUS	+=	./srcs_bonus/collision2_bonus.c
SRCS_BONUS	+=	./srcs_bonus/raycasting_global_bonus.c
SRCS_BONUS	+=	./srcs_bonus/raycasting_ray_length_bonus.c
SRCS_BONUS	+=	./srcs_bonus/raycasting_wall_impact_bonus.c
SRCS_BONUS	+=	./srcs_bonus/raycasting_wall_impact2_bonus.c
SRCS_BONUS	+=	./srcs_bonus/raycasting_npc_impact_bonus.c
SRCS_BONUS	+=	./srcs_bonus/draw_ray_on_minimap_bonus.c
SRCS_BONUS	+=	./srcs_bonus/draw_3d_bkg_bonus.c
SRCS_BONUS	+=	./srcs_bonus/draw_3d_npc_bonus.c
SRCS_BONUS	+=	./srcs_bonus/maths_functions_bonus.c
SRCS_BONUS	+=	./srcs_bonus/screenshot_bonus.c
SRCS_BONUS	+=	./srcs_bonus/screenshot2_bonus.c

OBJS		= ${SRCS:.c=.o}

OBJS_BONUS	= ${SRCS_BONUS:_bonus.c=_bonus.o}

AR		= ar rcs
RM		= rm -rf

#CFLAGS	= -Wall -Wextra -Werror
CFLAGS	= -O3 -march=native -ffast-math -Wall -Wextra -Werror
#CFLAGS	= -O3 -Wall -Wextra -Werror

CC		= gcc

all:		$(NAME)

bonus:		$(NAME_BONUS)

%_bonus.o:	%_bonus.c $(HEADER_BONUS)
			$(CC) $(CFLAGS) -c $< -o $@
			
%.o:		%.c $(HEADER)
			$(CC) $(CFLAGS) -c $< -o $@

$(NAME_BONUS):	mlib gnl libx $(OBJS_BONUS)
				@echo "\033[1;32m" $(NAME_BONUS) " OK\033[0m"
				$(CC) $(CFLAGS) $(LIBFT) $(GNL) $(LIBXNAME) -o $(EXEC) $(OBJS_BONUS) -g3 -framework OpenGL -framework Appkit -lz #-fsanitize=address 
				@echo "\033[1;32m" $(EXEC) " OK\033[0m"

$(NAME):		mlib gnl libx $(OBJS)
				$(CC) $(CFLAGS) $(LIBFT) $(GNL) $(LIBXNAME) -o $(EXEC) $(OBJS) -g3 -framework OpenGL -framework Appkit -lz #-fsanitize=address 
				@echo "\033[1;32m" $(EXEC) " OK\033[0m"

mlib:		
			@make -C libft all

gnl:		
			@make -C get_next_line all

libx:		
			@make -C minilibx_opengl_20191021 all

clean:
			@make -C libft clean
			@make -C get_next_line clean
			@make -C minilibx_opengl_20191021 clean
			@$(RM) $(OBJS)
			@$(RM) $(OBJS_BONUS)

fclean:		clean
			@$(RM) $(NAME)
			@$(RM) $(NAME_BONUS)
			@$(RM) $(EXEC)
			@$(RM) $(LIBFT)
			@$(RM) $(GNL)
			@$(RM) libft/$(LIBFT)
			@$(RM) get_next_line/$(GNL)
			@echo "DELETING \033[1;32m OK\033[0m"

re:			fclean all

rebonus:	fclean bonus

.PHONY:		all re fclean clean bonus rebonus
