CC 		= clang
NAME 	= cub3D
USER 	= dparada
CFLAGS 	= -Wall -Wextra -Werror -g -fsanitize=address
LIBFT 	= ./Include/LIBFT/libft.a
MLX42 	= ./Include/MLX42_P2/build/libmlx42.a
MLX_FLAGS = -Iinclude -ldl -lglfw -pthread -lm
SRC_DIR = src/
OBJ_DIR = obj/
LIB = ./Include/$(NAME).h

MAGENTA = \033[35;1m
YELLOW  = \033[33;1m
GREEN   = \033[32;1m
WHITE   = \033[37;1m
RESET   = \033[0m
GRAY 	= \033[0;90m
BLUE    = \033[34;1m
CYAN    = \033[37;1m
BOLD	= \033[1m
RED		= \033[31;1m

SRC_FILES = main ft_utils ft_get_map ft_check_maps free textures maybe_delete save_memory \
			init_mlx_game set_moves put_textures ray_casting keys distance mini_map \
			

SRC = $(addprefix $(SRC_DIR), $(addsuffix .c, $(SRC_FILES)))
OBJ = $(addprefix $(OBJ_DIR), $(addsuffix .o,$(SRC_FILES)))

OBJF = .cache_exists

all: $(NAME)

$(NAME): compiling $(OBJ) $(LIBFT) $(MLX42)
		@echo
		@$(CC) $(CFLAGS) $(OBJ) $(LIBFT) $(MLX42) $(MLX_FLAGS) -o $(NAME)
		@echo "$(RED)Cub3D compiled!$(RESET)"

$(MLX42):
		@cmake -B Include/MLX42_P2/build -S ./Include/MLX42_P2
		@cmake --build Include/MLX42_P2/build -j4

$(LIBFT):
		@make -s -C ./Include/LIBFT/

$(OBJ_DIR)%.o: $(SRC_DIR)%.c $(LIB)| $(OBJF)
		@mkdir -p $(dir $@)
		@echo "$(WHITE)Compiling: $(RESET)$(notdir $<)"
		@$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR)%.o: $(BONUS_DIR)%.c | $(OBJF)
		@echo "$(WHITE)Compiling: $(RESET)$(notdir $<)"
		@$(CC) $(CFLAGS) -c $< -o $@

$(OBJF):
		@mkdir -p $(OBJ_DIR)

compiling:
		@echo "$(RED)Compiling Cub3D: $(RESET)"

clean:
		@rm -rf $(OBJ_DIR)
		@make clean -s -C ./Include/LIBFT/
		@make clean -s -C ./Include/MLX42_P2/build/
		@echo "$(RED)Cleaning Cub3D's objects. $(RESET)"
		@echo

fclean:
		@rm -rf $(OBJ_DIR)
		@rm -rf $(NAME)
		@make fclean -s -C ./Include/LIBFT/
		@make clean -s -C ./Include/MLX42_P2/build/
		@echo "$(RED)Cleaning Cub3D's executables.$(RESET)"

re: fclean all

norm:
		norminette $(SRC_DIR)

.PHONY: all clean fclean re compiling
