# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: asasada <asasada@student.42tokyo.j>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/05 19:45:54 by asasada           #+#    #+#              #
#    Updated: 2022/11/05 19:45:54 by asasada          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS_DIR	:= source/
SRCS	:= solong.c \
			math_utils.c \
			draw_map.c \
			draw_map_tools.c \
			check_cli_args.c \
			check_map_format.c \
			list_utils.c \
			check_valid_path.c \
			init_game_info.c \
			load_images_set_screen.c \
			player_movement.c \
			end_game.c

SRCS	:= $(addprefix $(SRCS_DIR), $(SRCS))
OBJS	:= ${SRCS:.c=.o}

HEADERS :=	./includes/solong.h \
			./includes/math_utils.h
NAME	:= so_long

B_SRCS_DIR	:= bonus/
B_SRCS		:= solong_bonus.c \
			math_utils_bonus.c \
			draw_map_bonus.c \
			draw_map_tools_bonus.c \
			check_cli_args_bonus.c \
			check_map_format_bonus.c \
			list_utils_bonus.c \
			check_valid_path_bonus.c \
			init_game_info_bonus.c \
			load_images_set_screen_bonus.c \
			player_movement_bonus.c \
			end_game_bonus.c \
			enemy_bonus.c \
			draw_optimization.c

B_SRCS	:= $(addprefix $(B_SRCS_DIR), $(B_SRCS))
B_OBJS	:= ${B_SRCS:.c=.o}

B_INCLDIR	:=	-I ./bonus/includes
B_HEADERS	:=	./bonus/includes/solong_bonus.h \
				./bonus/includes/math_utils_bonus.h
B_NAME	:=	so_long_bonus

LIBFT		:= ./libft/libft.a
MINILIBX 	:= ./minilibx-linux/libmlx.a
MINILIB_DEP := -Lminilibx-linux -lmlx -lXext -lX11

INCLDIR			:= -I ./includes
LIBFT_INCLDIR	:= -I ./libft
PF_INCLDIR		:= -I ./libft/ft_printf_includes
MLX_INCLDIR		:= -I ./minilibx-linux
X_H_PATH		:= -I /usr/include/X11

CC		:= cc
RM		:= rm -f
CFLAGS	:= -Wall -Wextra -Werror

all:		${NAME}

${OBJS}:	${SRCS_DIR}%.o : ${SRCS_DIR}%.c
	${CC} ${CFLAGS} ${INCLDIR} ${LIBFT_INCLDIR} ${PF_INCLDIR} ${MLX_INCLDIR} ${X_H_PATH} -c $< -o $@

${NAME}:	${OBJS} ${HEADERS} ${LIBFT} ${MINILIBX}
	${CC} ${CFLAGS} ${OBJS} -o ${NAME} ${MINILIB_DEP} ${LIBFT}

${LIBFT}:
	$(MAKE) -C ./libft

${MINILIBX}:
	$(MAKE) -C ./minilibx-linux

clean:
	${RM} ${OBJS} ${B_OBJS}
	$(MAKE) -C ./libft clean
	$(MAKE) -C ./minilibx-linux clean

fclean:	clean
	${RM} ${NAME} ${B_NAME}
	$(MAKE) -C ./libft fclean

${B_OBJS}:	${B_SRCS_DIR}%.o : ${B_SRCS_DIR}%.c
	${CC} ${CFLAGS} ${B_INCLDIR} ${LIBFT_INCLDIR} ${PF_INCLDIR} ${MLX_INCLDIR} ${X_H_PATH} -c $< -o $@

${B_NAME}:	${B_OBJS} ${B_HEADERS} ${LIBFT} ${MINILIBX}
	${CC} ${CFLAGS} ${B_OBJS} -o ${B_NAME} ${MINILIB_DEP} ${LIBFT}

bonus:	${B_NAME}

re:		fclean all

do:		all clean

norm:
	norminette source includes libft bonus

.PHONY:	all clean fclean re bonus do norm
