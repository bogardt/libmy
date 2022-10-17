REP			= .
TEST_REP	= ./tests

SRC			+= $(REP)/my_is_alpha.c
SRC			+= $(REP)/my_is_digit.c
SRC			+= $(REP)/my_putstr.c
SRC			+= $(REP)/my_split.c
SRC			+= $(REP)/my_strlen.c

SRC_TEST	+= $(TEST_REP)/main.c
SRC_TEST	+= $(TEST_REP)/test_my_is_alpha.c
SRC_TEST	+= $(TEST_REP)/test_my_is_digit.c

RM			= rm -f

CC			= gcc

OBJS		= $(SRC:.c=.o)

OBJS_TEST	= $(SRC_TEST:.c=.o)

CFLAGS		+= -Wall -Wextra -Werror
CFLAGS		+= -ansi -pedantic
CFLAGS		+= -O0 -g3
CFLAGS		+= -I./includes
CFLAGS		+= -std=gnu99

LDFLAGS		+= -L. -lmy

TEST_FLAGS	+= -lcheck -lm -lpthread -lrt -lsubunit

NAME		= libmy.a

TEST_NAME	= check_tests

all:		$(NAME)

$(NAME):	$(OBJS)
			ar rcs $(NAME) $(OBJS)
			ranlib $(NAME)

$(TEST_NAME):	$(OBJS_TEST)
				$(CC) -o $(TEST_NAME) $(OBJS_TEST) $(CFLAGS) $(LDFLAGS) $(TEST_FLAGS)

clean:
			$(RM) $(OBJS)

fclean:		clean
			$(RM) $(NAME)

re:			fclean $(NAME)

test:		$(TEST_NAME)

clean_test:
			$(RM) $(OBJS_TEST)

fclean_test: clean_test
			$(RM) $(TEST_NAME)

re_test:	fclean_test $(TEST_NAME)


.PHONY:		all clean fclean re