GREEN = \033[0;32m
RED = \033[31m
BLUE = \033[34m
YELLOW = \033[33m
RESET = \033[0m

NAME = fractol
NAME_BONUS = fractol_bonus

CC = cc
CFLAGS = -Werror -Wextra -Wall

INCLUDE = includes

#LIBFT
LIBFT_DIR =	includes/libft/
LIBFT_NAME = libft.a
LIBFT = $(LIBFT_DIR)$(LIBFT_NAME)

OBJ_DIR = 		obj

#MLX
# MLX_DIR = minilibx-linux/
# MLX_NAME = libmlx.a
# MLX = $(MLX_DIR)$(MLX_NAME)

SRCS = srcs/draw.c \
	   srcs/fractol.c \
	   srcs/julia.c \
	   srcs/init.c \
	   srcs/mandelbrot.c \
	   srcs/ft_atof.c \
	   srcs/ft_strcmp.c \
	   srcs/utils.c

OBJS = srcs/draw.o \
	   srcs/fractol.o \
	   srcs/julia.o \
	   srcs/init.o \
	   srcs/mandelbrot.o \
	   srcs/ft_atof.o \
	   srcs/ft_strcmp.o \
	   srcs/utils.o

SRCS_BONUS = srcs_bonus/draw_bonus.c \
		srcs_bonus/fractol_bonus.c \
		srcs_bonus/julia_bonus.c \
		srcs_bonus/init_bonus.c \
		srcs_bonus/mandelbrot_bonus.c \
		srcs_bonus/ft_atof_bonus.c \
		srcs_bonus/ft_strcmp_bonus.c \
	   	srcs_bonus/utils_bonus.c \
		srcs_bonus/burning_ship_bonus.c

OBJS_BONUS = srcs_bonus/draw_bonus.o \
		srcs_bonus/fractol_bonus.o \
		srcs_bonus/julia_bonus.o \
		srcs_bonus/init_bonus.o \
		srcs_bonus/mandelbrot_bonus.o \
		srcs_bonus/ft_atof_bonus.o \
		srcs_bonus/ft_strcmp_bonus.o \
	   	srcs_bonus/utils_bonus.o \
		srcs_bonus/burning_ship_bonus.o

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT) $(INCLUDE)
	$(CC) $(CFLAGS) -I$(INCLUDE) -L$(LIBFT_DIR) \
		-o $(NAME) $(OBJS) $(LIBFT) -Lminilibx-linux -lm -lX11 -lmlx -lXext
	@echo "$(RESET)$(GREEN) $(NAME) ready$(RESET)."

bonus: $(NAME_BONUS)

$(NAME_BONUS):  $(OBJS_BONUS) $(LIBFT)
	$(CC) $(CFLAGS) -I$(MLX_DIR) -L$(MLX_DIR) -I$(INCLUDE) -L$(LIBFT_DIR) \
		-o $(NAME_BONUS) $(OBJS_BONUS) $(LIBFT) -lm -lX11 -lmlx -lXext
	@echo "$(GREEN) $(NAME_BONUS) erstellt$(RESET)."

$(LIBFT):
	@$(MAKE) -sC $(LIBFT_DIR)
	@echo "$(BLUE)LIBFT created$(RESET)"

clean:
	rm -rf $(OBJS)
	rm -rf $(OBJS_BONUS)
	@$(MAKE) clean -C $(LIBFT_DIR)
	@echo "$(RED) Objektdateien gelöscht.$(RESET)"

fclean: clean
	rm -f $(NAME)
	rm -rf $(NAME_BONUS)
	rm -f $(LIBFT_DIR)$(LIBFT_NAME)
	@echo "$(RED) $(NAME) gelöscht.$(RESET)"

re: fclean all

.PHONY: all clean fclean re bonus
