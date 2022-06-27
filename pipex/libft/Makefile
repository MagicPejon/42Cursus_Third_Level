# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amalbrei <amalbrei@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/21 19:43:26 by amalbrei          #+#    #+#              #
#    Updated: 2022/06/17 15:53:33 by amalbrei         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	libft.a
CC		=	gcc
CFLAGS	=	-Wall -Wextra -Werror
LIB		=	ar	-rcs
RM		=	rm	-rf

SRCS 	= 	ft_isalpha.c	ft_isdigit.c	ft_isalnum.c	ft_isascii.c	\
			ft_isprint.c	ft_strlen.c		ft_memset.c		ft_bzero.c		\
			ft_memcpy.c		ft_memmove.c	ft_strlcpy.c	ft_strlcat.c	\
			ft_toupper.c	ft_tolower.c	ft_strchr.c		ft_strrchr.c	\
			ft_strncmp.c	ft_memchr.c		ft_memcmp.c		ft_strnstr.c	\
			ft_atoi.c		ft_calloc.c		ft_strdup.c		ft_substr.c		\
			ft_strjoin.c	ft_strtrim.c	ft_strmapi.c	ft_striteri.c	\
			ft_putchar_fd.c	ft_putstr_fd.c	ft_putendl_fd.c	ft_putnbr_fd.c	\
			ft_itoa.c		ft_split.c
			
B_SRCS 	=	ft_lstnew.c		ft_lstadd_front.c	ft_lstsize.c	ft_lstlast.c\
			ft_lstdelone.c	ft_lstadd_back.c	ft_lstclear.c	ft_lstiter.c\
			ft_lstmap.c

F_SRCS = 	ft_printf.c			ft_allocate.c		ft_putchar_arg.c		\
			ft_putpointer_arg.c	ft_puthexa_arg.c	ft_uputnbr_arg.c		\
			ft_putnbr_arg.c		ft_putstr_arg.c		ft_putpercent_arg.c		\
			ft_createflag.c		ft_isflag.c			ft_nlen.c				\
			ft_addspaces.c		ft_fn.c										\

G_SRCS = 	get_next_line.c	get_next_line_utils.c	get_next_line_bonus.c	\
			get_next_line_utils_bonus.c

OBJS	= 	$(SRCS:.c=.o)

B_OBJS	=	$(B_SRCS:.c=.o)

F_OBJS	=	$(F_SRCS:.c=.o)

G_OBJS	=	$(G_SRCS:.c=.o)

all: $(NAME)

.c.o:
	$(CC) $(CFLAGS) -c $^ -o $@

$(NAME): $(OBJS)
	$(LIB) $(NAME) $(OBJS)

bonus: $(B_OBJS)
	$(LIB) $(NAME) $(B_OBJS)

printf: $(F_OBJS)
	$(LIB) $(NAME) $(F_OBJS)

gnl: $(G_OBJS)
	$(LIB) $(NAME) $(G_OBJS)

list:
	ar -t $(NAME)
	@echo Object files above are within your library.

deploy:
	mv $(NAME) ..
	@echo DEPLOY DA BOI

clean:
	$(RM) $(OBJS) $(B_OBJS) $(F_OBJS) $(G_OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean $(NAME)

.PHONY = all clean fclean re
