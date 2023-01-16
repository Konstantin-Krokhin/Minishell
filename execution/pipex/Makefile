# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kokrokhi <kokrokhi@student.42wolfsburg.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/22 16:59:40 by kokrokhi          #+#    #+#              #
#    Updated: 2022/08/02 00:01:46 by kokrokhi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC		= clang
NAME	= pipex
CFLAGS	= -Wall -Werror -Wextra
HEADER	= -I includes -I Libft/
LIBFT	= Libft/
LIBFT_A = Libft/libft.a

SRCS	=	pipex.c pipex_helper.c

OBJS	= $(SRCS:.c=.o)

NC			:= \033[0m
B_RED		:= \033[1;31m
RED 		:= \033[0;31m
B_GREEN		:= \033[1;32m
GREEN 		:= \033[0;32m
B_BLUE 		:= \033[1;34m
BLUE 		:= \033[0;34m
PURPLE		:= \033[0;35m
B_PURPLE	:= \033[1;35m

SUBM_STATE := $(shell find Libft -type f)

# to automatically initialize the submodules
ifeq ($(SUBM_STATE),)
SUBM_FLAG	= submodule
else 
SUBM_FLAG	= 
endif

all: $(SUBM_STATE) $(LIBFT_A) $(PRINTF_A) $(NAME) 

%.o : %.c 
	@echo "$(B_PURPLE)Compiling: $(BLUE)$(notdir $<) 🔨$(NC)"
	@$(CC) $(CFLAGS) -c $< -o $@

submodule: 
	git submodule init 
	git submodule update

$(LIBFT_A):
	@echo "\n${GREEN}======== libft ========${NC}"
	@$(MAKE) -C $(LIBFT)

Pipex: 
	@echo "${GREEN}======== Pipex ========${NC}"

$(NAME): Pipex $(OBJS)
	@$(CC) $(HEADER) -L$(LIBFT) $(SRCS) $(DEBUG) -lft -o $(NAME)

clean:
	@rm -f $(OBJS)
	@echo "${B_RED}🧹 Cleaning: ${RED} $(notdir $(OBJS))"
	@$(MAKE) -C $(LIBFT) fclean

fclean: clean
	@rm -f $(NAME)
	@echo "${B_RED}🧹 Cleaning: ${RED} $(NAME)"

re: fclean all

.PHONY: all, libft, clean, fclean