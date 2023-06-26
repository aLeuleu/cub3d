# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lpupier <lpupier@student.42lyon.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/24 11:24:38 by lpupier           #+#    #+#              #
#    Updated: 2023/05/24 13:53:01 by lpupier          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Constants
NAME		=	libft.a
CC			=	cc
CFLAGS		=	-Wall -Wextra -Werror
RM			=	rm -rf

# Headers directory
DIR_HEADER	=	includes/

# Sources directory
DIR_CHAR	=	char/
DIR_PRINTF	=	ft_printf/
DIR_GNL		=	get_next_line/
DIR_LST		=	lst/
DIR_MEM		=	mem/
DIR_STR		=	str/
DIR_WRITE	=	write/

# Headers file
HEADERS		=	${DIR_HEADER}libft.h

# Char files
SRC_CHAR	=	${DIR_CHAR}ft_isalnum.c	\
				${DIR_CHAR}ft_isalpha.c	\
				${DIR_CHAR}ft_isascii.c	\
				${DIR_CHAR}ft_isdigit.c	\
				${DIR_CHAR}ft_isprint.c \
				${DIR_CHAR}ft_tolower.c	\
				${DIR_CHAR}ft_toupper.c


# Printf files
SRC_PRINTF	=	${DIR_PRINTF}ft_display_arg.c	\
				${DIR_PRINTF}ft_functions.c		\
				${DIR_PRINTF}ft_printf.c

# Get Next Line files
SRC_GNL		=	${DIR_GNL}get_next_line.c		\
				${DIR_GNL}get_next_line_utils.c

# List files
SRC_LST		=	${DIR_LST}ft_lstadd_back.c	\
				${DIR_LST}ft_lstadd_front.c	\
				${DIR_LST}ft_lstclear.c		\
				${DIR_LST}ft_lstdelone.c	\
				${DIR_LST}ft_lstiter.c		\
				${DIR_LST}ft_lstlast.c		\
				${DIR_LST}ft_lstmap.c		\
				${DIR_LST}ft_lstnew.c		\
				${DIR_LST}ft_lstsize.c		\
				${DIR_LST}ft_len_tab.c		\
				${DIR_LST}ft_free_tab.c

# Memory files
SRC_MEM		=	${DIR_MEM}ft_bzero.c	\
				${DIR_MEM}ft_calloc.c	\
				${DIR_MEM}ft_memchr.c	\
				${DIR_MEM}ft_memcmp.c	\
				${DIR_MEM}ft_memcpy.c	\
				${DIR_MEM}ft_memmove.c	\
				${DIR_MEM}ft_memset.c

# Strings files
SRC_STR		=	${DIR_STR}ft_atoi.c		\
				${DIR_STR}ft_itoa.c		\
				${DIR_STR}ft_split.c	\
				${DIR_STR}ft_strchr.c	\
				${DIR_STR}ft_strdup.c	\
				${DIR_STR}ft_striteri.c	\
				${DIR_STR}ft_strjoin.c	\
				${DIR_STR}ft_strlcat.c	\
				${DIR_STR}ft_strlcpy.c	\
				${DIR_STR}ft_strlen.c	\
				${DIR_STR}ft_strmapi.c	\
				${DIR_STR}ft_strncmp.c	\
				${DIR_STR}ft_strcmp.c	\
				${DIR_STR}ft_strrchr.c	\
				${DIR_STR}ft_strtrim.c	\
				${DIR_STR}ft_substr.c

# Write files
SRC_WRITE	=	${DIR_WRITE}ft_putchar_fd.c		\
				${DIR_WRITE}ft_putendl_fd.c		\
				${DIR_WRITE}ft_putnbr_base.c	\
				${DIR_WRITE}ft_putnbr_fd.c		\
				${DIR_WRITE}ft_putstr_fd.c


# Sources files
SRCS	=	${SRC_CHAR}		\
			${SRC_PRINTF}	\
			${SRC_GNL}		\
			${SRC_LST}		\
			${SRC_MEM}		\
			${SRC_STR}		\
			${SRC_WRITE}

# Objects
DIR_OBJS		=	.objs/
OBJS			=	${patsubst %.c, ${DIR_OBJS}%.o, ${SRCS}}

# Rules
all:		$(NAME)

${DIR_OBJS}%.o: %.c	${HEADERS}
	@mkdir -p ${shell dirname $@}
	${CC} ${CFLAGS} -c $< -o $@ -I ${DIR_HEADER}

${DIR_OBJS}: ${MKDIR} ${DIR_OBJS}

$(NAME):	$(OBJS)
			ar rcs $(NAME) $(OBJS)

clean:
			${RM} $(OBJS)

fclean:		clean
			${RM} $(NAME)

re:			fclean $(NAME)

.PHONY:		all clean fclean re