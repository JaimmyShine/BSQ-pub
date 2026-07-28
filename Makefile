NAME = bsq

CC = cc

CFLAGS = -Wall -Wextra -Werror

INCLUDE = -Iinclude -Ift_utils/include

SRC_DIR = src

SRC = main.c

SRCPATH = $(SRC:%=$(SRC_DIR)/%)

OBJ = $(SRCPATH:.c=.o)

LIBFT_UTILS = ft_utils/libft_utils.a

all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDE) -c -o $@ $<

$(NAME): $(OBJ) $(LIBFT_UTILS)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT_UTILS) -o $(NAME)

$(LIBFT_UTILS):
	make -C ft_utils

clean:
	make -C ft_utils clean
	rm -f $(OBJ)

fclean: clean
	make -C ft_utils fclean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
