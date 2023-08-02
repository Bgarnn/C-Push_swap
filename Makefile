NAME	=	push_swap

CC	=	cc

CFLAGS	=	-Wall -Wextra -Werror -I$(DIR_INC) -I$(LIBFT_DIR)

SRCS	=	push_swap.c input_get.c ft_lst.c sort_check_and_simple.c swap_ab.c ft_action.c\

DIR_INC	=	include
DIR_SRC	=	src

LIBFT	=	libft/libft.a
LIBFT_DIR	=	libft/

RM	=	rm -rf

$(NAME):
	@make -C libft
	@$(CC) $(CFLAGS) $(addprefix $(DIR_SRC)/, $(SRCS)) $(LIBFT) -o $(NAME)

.PHONY: all clean fclean re norm
all: $(NAME)

clean:
		@$(RM) $(NAME)
		@make clean -C libft


fclean:
		@$(RM) $(NAME)
		@make fclean -C libft

re: fclean all