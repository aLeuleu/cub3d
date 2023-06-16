# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lpupier <lpupier@student.42lyon.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/23 15:15:27 by lpupier           #+#    #+#              #
#    Updated: 2023/06/01 13:57:20 by lpupier          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Constants
NAME			=	cub3d
CC				=	cc
RM				=	rm -rf
FLAGS			=	-Wall -Wextra -Werror -g3 -fsanitize=address
FLAGS_MATH		=	-lm

# Libft support
DIR_LIBFT		=	libft/
LIBFT			=	${DIR_LIBFT}libft.a

# Directories
DIR_HEADER		=	include/
DIR_SRC			=	src/
DIR_LIB			=	lib/
DIR_OBJ			=	.obj/

# Subdirectories
DIR_PARSING		=	${DIR_SRC}parsing/
DIR_UTILS		=	${DIR_SRC}utils/
DIR_DISPLAY		=	${DIR_SRC}display/
DIR_EVENTS		=	${DIR_SRC}events/
DIR_DEBUG		=	${DIR_SRC}debug/

# Headers files
HEADER			=	${DIR_HEADER}cub3d.h	\
					${DIR_HEADER}mlx.h

# Parsing files
SRC_PARSING		=	${DIR_PARSING}parsing.c					\
					${DIR_PARSING}check_file_extention.c	\
					${DIR_PARSING}get_textures_colors.c		\
					${DIR_PARSING}get_map.c					\
					${DIR_PARSING}get_player_position.c		\
					${DIR_PARSING}load_colors.c				\
					${DIR_PARSING}map_format.c

# Utils files
SRC_UTILS		=	${DIR_UTILS}errors.c		\
					${DIR_UTILS}init.c			\
					${DIR_UTILS}free_memory.c	\
					${DIR_UTILS}utils.c

# Events files
SRC_EVENTS		=	${DIR_EVENTS}events.c			\
					${DIR_EVENTS}key_gestion.c		\
					${DIR_EVENTS}player_movements.c	\
					${DIR_EVENTS}move_functions.c	\
					${DIR_EVENTS}minimap_opening.c

# Display files
SRC_DISPLAY		=	${DIR_DISPLAY}load_textures.c				\
					${DIR_DISPLAY}render_frames.c				\
					${DIR_DISPLAY}display_game.c \
					${DIR_DISPLAY}draw_tools/mlx_draw_square.c	\
					${DIR_DISPLAY}draw_tools/mlx_draw_circle.c	\
					${DIR_DISPLAY}draw_tools/mlx_draw_pixel.c	\
					${DIR_DISPLAY}draw_tools/mlx_draw_line.c	\
					${DIR_DISPLAY}minimap/display_minimap.c		\
					${DIR_DISPLAY}minimap/geometry_minimap.c	\
					${DIR_DISPLAY}minimap/frame_minimap.c		\

# Sources files
SRC				=	${DIR_SRC}main.c	\
					${SRC_PARSING}		\
					${SRC_UTILS}		\
					${SRC_DISPLAY}		\
					${SRC_EVENTS}		\
					${SRC_DEBUG}

# Debug files
SRC_DEBUG		=	${DIR_DEBUG}debug_ray.c

# Objects
OBJ				=	${patsubst %.c, ${DIR_OBJ}%.o, ${SRC}}

# Make in Linux or MacOS system
OS := $(shell uname)
ARCH := $(shell uname -m)
ifeq ($(OS),Darwin)
  MLX			=	mlx_macos
  MLX_LIB		=	${DIR_LIB}${MLX}.a
  MLX_FLAGS		=	-framework OpenGL -framework AppKit
  DEFINE_OS		=	-D OS_DARWIN=1
else
  ifeq ($(ARCH),x86_64)
  	MLX			=	mlx_linux
  else
  	MLX			=	mlx_linux_arm
  endif
  MLX_LIB		=	${DIR_LIB}${MLX}.a
  MLX_FLAGS		=	-lXext -lX11
  DEFINE_OS		=	-D OS_LINUX=1
endif

# Rules
all:			${NAME}

${DIR_OBJ}%.o:	%.c	${HEADER}
				@mkdir -p ${shell dirname $@}
				${CC} ${FLAGS} -c $< -o $@ -I ${DIR_HEADER} ${DEFINE_OS} 

${DIR_OBJ}:		${MKDIR} ${DIR_OBJ}

${NAME}:		${LIBFT} ${OBJ}
				${CC} ${FLAGS} ${OBJ} ${LIBFT} -o ${NAME} -Llib -l${MLX} ${MLX_FLAGS} ${DEFINE_OS} ${FLAGS_MATH}

${LIBFT}:		FORCE
				${MAKE} -C ${DIR_LIBFT}

clean:
				${RM} ${OBJ} ${DIR_OBJ}
				${MAKE} clean -C ${DIR_LIBFT}

fclean:			clean
				${RM} ${NAME}
				${MAKE} fclean -C ${DIR_LIBFT}

re :			fclean all

check:
				norminette ${DIR_SRC} ${DIR_HEADER}cub3d.h


valgrind:		${NAME}
				valgrind --leak-check=full ./${NAME}

FORCE:

.PHONY: all clean fclean re check valgrind FORCE