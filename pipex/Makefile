# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amalbrei <amalbrei@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/15 14:38:11 by amalbrei          #+#    #+#              #
#    Updated: 2022/06/26 21:50:52 by amalbrei         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	pipex
CC		=	gcc
SUBDIR	=	libft
SUBLIB	=	ft
CFLAGS	=	-Wall -Wextra -Werror
RM		=	rm	-rf

SRCS 	=	pipex.c		error_free.c	processes.c

OBJS	= 	$(SRCS:.c=.o)

all: $(NAME)

.c.o:
	$(CC) $(CFLAGS) -Ilibft -c $^ -o $@

$(NAME): $(SUBDIR) $(OBJS)
	$(MAKE) all -C libft
	$(CC) $(CFLAGS) $(SRCS) -L$(SUBDIR) -l$(SUBLIB) -o $(NAME)
	
$(SUBDIR):
	$(MAKE) all -C libft

clean:
	$(RM) $(OBJS)
	$(MAKE) clean -C libft

fclean: clean
	$(RM) $(NAME)
	$(MAKE) fclean -C libft

re: fclean $(NAME)

.PHONY = all clean fclean re
