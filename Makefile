REP			= .
TEST_REP	= ./tests

# sources de la librarie
SRC			+= $(REP)/my_is_alpha.c
SRC			+= $(REP)/my_is_digit.c
SRC			+= $(REP)/my_is_alpha_num.c
SRC			+= $(REP)/my_strlen.c
SRC			+= $(REP)/my_putstr.c
SRC			+= $(REP)/my_count_words.c
SRC			+= $(REP)/my_split.c
SRC			+= $(REP)/my_strncat.c
SRC			+= $(REP)/my_strcat.c
SRC			+= $(REP)/my_tolower.c
SRC			+= $(REP)/my_toupper.c
SRC			+= $(REP)/my_strcmp.c
SRC			+= $(REP)/my_strncmp.c

# sources des tests unitaires
SRC_TEST	+= $(TEST_REP)/main.c
SRC_TEST	+= $(TEST_REP)/test_my_is_alpha.c
SRC_TEST	+= $(TEST_REP)/test_my_is_digit.c
SRC_TEST	+= $(TEST_REP)/test_my_is_alpha_num.c
SRC_TEST	+= $(TEST_REP)/test_my_strlen.c
SRC_TEST	+= $(TEST_REP)/test_my_putstr.c
SRC_TEST	+= $(TEST_REP)/test_my_count_words.c
SRC_TEST	+= $(TEST_REP)/test_my_split.c
SRC_TEST	+= $(TEST_REP)/test_my_strcat.c
SRC_TEST	+= $(TEST_REP)/test_my_strncat.c
SRC_TEST	+= $(TEST_REP)/test_my_tolower.c
SRC_TEST	+= $(TEST_REP)/test_my_toupper.c
SRC_TEST	+= $(TEST_REP)/test_my_strcmp.c
SRC_TEST	+= $(TEST_REP)/test_my_strncmp.c

RM			= rm -f

CC			= gcc

OBJS		= $(SRC:.c=.o)

OBJS_TEST	= $(SRC_TEST:.c=.o)

# flags de warning
CFLAGS		+= -Wall -Wextra -Werror
CFLAGS		+= -ansi -pedantic

# options pour gdb / valgrind
CFLAGS		+= -O0 -g3

# force gcc a compiler en gnu99
CFLAGS		+= -std=gnu99

# association du path des fichiers header 
CFLAGS		+= -I./includes

# flag pour associer la librarie static libmy.a aux projets de tests
LDFLAGS		+= -L. -lmy

# flags pour compiler avec check.h
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