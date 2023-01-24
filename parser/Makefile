NAME = parser.a
CC = cc
CFLAGS = -Werror -Wall -Wextra
SRCS = parser.c

SRCS_BONUS =

DEPS = parser.h

OBJS = $(SRCS:.c=.o)
OBJS_BONUS = $(SRCS_BONUS:.c=.o)

all: $(NAME)

bonus: build_bonus

$(NAME): $(OBJS) $(OBJS_BONUS)
	ar -rc $(NAME) $(OBJS) $(OBJS_BONUS)

build_bonus: $(OBJS_BONUS)
	ar -rc $(NAME) $(OBJS_BONUS)

%.o: %.c  $(DEPS)
	$(CC) -c $(CFLAGS) $<

clean:
	/bin/rm -f $(OBJS) $(OBJS_BONUS)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all