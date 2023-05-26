# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lpupier <lpupier@student.42lyon.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/23 15:15:27 by lpupier           #+#    #+#              #
#    Updated: 2023/05/26 16:06:29 by lpupier          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Constants
NAME			=	cub3d
CC				=	cc
RM				=	rm -rf
FLAGS			=	-Wall -Wextra -Werror -g3 #-fsanitize=address

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

# Headers files
HEADER			=	${DIR_HEADER}cub3d.h	\
					${DIR_HEADER}mlx.h

# Parsing files
SRC_PARSING		=	${DIR_PARSING}parsing.c					\
					${DIR_PARSING}check_file_extention.c	\
					${DIR_PARSING}get_textures_colors.c		\
					${DIR_PARSING}get_map.c

# Utils files
SRC_UTILS		=	${DIR_UTILS}errors.c	\
					${DIR_UTILS}init.c

# Utils files
SRC_DISPLAY		=	${DIR_DISPLAY}load_textures.c

# Sources files
SRC				=	${DIR_SRC}main.c	\
					${DIR_SRC}events.c	\
					${SRC_PARSING}		\
					${SRC_UTILS}		\
					${SRC_DISPLAY}

# Objects
OBJ				=	${patsubst %.c, ${DIR_OBJ}%.o, ${SRC}}

# Make in Linux or MacOS system
OS := $(shell uname)
ifeq ($(OS),Darwin)
  MLX			=	mlx_macos
  MLX_LIB		=	${DIR_LIB}mlx_macos.a
  MLX_FLAGS		=	-framework OpenGL -framework AppKit
else
  MLX			=	mlx_linux
  MLX_LIB		=	${DIR_LIB}mlx_linux.a
  MLX_FLAGS		=	-lXext -lX11
endif

# Rules
all:			${NAME}

${DIR_OBJ}%.o:	%.c	${HEADER}
				@mkdir -p ${shell dirname $@}
				${CC} ${FLAGS} -c $< -o $@ -I ${DIR_HEADER}

${DIR_OBJ}:		${MKDIR} ${DIR_OBJ}

${NAME}:		${LIBFT} ${OBJ}
				${CC} ${FLAGS} ${OBJ} ${LIBFT} -o ${NAME} -Llib -l${MLX} ${MLX_FLAGS}

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