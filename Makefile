NAME		= lem-in

CC			= gcc
FLAGS		= -Wall -Wextra -g

LIB_PATH	= libft/
LIB			= $(LIB_PATH)libft.a
LIB_LINK	= -L $(LIB_PATH) -lft

INCLUDES	= -I $(LIB_PATH)includes -I includes

SRCS		= src/lemin.c \
			  src/lst.c \
			  src/pile_pathes.c \
			  src/hash.c \
			  src/init.c \
			  src/parsing.c \
			  src/parse_room.c \
			  src/parse_link.c \
			  src/error.c \
			  src/resolve.c \
			  src/use_pathes.c \

OBJS 		= $(SRCS:src/%.c=obj/%.o)



all: obj $(NAME)

$(NAME): $(LIB) $(OBJS)
	$(CC) $(FLAGS) $(LIB_LINK) -o $@ $^

$(LIB):
	@make -C $(LIB_PATH)

obj:
	mkdir -p obj

obj/%.o: src/%.c includes/lemin.h
	$(CC) $(FLAGS) $(INCLUDES) -c -o $@ $<

clean:
	@rm -f $(OBJS)
	@rm -rf obj
	@echo "all obects removed"

fclean_lib:
	@make fclean -C $(LIB_PATH)

fclean: clean fclean_lib
	@rm -f $(NAME)
	@echo "binary removed"

re: fclean all

.PHONY: all clean fclean re fclean_lib
