NAME 			=	cub3D

CC				=	gcc
FLAGS			=	-Wall -Wextra -Werror

SRC				=	./src/display/print_sprites.c \
					./src/error/error_message.c \
					./src/error/free_tmap.c \
					./src/setarguments/part_one.c \
					./src/setarguments/part_two.c \
					./src/setarguments/set_arg.c \
					./src/utils/utils.c \
					./src/main.c \

LIBFT_PATH		=	./libft
LIBFT			=	$(LIBFT_PATH)/libft.a

all : $(NAME)

$(NAME):	$(LIBFT)
	@$(CC) $(FLAGS) $(SRC) $(LIBFT) -o $(NAME)

$(LIBFT):
		@make -C $(LIBFT_PATH) all

clean:
	@make -C $(LIBFT_PATH) clean

fclean:
	@make -C $(LIBFT_PATH) fclean
	@rm -f $(NAME)

re: fclean all

e:
	@rm -rf $(NAME)
	@$(CC) $(FLAGS) $(SRC) $(LIBFT) -o $(NAME)

r:
	@./$(NAME) dosya.cub

ee: e r

.PHONY : all clean fclean re e