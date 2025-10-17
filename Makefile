NAME        = so_long

CC          = gcc
CFLAGS      = -Wall -Wextra -Werror -I include -I $(LIBFT_DIR)/includes -I $(GNL_DIR)
RM          = rm -f

SRC_DIR     = src
CORE_DIR    = $(SRC_DIR)/core
CHK_DIR     = $(SRC_DIR)/checker
HOOK_DIR    = $(SRC_DIR)/hooks
RENDER_DIR  = $(SRC_DIR)/render
LIBFT_DIR   = libft
GNL_DIR     = get_next_line
MLX_DIR     = minilibx-linux

LIBFT       = $(LIBFT_DIR)/libft.a
MLX         = $(MLX_DIR)/libmlx.a
LFLAGS      = -L$(MLX_DIR) -lmlx -lXext -lX11 -lm

SRC         = $(RENDER_DIR)/init_mlx.c \
              $(RENDER_DIR)/render_map.c \
			  $(RENDER_DIR)/found_camera.c \
              $(HOOK_DIR)/input.c \
              $(HOOK_DIR)/movement.c \
              $(CHK_DIR)/map_validation.c \
              $(CHK_DIR)/map_shape.c \
              $(CHK_DIR)/map_content.c \
              $(CHK_DIR)/map_walls.c \
              $(CHK_DIR)/map_path.c \
              $(CORE_DIR)/state.c \
              $(GNL_DIR)/get_next_line.c \
              $(GNL_DIR)/get_next_line_utils.c \
              $(SRC_DIR)/main.c

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

.PHONY: all clean fclean re
