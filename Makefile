# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bkhatib <bkhatib@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/24 20:47:52 by bkhatib           #+#    #+#              #
#    Updated: 2023/01/24 20:49:22 by bkhatib          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3d

SRCS = $(wildcard *.c parser/*.c utils/*.c)
OBJS = $(SRCS:.c=.o)
HEADER = cub3d.h

INCLUDE	= -I /usr/local/include
LIBMLX	= -L /usr/local/lib

CC = gcc
FLAGS = -Wall -Wextra -Werror

GREEN		=	\033[92;5;118m
GREY		=	\033[33;2;37m
RESET		=	\033[0m
CURSIVE		=	\033[33;3m
SUCCESS	=	[$(GREEN)SUCCESS$(RESET)]

all: $(NAME)

$(NAME): $(OBJS) $(HEADER)
		@echo "$(CURSIVE)$(GREY)	- Compiling $(NAME)  ... $(RESET)\n"
		$(CC) $(OBJS) $(INCLUDE) $(LIBMLX) -lmlx -framework OpenGL -framework AppKit -o $(NAME)
		@echo "$(SUCCESS)$(GREEN)- Executable ready.\n$(RESET)"

%.o: %.c $(HEADER)
	@echo "$(CURSIVE)$(GREY)	- Making object file $@ from source file $< ... $(RESET)\n"
	@ $(CC) $(FLAGS) -c $< -o $@
	
clean:
	@ $(RM) $(OBJS)
	@echo "$(CURSIVE)$(GREY)	- Removing object files ... $(RESET)\n"
	@echo "$(SUCCESS)$(GREEN) - Object files removed.$(RESET)\n"

fclean: clean
	@ $(RM) $(NAME)
	@echo "$(CURSIVE)$(GREY)	- Removing $(NAME)... $(RESET)\n"
	@echo "$(SUCCESS)$(GREEN) - Executable removed.$(RESET)\n"

re: fclean all