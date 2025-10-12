NAME        = so_long

CC          = gcc
CFLAGS      = -Wall -Wextra -Werror -I include -I $(LIBFT_DIR)/includes -I $(GNL_DIR)
RM          = rm -f

SRC_DIR     = src
LIBFT_DIR   = libft
GNL_DIR     = get_next_line
MLX_DIR     = minilibx-linux

LIBFT       = $(LIBFT_DIR)/libft.a
MLX         = $(MLX_DIR)/libmlx.a
LFLAGS      = -L$(MLX_DIR) -lmlx -lXext -lX11 -lm

SRC         = $(SRC_DIR)/main.c \
              $(SRC_DIR)/map_check.c \
              $(SRC_DIR)/map_parser.c \
              $(SRC_DIR)/player.c \
              $(SRC_DIR)/render.c \
              $(SRC_DIR)/utils.c \
              $(GNL_DIR)/get_next_line.c \
              $(GNL_DIR)/get_next_line_utils.c

OBJ         = $(SRC:.c=.o)

all: $(LIBFT) $(MLX) $(NAME)

$(LIBFT):
	@$(MAKE) -C $(LIBFT_DIR)

$(MLX):
	@$(MAKE) -C $(MLX_DIR)

$(NAME): $(OBJ)
	$(CC) $(OBJ) $(LIBFT) $(LFLAGS) -o $(NAME)

clean:
	$(RM) $(OBJ)
	@$(MAKE) -C $(LIBFT_DIR) clean
	@$(MAKE) -C $(MLX_DIR) clean

fclean: clean
	$(RM) $(NAME)
	@$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re
