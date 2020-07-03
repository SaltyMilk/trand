NAME= libtrand.a
CC= gcc
SRC= trand.c
OBJ= $(SRC:.c=.o)
CFLAG= -c -Wextra -Werror

DEF_THREAD=19

all: $(NAME)

$(NAME): $(OBJ)
	ar -rc $(NAME) $(OBJ)

%.o: %.c
	$(CC) $(CFLAG) -D DEF_THREAD=$(DEF_THREAD) $?

clean:
	rm -f $(OBJ)
fclean:
	rm -f $(OBJ) $(NAME)

re : fclean all

