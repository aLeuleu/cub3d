# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lpupier <lpupier@student.42lyon.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/23 15:15:27 by lpupier           #+#    #+#              #
#    Updated: 2023/05/23 16:48:39 by lpupier          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Constants
NAME			=	cub3d
CC				=	cc
RM				=	rm -rf
FLAGS			=	-Wall -Wextra -Werror -g3 -fsanitize=address

# Directories
DIR_HEADER		=	include/
DIR_SRC			=	src/
DIR_LIB			=	lib/
DIR_OBJ			=	.obj/

# Headers files
HEADER			=	${DIR_HEADER}cub3d.h	\
					${DIR_HEADER}mlx.h

# Sources files
SRC				=	${DIR_SRC}main.c		\
					${DIR_SRC}events.c

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

${NAME}:		${OBJ}
				${CC} ${FLAGS} ${OBJ} -o ${NAME} -Llib -l${MLX} ${MLX_FLAGS}
clean:
				${RM} ${OBJ} ${DIR_OBJ}

fclean:			clean
				${RM} ${NAME}

re :			fclean all

check:
				norminette ${DIR_SRC} ${DIR_HEADER}cub3d.h

.PHONY: all clean fclean re check