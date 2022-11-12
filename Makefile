NAME = philo
CC = cc
CFLAGS = -Wall -Wextra -Werror -I./inc

OBJS_DIR = obj
SRCS = $(wildcard src/*.c)
OBJS = $(patsubst src/%.c, $(OBJS_DIR)/%.o, $(SRCS))

MK = mkdir -p
RM = rm -f
RMRF = rm -rf

LIBCACH = ~/Library/Caches/

COLOUR_GREEN=\033[0;32m
COLOUR_RED=\033[0;31m
COLOUR_NEW=\033[0;36m
COLOUR_END=\033[0m

$(OBJS_DIR)/%.o: ./src/%.c | $(OBJS_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJS)
	@echo "$(COLOUR_GREEN)COMPILED😍$(COLOUR_END)"

$(OBJS_DIR):
	@$(MK) $(OBJS_DIR)

clean:
	@$(RMRF)	$(OBJS_DIR)
	@echo "$(COLOUR_RED)CLEANED🤨$(COLOUR_END)"

fclean: clean
	@$(RM)  $(NAME)
	@$(RMRF) $(LIBCACH)
	@echo "$(COLOUR_NEW)THANK YOU😘$(COLOUR_END)"

re: fclean all

.PHONY: all clean fclean re