# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aamajane <aamajane@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/04 15:10:36 by aamajane          #+#    #+#              #
#    Updated: 2022/08/23 18:20:19 by aamajane         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	pipex

LIBPX_M	=	srcs/libpx.a

LIBPX_B	=	srcs/libpx_bonus.a

SRCS_M	=	srcs/main.c \
			srcs/pipex.c \
			srcs/utils_1.c \
			srcs/utils_2.c \
			srcs/utils_3.c \
			srcs/check_cmd.c \
			srcs/child_process.c

OBJS_M	=	$(SRCS_M:.c=.o)

SRCS_B	=	srcs/pipex.c \
			srcs/utils_1.c \
			srcs/utils_2.c \
			srcs/utils_3.c \
			srcs/check_cmd.c \
			srcs/main_bonus.c \
			srcs/child_process.c \
			srcs/heredoc_bonus.c \
			srcs/get_next_line.c \

OBJS_B	=	$(SRCS_B:.c=.o)

CC		=	cc

CFLAGS	=	-Wall -Wextra -Werror

LIB		=	ar -rcs

RM		=	rm -rf


all:		$(NAME)

$(NAME):	$(LIBPX_M)
			@$(RM) $(LIBPX_B)
			@$(CC) $(CFLAGS) $(LIBPX_M) -o $(NAME)

$(LIBPX_M):	$(OBJS_M)
			@$(LIB) $(LIBPX_M) $(OBJS_M)

bonus:		$(LIBPX_B)

$(LIBPX_B):	$(OBJS_B)
			@$(RM) $(LIBPX_M)
			@$(LIB) $(LIBPX_B) $(OBJS_B)
			@$(CC) $(CFLAGS) $(LIBPX_B) -o $(NAME)

.c.o:
			@${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

clean:
			@$(RM) $(OBJS_M) $(OBJS_B) $(LIBPX_M) $(LIBPX_B)

fclean:		clean
			@$(RM) $(NAME)

re:			fclean all

.PHONY:		all bonus clean fclean re
