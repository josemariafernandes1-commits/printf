NAME 	= libftprintf.a

CC 		= cc
CFLAGS 	= -Wall -Wextra -Werror
FNCTS 	= ft_printf.c \
			ft_handle_c.c \
			ft_handle_s.c \
			ft_handle_void_hex.c \
			ft_handle_di_base10.c \
			ft_handle_u_base10.c \
			ft_handle_hex.c


OUTPUTS = $(FNCTS:.c=.o)

all: $(NAME)

$(NAME): $(OUTPUTS)
	ar rcs $(NAME) $(OUTPUTS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean: 
	rm -f $(OUTPUTS)

fclean: 
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
