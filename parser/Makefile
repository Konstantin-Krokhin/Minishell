NAME = parser.a

CC = cc

CFLAGS =
#CFLAGS = -Werror -Wall -Wextra
SRCS = parser.c get_char_index.c

SRCS_BONUS =

DEPS = parser.h

OBJS = $(SRCS:.c=.o)
OBJS_BONUS = $(SRCS_BONUS:.c=.o)

NAME_LIBFT = libft.a
LIBFT_DIR = ../libft/
LIBFT_DEPS = libft.h

all: $(NAME)

bonus: build_bonus

$(NAME): $(OBJS) $(DEPS)
	$(MAKE) -C ${LIBFT_DIR}
	ar -rc $(NAME) $(OBJS) ${LIBFT_DIR}$(NAME_LIBFT)

build_bonus: $(OBJS_BONUS)
	ar -rc $(NAME) $(OBJS_BONUS)

NAME_alone = parser.exe
standalone: $(OBJS) $(DEPS)
	$(MAKE) -C ${LIBFT_DIR}
	$(CC) $(CFLAGS) $(OBJS) ${LIBFT_DIR}$(NAME_LIBFT) -o $(NAME_alone)


%.o: %.c  $(DEPS)
	$(CC) -c $(CFLAGS) $<

clean:
	/bin/rm -f $(OBJS) $(OBJS_BONUS)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all