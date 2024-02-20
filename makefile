NAME		=	so_long

CC			=	clang

FLAG		=	-Wall -Wextra -Werror -g3

LIBFT_PATH  =	./libft/

LIBFT_FILE  =	libft.a

MLX_PATH    =	./mlx/

MLX_FILE    =	libmlx.a

GNL_PATH    =	./get_next_line/

GNL_FILE    =	libgnl.a 

LIBFT_LIB   = $(addprefix $(LIBFT_PATH), $(LIBFT_FILE))
MLX_LIB     = $(addprefix $(MLX_PATH), $(MLX_FILE))
GNL_LIB     = $(addprefix $(GNL_PATH), $(GNL_FILE))

MLX_EX      = $(MLX_LIB) -lX11 -lXext -lbsd
GNL_EX      = $(GNL_LIB)

C_FILE		=	messages.c main.c init.c Map/ft_split.c Map/checkmap.c win.c \
					Map/checkmap_utils.c Graphique/event.c Graphique/mlx_utils.c \

INC_DIR		=	./includes/

SRC			=	$(C_FILE)

OBJ			=	$(SRC:.c=.o)

.c.o:
	$(CC) $(FLAG) -c $< -o $@

all: $(NAME)

lib:
	@echo "\033[0;33m\nCOMPILING $(LIBFT_PATH)\n"
	@make -C $(LIBFT_PATH)
	@echo "\033[1;32mLIBFT_lib created\n"

mlx:
	@echo "\033[0;33m\nCOMPILING $(MLX_PATH)...\n"
	@make -sC $(MLX_PATH)
	@echo "\033[1;32mMLX_lib created\n"

gnl:
	@echo "\033[0;33m\nCOMPILING $(GNL_PATH)...\n"
	@make -sC $(GNL_PATH)
	@echo "\033[1;32mGNL_lib created\n"

$(NAME): lib mlx gnl $(OBJ)
	@echo "\033[0;33m\nCOMPILING SO_LONG...\n"
	$(CC) $(OBJ) $(LIBFT_LIB) $(MLX_EX) $(GNL_EX) -o $(NAME)
	@echo "\033[1;32m./so_long created\n"

clean:
	@echo "\033[0;31mDeleting Obj file in $(MLX_PATH)...\n"
	@make clean -sC $(MLX_PATH)
	@echo "\033[0;31mDeleting Obj file in $(LIBFT_PATH)...\n"
	@make clean -sC $(LIBFT_PATH)
	@echo "\033[0;31mDeleting Obj file in $(GNL_PATH)...\n"
	@make clean -sC $(GNL_PATH)
	@echo "\033[1;32mDone\n"
	@echo "\033[0;31mDeleting So_long object...\n"
	@rm -f $(OBJ)
	@echo "\033[1;32mDone\n"

fclean: clean
	@echo "\033[0;31mDeleting so_long executable..."
	@rm -f $(NAME)
	@make fclean -C $(LIBFT_PATH)
	@echo "\033[0;31mDeleting GNL library..."
	@rm -f $(GNL_LIB)
	@echo "\033[1;32mDone\n"

re: fclean all

.PHONY: all clean fclean re
