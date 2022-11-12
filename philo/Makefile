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

$(OBJS_DIR)/%.o: ./src/%.c | $(OBJS_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

$(OBJS_DIR):
	$(MK) $(OBJS_DIR)

clean:
	$(RMRF)	$(OBJS_DIR)

fclean: clean
	$(RM)  $(NAME)
	$(RMRF) $(LIBCACH)

re: fclean all

.PHONY: all clean fclean re