# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kokrokhi <kokrokhi@student.42wolfsburg.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/28 22:11:49 by konstantink       #+#    #+#              #
#    Updated: 2022/07/28 19:05:48 by kokrokhi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRC =	ft_strnstr.c \
		ft_isdigit.c \
		ft_putstr_fd.c \
		ft_strlcpy.c \
		ft_strlen.c \
		ft_memcmp.c \
		ft_putnbr_fd.c \
		ft_strchr.c \
		ft_striteri.c \
		ft_bzero.c \
		ft_strjoin.c \
		ft_isascii.c \
		ft_memcpy.c \
		ft_isprint.c \
		ft_putendl_fd.c \
		ft_toupper.c \
		ft_split.c \
		ft_strrchr.c \
		ft_isalpha.c \
		ft_memchr.c \
		ft_putchar_fd.c \
		ft_memset.c \
		ft_substr.c \
		ft_strncmp.c \
		ft_strmapi.c \
		ft_strtrim.c \
		ft_memmove.c \
		ft_strlcat.c \
		ft_calloc.c \
		ft_strdup.c \
		ft_atoi.c \
		ft_isalnum.c \
		ft_itoa.c \
		ft_tolower.c \
		ft_printf.c \
		ft_printdecimal.c \
		ft_printhex.c \
		ft_printstring.c \
		ft_printunsigned.c \
		ft_printvoid.c \

OBJ = $(SRC:.c=.o)

BONUS =	ft_lstnew.c \
		ft_lstadd_front.c \
		ft_lstsize.c \
		ft_lstlast.c \
		ft_lstadd_back.c \
		ft_lstdelone.c \
		ft_lstclear.c \
		ft_lstiter.c \
		ft_lstmap.c

BONUS_OBJ =$(BONUS:.c=.o)

CC = gcc
FLAGS = -Wall -Wextra -Werror
RM = rm -rf

all: $(NAME)

$(NAME): $(OBJ)
	ar rsc $(NAME) $(OBJ)

clean:
	$(RM) $(OBJ) $(BONUS_OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

bonus: $(OBJ) $(BONUS_OBJ)
	ar rsc $(NAME) $(OBJ) $(BONUS_OBJ)

.PHONY: all clean fclean re bonus