GREEN	= \033[0;32m
CYAN	= \033[0;36m
RED		= \033[0;31m
NC		= \033[0m
ORANGE	= \033[38;5;214m


COMPILER = cc
CFLAGS = -Wall -Wextra -Werror -fsanitize=address -I$(INC_DIR) -Ilibft -Ift_printf

INC_DIR = inc/
SRC_DIR = src/
LIBFT_DIR = libft/
FT_PRINTF_DIR = ft_printf/

SERVER_FILES = server.c
CLIENT_FILES = client.c
BONUS_FILES = server_bonus.c client_bonus.c

SERVER_SRCS = $(addprefix $(SRC_DIR), $(SERVER_FILES))
CLIENT_SRCS = $(addprefix $(SRC_DIR), $(CLIENT_FILES))
SERVER_OBJS = $(SERVER_SRCS:.c=.o)
CLIENT_OBJS = $(CLIENT_SRCS:.c=.o)

CLIENT = client
SERVER = server

LIBFT = $(LIBFT_DIR)libft.a
FT_PRINTF = $(FT_PRINTF_DIR)libftprintf.a


all: $(LIBFT) $(FT_PRINTF) $(SERVER) $(CLIENT)

$(LIBFT):
	@echo "$(CYAN)Compiling libft...$(NC)"
	$(MAKE) -C libft

$(FT_PRINTF):
	@echo "$(CYAN)Compiling ft_printf...$(NC)"
	$(MAKE) -C ft_printf

$(SERVER): $(SERVER_OBJS)
	@echo "$(CYAN)Compiling $(SERVER)...$(NC)"
	$(COMPILER) $(CFLAGS) -o $(SERVER) $(SERVER_OBJS) $(LIBFT) $(FT_PRINTF)
	@echo "$(GREEN)$(SERVER) compiled successfully! ✅$(NC)"

$(CLIENT): $(CLIENT_OBJS)
	@echo "$(CYAN)Compiling $(CLIENT)...$(NC)"
	$(COMPILER) $(CFLAGS) -o $(CLIENT) $(CLIENT_OBJS) $(LIBFT) $(FT_PRINTF)
	@echo "$(GREEN)$(CLIENT) compiled successfully! ✅$(NC)"

bonus: all

clean:
	@echo "$(ORANGE)Cleaning object files... 🧹$(NC)"
	rm -rf $(SERVER_OBJS) $(CLIENT_OBJS) $(OBJS_BONUS)
	@$(MAKE) -C libft clean
	@$(MAKE) -C ft_printf clean

fclean: clean
	@echo "$(ORANGE)Removing binaries... 🗑️$(NC)"
	rm -rf $(SERVER) $(CLIENT) $(BONUS)
	@$(MAKE) -C libft fclean
	@$(MAKE) -C ft_printf fclean

re: fclean all

.PHONY: all clean fclean re start_server start_client
