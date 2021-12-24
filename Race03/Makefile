CFLAGS := -std=c11 -Wall -Wextra -Werror -Wpedantic -lncurses
NAME := matrix_rain

all: $(NAME)

$(NAME):
	clang $(CFLAGS) -Iinc -o $(NAME) src/*.c

clean:
	rm -rf ./obj

uninstall: clean
	rm -rf $(NAME)

reinstall:
	make uninstall
	make