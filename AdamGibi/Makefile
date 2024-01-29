NAME    =   cub3D
CC      =   gcc
FLAGS   =   #-Wall -Wextra -Werror
SRC_DIR =	./src
OBJ_DIR =	./obj

SRC		=	$(SRC_DIR)/check_map.c \
			$(SRC_DIR)/checkMapCharacters.c \
			$(SRC_DIR)/copyMap.c \
			$(SRC_DIR)/error_message.c \
			$(SRC_DIR)/set_map_values.c \
			$(SRC_DIR)/setMap.c \
			$(SRC_DIR)/print.c \
			$(SRC_DIR)/utils.c \


OBJS	=	$(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(SRC))
MAIN	=	$(SRC_DIR)/main.c

LIBFT_PATH	=	./libft
LIBFT		=	$(LIBFT_PATH)/libft.a

all:    			$(NAME)
$(NAME):			$(MAIN) $(LIBFT) $(OBJS)
					@mkdir -p ./bin
					$(CC) $(FLAGS) $^ -o ./bin/$@

$(OBJ_DIR)/%.o: 	$(SRC_DIR)/%.c
					@mkdir -p $(OBJ_DIR)
					$(CC) $(FLAGS) -c $< -o $@

$(LIBFT):
		@make -C $(LIBFT_PATH) all

clean:
					@make -C $(LIBFT_PATH) re
					rm -rf $(OBJ_DIR) $(MAIN_EXECUTABLE)

fclean:				clean
					rm -rf ./bin

re:					fclean all
.PHONY:				all clean fclean re