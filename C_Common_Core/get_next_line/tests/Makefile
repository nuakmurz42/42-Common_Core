NAME = gnl_tester
STDIN_NAME = test_stdin

CC = cc
CFLAGS = -Wall -Wextra -Werror

BUFFER_SIZE ?= 42

SRC = main.c \
      runner.c

GNL_SRC = ../get_next_line.c \
          ../get_next_line_utils.c

HEADERS = test_gnl.h \
          ../get_next_line.h

all: $(NAME)

$(NAME): $(SRC) $(GNL_SRC) $(HEADERS) FORCE
	$(CC) $(CFLAGS) -D BUFFER_SIZE=$(BUFFER_SIZE) $(SRC) $(GNL_SRC) -o $(NAME)

test_stdin: test_stdin.c $(GNL_SRC) ../get_next_line.h FORCE
	$(CC) $(CFLAGS) -D BUFFER_SIZE=$(BUFFER_SIZE) test_stdin.c $(GNL_SRC) -o $(STDIN_NAME)

clean:
	rm -f $(NAME) $(STDIN_NAME)

fclean: clean

re: fclean all

run: all
	./$(NAME)

valgrind: all
	valgrind \
		--leak-check=full \
		--show-leak-kinds=all \
		--track-origins=yes \
		./$(NAME)

FORCE:

.PHONY: all clean fclean re run valgrind test_stdin FORCE
