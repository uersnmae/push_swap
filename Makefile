CC = clang
CFLAGS = -Wall -Wextra -Werror -Iinclude -Isrcs -g

VPATH = srcs:srcs/stack:srcs/push_swap_ops:srcs/checker_bonus:includes
STACK_INC = stack.h
STACK_SRC = 

PUSH_SWAP_INC = $(STACK_INC) push_swap.h
PUSH_SWAP_SRC = $(STACK_SRC)

CHECKER_INC = $(STACK_INC) checker_bonus.h
CHECKER_SRC = $(STACK_SRC)

PUSH_SWAP = push_swap
CHECKER = checker
NAME = $(PUSH_SWAP) $(CHECKER) 

# libft
LIBFT = libft.a
LIBFT_DIR = libft
LIBFT_FILE = $(LIBFT_DIR)/$(LIBFT)
CFLAGS += -I $(LIBFT_DIR)

# ft_printf
FT_PRINTF = ft_printf.a
FT_PRINTF_DIR = libft/ft_printf
FT_PRINTF_FILE = $(FT_PRINTF_DIR)/$(FT_PRINTF)
CFLAGS += -I $(FT_PRINTF_DIR)/includes

all: $(PUSH_SWAP)

bonus: $(CHECKER)

obj:
	mkdir -p obj

LIB = $(LIBFT) $(FT_PRINTF)
PUSH_SWAP_OBJ = $(PUSH_SWAP_SRC:%.c=obj/push_swap/%.o)
CHECKER_OBJ = $(CHECKER_SRC:%.c=obj/checker/%.o)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(FT_PRINTF):
	$(MAKE) -C $(FT_PRINTF_DIR)

$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

lib_clean:
	$(MAKE) clean -C $(LIBFT_DIR)
	$(MAKE) clean -C $(FT_PRINTF_DIR)

lib_fclean:
	$(MAKE) fclean -C $(LIBFT_DIR)
	$(MAKE) fclean -C $(FT_PRINTF_DIR)

clean: lib_clean
	rm -rf $(OBJ_DIR)

fclean: clean lib_fclean
	rm -rf $(NAME)

re: fclean all

.PHONY: all bonus lib_clean lib_fclean clean fclean re
