NAME= minishell

CFLAGS = -Wall -Werror -Wextra
#CFLAGS =-lreadline   -Wall -Werror -Wextra
#CFLAGS= -lreadline  -Wall -Werror -Wextra #-fsanitize=address


CC = cc

SRC = learn1.c

DEPS =

SRC_BONUS =

DEPS_BONUS =

NAME_LIBFT = libft.a
LIBFT_DIR = ./libft/
LIBFT_DEPS = libft.h


OBJ = $(SRC:%.c=%.o)

OBJ_BONUS = $(SRC_BONUS:%.c=%.o)


all: $(NAME)

$(NAME): $(OBJ) $(DEPS)
	$(MAKE) -C ${LIBFT_DIR}
	$(CC) $(OBJ)  -lreadline  $(CFLAGS) -o $(NAME) ${LIBFT_DIR}$(NAME_LIBFT)

bonus: $(OBJ_BONUS) $(DEPS_BONUS)
	$(MAKE) -C ${LIBFT_DIR}
	$(CC) $(OBJ_BONUS) $(CFLAGS) -o $(NAME) ${LIBFT_DIR}$(NAME_LIBFT)

%.o: %.c  $(DEPS) $(DEPS_BONUS) $(LIBFT_DEPS)
		$(CC) -c $(CFLAGS)

clean:
	rm -f $(OBJ)
	rm -f $(OBJ_BONUS)
	make clean -C ${LIBFT_DIR}

fclean: clean
	/bin/rm -f $(NAME)
	make fclean -C ${LIBFT_DIR}

re: fclean all
