CC = cc
CFLAGS = -Wall -Wextra -Werror -I/usr/local/include
LIBFT_PRINTF_DIR = ft_printf
LIBFT_PRINTF = $(LIBFT_PRINTF_DIR)/libftprintf.a

SRCS = ft_split.c \
		window.c \
		loop.c \
		map_checker.c \
    	keys.c \
	   	so_long.c \
	   	map.c helper.c \
       	images_loader.c \
		m_animation.c \
		move_check.c \
		flood_fill.c
SRCS_BONUS = bonus_animation_player.c \
		bonus_clean_up.c \
		bonus_display.c \
		bonus_images_loader.c \
		bonus_images_loader_two.c \
		bonus_initialize.c \
		bonus_keys.c \
		bonus_loop.c \
		bonus_map_checker.c \
		bonus_flood_fill.c \
		bonus_map.c \
		bonus_move_check.c \
		bonus_so_long.c \
		bonus_window.c \
		bonus_allocation.c \
		ft_split.c \
		helper.c \
		ft_itoa.c

OBJ = $(SRCS:.c=.o)
OBJ_BONUS = $(SRCS_BONUS:.c=.o)

NAME = so_long

all: $(LIBFT_PRINTF) $(NAME)

$(LIBFT_PRINTF):
	@$(MAKE) -C $(LIBFT_PRINTF_DIR)

$(NAME): $(OBJ) $(LIBFT_PRINTF)
	$(CC) $(OBJ) -L/usr/local/lib -lmlx_Linux -lXext -lX11 $(LIBFT_PRINTF) -o $@ 

bonus: $(LIBFT_PRINTF) $(OBJ_BONUS)
	$(CC) $(OBJ_BONUS) -L/usr/local/lib -lmlx_Linux -lXext -lX11 $(LIBFT_PRINTF) -o $(NAME)

bonus: $(LIBFT_PRINTF) $(OBJ_BONUS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(OBJ_BONUS)
	@$(MAKE) -C $(LIBFT_PRINTF_DIR) clean

fclean: clean
	rm -f $(NAME)
	@$(MAKE) -C $(LIBFT_PRINTF_DIR) fclean

re: fclean all

.PHONY: all clean fclean re bonus
