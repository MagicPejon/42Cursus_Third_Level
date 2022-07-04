# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amalbrei <amalbrei@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/15 14:38:11 by amalbrei          #+#    #+#              #
#    Updated: 2022/07/02 19:57:21 by amalbrei         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	pipex
B_NAME	=	pipex
CC		=	gcc
SUBDIR	=	libft
SUBLIB	=	ft
CFLAGS	=	-Wall -Wextra -Werror
RM		=	rm	-rf

SRCS 	=	pipex.c		error_free.c	processes.c		pipex_split.c

B_SRCS	=	pipex_bonus.c	error_free_bonus.c	processes_bonus.c	\
			here_doc_bonus.c	get_files_bonus.c

all: $(NAME)

bonus:	$(SUBDIR) $(B_SRCS)
	$(MAKE) all -C libft
	$(MAKE) gnl -C libft
	$(CC) $(CFLAGS) $(B_SRCS) -L$(SUBDIR) -l$(SUBLIB) -o $(NAME)

.c.o:
	$(CC) $(CFLAGS) -Ilibft -c $^ -o $@

$(NAME): $(SUBDIR)
	$(MAKE) all -C libft
	$(CC) $(CFLAGS) $(SRCS) -L$(SUBDIR) -l$(SUBLIB) -o $(NAME)

clean:
	$(MAKE) clean -C libft

fclean: clean
	$(RM) $(NAME)
	$(MAKE) fclean -C libft

re: fclean $(NAME)

.PHONY = all clean fclean re
