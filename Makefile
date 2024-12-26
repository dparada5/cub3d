CC 		= gcc
NAME 	= cub3D
NAME_BONUS = cub3D_bonus
USER 	= dparada
CFLAGS 	= -Wall -Wextra -Werror -g
LIBFT 	= ./Include/LIBFT/libft.a
MLX42 	= ./Include/MLX42_P2/build/libmlx42.a
MLX_FLAGS = -Iinclude -ldl -lglfw -pthread -lm
SRC_DIR = src/
SRC_BONUS_DIR = src_bonus/
OBJ_DIR = obj/
OBJ_BONUS_DIR = obj_bonus/
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

SRC_FILES = main ft_utils ft_get_map ft_check_maps free textures save_memory \
			init_mlx_game set_moves put_textures ray_casting keys distance mini_map \
			paint_textures animations \

SRC_F_BONUS = main_bonus ft_utils_bonus ft_get_map_bonus ft_check_maps_bonus free_bonus \
			textures_bonus save_memory_bonus init_mlx_game_bonus set_moves_bonus \
			put_textures_bonus ray_casting_bonus keys_bonus distance_bonus mini_map_bonus \
			paint_textures_bonus animations_bonus door_bonus\

SRC = $(addprefix $(SRC_DIR), $(addsuffix .c, $(SRC_FILES)))
OBJ = $(addprefix $(OBJ_DIR), $(addsuffix .o,$(SRC_FILES)))

SRC_BONUS = $(addprefix $(SRC_BONUS_DIR), $(addsuffix .c, $(SRC_F_BONUS)))
OBJ_BONUS = $(addprefix $(OBJ_BONUS_DIR), $(addsuffix .o,$(SRC_F_BONUS)))

OBJF = .cache_exists

all: $(NAME)

$(NAME): compiling $(OBJ) $(LIBFT) $(MLX42)
		@echo
		@$(CC) $(CFLAGS) $(OBJ) $(LIBFT) $(MLX42) $(MLX_FLAGS) -o $(NAME)
		@echo "$(RED)Cub3D compiled!$(RESET)"

bonus: compiling_bonus $(OBJ_BONUS) $(LIBFT) $(MLX42)
		@echo
		@$(CC) $(CFLAGS) $(OBJ_BONUS) $(LIBFT) $(MLX42) $(MLX_FLAGS) -o $(NAME_BONUS)
		@echo "$(RED)Cub3D Bonus compiled!$(RESET)"

$(MLX42):
		@cmake -B Include/MLX42_P2/build -S ./Include/MLX42_P2
		@cmake --build Include/MLX42_P2/build -j4

$(LIBFT):
		@make -s -C ./Include/LIBFT/

$(OBJ_DIR)%.o: $(SRC_DIR)%.c $(LIB)| $(OBJF)
		@mkdir -p $(dir $@)
		@echo "$(WHITE)Compiling: $(RESET)$(notdir $<)"
		@$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_BONUS_DIR)%.o: $(SRC_BONUS_DIR)%.c | $(OBJF)
		@mkdir -p $(dir $@)
		@echo "$(WHITE)Compiling: $(RESET)$(notdir $<)"
		@$(CC) $(CFLAGS) -c $< -o $@

$(OBJF):
		@mkdir -p $(OBJ_DIR) $(OBJ_BONUS_DIR)

compiling:
		@echo "$(RED)Compiling Cub3D: $(RESET)"

compiling_bonus:
		@echo "$(RED)Compiling Cub3D Bonus: $(RESET)"

clean:
		@rm -rf $(OBJ_DIR)
		@rm -rf $(OBJ_BONUS_DIR)
		@make clean -s -C ./Include/LIBFT/
		@make clean -s -C ./Include/MLX42_P2/build/
		@echo "$(RED)Cleaning Cub3D's objects. $(RESET)"
		@echo

fclean:
		@rm -rf $(OBJ_DIR)
		@rm -rf $(OBJ_BONUS_DIR)
		@rm -rf $(NAME)
		@rm -rf $(NAME)_bonus
		@make fclean -s -C ./Include/LIBFT/
		@make clean -s -C ./Include/MLX42_P2/build/
		@echo "$(RED)Cleaning Cub3D's executables.$(RESET)"

re: fclean all

rebonus: fclean bonus

norm:
		norminette $(SRC_DIR)

.PHONY: all clean fclean re compiling bonus compiling_bonus
