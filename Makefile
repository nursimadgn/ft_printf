NAME = libftprintf.a
HEADER = ft_printf.h
CC = cc
CFLAGS = -Wall -Wextra -Werror
SRCS = ft_printf.c \
	ft_utils.c \
	ft_utils2.c \

OBJS = $(SRCS:.c=.o)
AR = ar rcs

all: $(NAME)

$(NAME): $(OBJS)
	$(AR) $(NAME) $(OBJS)

%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@


clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re