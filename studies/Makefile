# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lambrozi <lambrozi@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/02 10:10:26 by lambrozi          #+#    #+#              #
#    Updated: 2020/11/02 10:10:38 by lambrozi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= learning 

LIB_DIR		= ../lib

MLX_DIR		= $(LIB_DIR)/minilibx
MLX		= $(MLX_DIR)/libmlx_Linux.a

INCLUDE		= learning.h

_SRC		= learning.c \
		  color.c \
		  shapes.c \
		  hooks.c

SDIR		= .
SRC		= $(addprefix $(SDIR)/,$(_SRC))

ODIR		= ./obj
OBJ		= $(patsubst $(SDIR)/%.c, $(ODIR)/%.o, $(SRC))

CC		= gcc
C_FLAGS		= -Wextra \
		  -Wall \
		  #-Werror


LXFLAGS		= -L$(MLX_DIR) \
		  -lmlx \
		  -lXext \
		  -lmlx_Linux \
		  -lX11 \
		  -lm \
		  -lbsd


.PHONY: all clean fclean re run norm 

all: $(NAME)

$(NAME): $(OBJ)
	@echo "\n\033[0;33mCompiling..."
	$(CC) -o $(NAME) $(OBJ) $(LXFLAGS)
	@echo "\033[0m"
	#ar rcs $@ $^
	#ranlib $@

$(ODIR)/%.o : $(SDIR)/%.c $(MLX)
	mkdir -p $(ODIR)
	$(CC) $(C_FLAGS) -c $< -o $@ -I$(MLX_DIR)

$(MLX):
	$(MAKE) -C $(MLX_DIR)

run: $(NAME)
	./$(NAME)

clean:
	rm -f $(OBJ)
	rm -rf $(ODIR)
	make -C $(MLX_DIR) clean

fclean: clean
	rm -f $(NAME)

norm:
	~/.norminette/norminette.rb $(SDIR) $(IDIR)

re: fclean all
