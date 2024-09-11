NAME_SERVER = ./server/server
NAME_CLIENT = ./client/client
User = $(shell whoami)

CC = $(shell which clang gcc cc | head -n 1)
CFLAGS = -Wall -Wextra -Werror -g
AR = ar rcs
RM = rm -f

SRC_SERVER = ./server/server.c
SRC_CLIENT = ./client/client.c
SRC_UTILS = ./utils/utils.c

OBJ_SERVER = $(SRC_SERVER:.c=.o)
OBJ_CLIENT = $(SRC_CLIENT:.c=.o)
OBJ_UTILS = $(SRC_UTILS:.c=.o)

# Reglas
all: $(NAME_SERVER) $(NAME_CLIENT)
	@echo "$(GREEN) Compiling: ........ OK $<"

$(NAME_SERVER): $(OBJ_SERVER) $(OBJ_UTILS)
	@echo "$(CYAN) Compiling: ........ OK"
	$(CC) $(CFLAGS) $(SRC_SERVER) $(SRC_UTILS) -o $(NAME_SERVER)
	@echo "$(YELLOW) Server was successfully created."

$(NAME_CLIENT): $(OBJ_CLIENT) $(OBJ_UTILS)
	@echo "$(CYAN) Compiling: ........ OK"
	$(CC) $(CFLAGS) $(SRC_CLIENT) $(SRC_UTILS) -o $(NAME_CLIENT)
	@echo "$(BLUE) Client was successfully created."

clean:
	@echo "$(MAGENTA) Removing *****.o:"
	$(RM) $(OBJ_SERVER) $(OBJ_CLIENT) $(OBJ_UTILS)
	@echo "$(RED) Object fully cleaned.$(DEFAULT)"

fclean: clean
	@echo "$(MAGENTA) Removing ********* executables files:"
	$(RM) $(NAME_SERVER) $(NAME_CLIENT)
	@echo "$(GREEN)Cleaned execute.$(DEFAULT)"

re: fclean all
	@echo "$(BOLD)Cleaned .$(DEFAULT)"

.PHONY: all clean fclean re
	@echo "$(PINK).PHONY Cleaned.$(DEFAULT)"

#COLORS
BOLD	:= \033[1m
BLACK	:= \033[30;1m
RED		:= \033[31;1m
GREEN	:= \033[32;1m
YELLOW	:= \033[33;1m
BLUE	:= \033[34;1m
MAGENTA	:= \033[35;1m
CYAN	:= \033[36;1m
WHITE	:= \033[37;1m
PINK	:= \033[38;5;206m
purple	:= \033[38;5;57m
DEFAULT	:= \033[0m