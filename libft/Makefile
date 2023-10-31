# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ole <marvin@42.fr>                         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/02 11:27:36 by ole               #+#    #+#              #
#    Updated: 2023/05/02 11:33:01 by ole              ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	libft.a

COLOR	=	\033[0;38;5;11m
RESET	=	\033[00m

SRCS	=	ft_atoi.c\
		ft_base.c\
		ft_bzero.c\
		ft_calloc.c\
		ft_isalnum.c\
		ft_isalpha.c\
		ft_isascii.c\
		ft_isdigit.c\
		ft_isduplicate.c\
		ft_isnum.c\
		ft_isprint.c\
		ft_issign.c\
		ft_itoa.c\
		ft_memchr.c\
		ft_memcmp.c\
		ft_memcpy.c\
		ft_memmove.c\
		ft_memset.c\
		ft_putchar.c\
		ft_putchar_count.c\
		ft_putchar_fd.c\
		ft_puthex.c\
		ft_putendl_fd.c\
		ft_putnbr.c\
		ft_putnbr_count.c\
		ft_putnbr_fd.c\
		ft_putstr.c\
		ft_putstr_count.c\
		ft_putstr_fd.c\
		ft_putptr.c\
		ft_split.c\
		ft_strchr.c\
		ft_strdup.c\
		ft_striteri.c\
		ft_strjoin.c\
		ft_strlcat.c\
		ft_strlcpy.c\
		ft_strlen.c\
		ft_strmapi.c\
		ft_strcmp.c\
		ft_strncmp.c\
		ft_strnstr.c\
		ft_strrchr.c\
		ft_strtrim.c\
		ft_substr.c\
		ft_tolower.c\
		ft_toupper.c\
		ft_lstnew.c\
		ft_lstadd_front.c\
		ft_lstsize.c\
		ft_lstadd_back.c\
		ft_lstlast.c\
		ft_lstdelone.c\
		ft_lstclear.c\
		ft_lstiter.c\
		ft_lstmap.c

OBJS	=	$(SRCS:.c=.o)

CC	=	@cc
FLAGS	=	-Wall -Wextra -Werror
HEADER	=	libft.h

.PHONY:		all clean fclean re

all:		$(NAME)

$(NAME):	$(OBJS)
		@ar -r $(NAME) $(OBJS)
		@printf "\n$(COLOR)o----------------------------------------o\n"
		@printf "$(COLOR)|$(RESET)           ! libft compiled !           $(COLOR)|\n"
		@printf "o----------------------------------------o$(RESET)\n\n"

%.o:		%.c $(HEADER)
		$(CC) $(FLAGS) -c $< -o $@

clean:		
		@rm -f $(OBJS)

fclean: 	clean
		@rm -f $(NAME)
		@printf "\n$(COLOR)---------- all are files deleted ---------$(RESET)\n\n"

re: 		fclean all
		@rm -f $(OBJS)


