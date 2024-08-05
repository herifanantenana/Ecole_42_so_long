# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: arakotom <arakotom@student.42antananari    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/26 00:43:26 by arakotom          #+#    #+#              #
#    Updated: 2024/08/05 16:58:22 by arakotom         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFLAGS = -Wall -Wextra -Werror

SRC_DIR = srcs
OBJ_DIR = objs
HEADER_DIR = includes
LIBFT_DIR = libft
FT_PRINTF_DIR = ft_printf
GET_NEXT_LINE_DIR = get_next_line
MINILIBX_DIR = minilibx-linux

MINILIBX_FLAGS = -Lminilibx-linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz

SRCS = assets_init.c \
	assets_utils.c \
	draw_assets.c \
	draw_game_map.c \
	error_handler.c \
	game_handler.c \
	game_init.c \
	key_handler.c \
	main.c \
	map_file.c \
	map_utils.c \
	map_validation.c \
	move_utils.c \
	move.c
OBJS = $(addprefix $(OBJ_DIR)/, $(SRCS:.c=.o))
LIB = $(LIBFT_DIR)/libft.a \
	$(FT_PRINTF_DIR)/libftprintf.a \
	$(GET_NEXT_LINE_DIR)/get_next_line.a

RM = rm -rf

NAME = so_long

all : $(NAME)

$(NAME): $(OBJS) $(LIB)
	@make -C minilibx-linux
	$(CC) -g $(CFLAGS) $^ $(MINILIBX_FLAGS) -o $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	$(CC) -g $(CFLAGS) -I/usr/include -Imlx_linux -O3 -c $< -o $@

$(LIB) :
	@make -C $(LIBFT_DIR)
	@make -C $(FT_PRINTF_DIR)
	@make -C $(GET_NEXT_LINE_DIR)

clean :
	@make clean -C $(LIBFT_DIR)
	@make clean -C $(FT_PRINTF_DIR)
	@make clean -C $(GET_NEXT_LINE_DIR)
	@make clean -C $(MINILIBX_DIR)
	$(RM) $(OBJ_DIR)

fclean : clean
	@make fclean -C $(LIBFT_DIR)
	@make fclean -C $(FT_PRINTF_DIR)
	@make fclean -C $(GET_NEXT_LINE_DIR)
	$(RM) $(NAME)

re : fclean all

.PHONY: all clean fclean re
