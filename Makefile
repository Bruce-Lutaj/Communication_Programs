SERVER_NAME = server
CLIENT_NAME = client

CC = cc
HEADERS = ./Libft/Headers
CFLAGS = -Wextra -Werror -Wall -g -I$(HEADERS)
RM = rm -f

LIBFT_MAKE = ./Libft

SERVER_SRC =	server.c

CLIENT_SRC =	client.c

all: $(SERVER_NAME) $(CLIENT_NAME)

$(SERVER_NAME): $(SERVER_SRC)
	@make all -s -C $(LIBFT_MAKE)
	$(CC) $(FLAGS) -I. -I$(HEADERS) $(SERVER_SRC) -L$(LIBFT_MAKE) -lft -o $(SERVER_NAME)

$(CLIENT_NAME): $(CLIENT_SRC)
	@make all -s -C $(LIBFT_MAKE)
	$(CC) $(FLAGS) -I. -I$(HEADERS) $(CLIENT_SRC) -L$(LIBFT_MAKE) -lft -o $(CLIENT_NAME)

clean:
	@make clean -s -C $(LIBFT_MAKE)

fclean: clean
	@make fclean -s -C $(LIBFT_MAKE)
	@$(RM) $(SERVER_NAME) $(CLIENT_NAME)

re: fclean all

# .SILENT:
.PHONY: all clean fclean re