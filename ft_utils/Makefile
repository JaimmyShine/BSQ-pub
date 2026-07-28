NAME = libft_utils.a

CC = cc

CFLAGS = -Wall -Wextra -Werror

INCLUDE = -Iinclude

SRC_DIR = src

SRC = ft_putchar.c \
	  ft_putstr.c \
	  ft_puterr.c \
	  ft_strlen.c \
	  ft_strcmp.c \
	  ft_split.c \
	  ft_strdup.c \
	  ft_strncpy.c \
	  ft_atoi.c \
	  ft_str_is_numeric.c \
	  ft_str_is_printable.c

SRCPATH = $(SRC:%=$(SRC_DIR)/%)

OBJ = $(SRCPATH:.c=.o)

all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDE) -c -o $@ $<

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
