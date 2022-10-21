REP			= .
TEST_REP	= ./tests

# sources de la librarie
FILE_SRC	= \
	my_is_alpha \
	my_is_digit\
	my_is_alpha_num\
	my_strlen\
	my_putstr\
	my_count_words\
	my_split\
	my_tolower\
	my_toupper\
	my_strcmp\
	my_strncmp\
	my_strcpy\
	my_strncpy\
	my_strlcpy\
	my_strcat\
	my_strncat\
	my_strlcat\
	my_memcpy\
	my_is_alpha\
	my_is_digit\
	my_is_alpha_num\
	my_strlen\
	my_putstr\
	my_count_words\
	my_split\
	my_tolower\
	my_toupper\
	my_strcmp\
	my_strncmp\
	my_strcpy\
	my_strncpy\
	my_strlcpy\
	my_strcat\
	my_strncat\
	my_strlcat\
	my_memcpy \
	my_memset \
	my_strnlen

SRC = $(addprefix $(REP)/,$(addsuffix .c,$(FILE_SRC)))
SRC_COV = \
	$(addprefix $(REP)/,$(addsuffix .gcno,$(FILE_SRC))) \
	$(addprefix $(REP)/,$(addsuffix .gcda,$(FILE_SRC)))

RES_COV = \
	$(addprefix $(REP)/,$(addsuffix .c.gcov,$(FILE_SRC)))

FILE_TEST = \
	main \
  test_my_is_alpha \
  test_my_is_digit \
  test_my_is_alpha_num \
  test_my_strlen \
  test_my_putstr \
  test_my_count_words \
  test_my_split \
  test_my_strcat \
  test_my_strncat \
  test_my_tolower \
  test_my_toupper \
  test_my_strcmp \
  test_my_strncmp \
  test_my_strcpy \
  test_my_strncpy \
  test_my_strlcat \
  test_my_strlcpy \
  test_my_memcpy \
  test_my_memset \
	test_my_strnlen

SRC_TEST = $(addprefix $(TEST_REP)/,$(addsuffix .c,$(FILE_TEST)))

RM			= rm -f

CC			?= gcc

OBJS		= $(SRC:.c=.o)

OBJS_TEST	= $(SRC_TEST:.c=.o)

# flags de warning
CFLAGS		+= -Wall -Wextra -Werror -Wno-newline-eof
CFLAGS		+= -ansi -pedantic
CFLAGS		+= -fprofile-arcs -ftest-coverage

# options pour gdb / valgrind
CFLAGS		+= -O0 -gdwarf-4

# force gcc a compiler en gnu99
CFLAGS		+= -std=gnu99

# association du path des fichiers header 
CFLAGS		+= -I./includes

# flags pour compiler la library bsd
BSD_FLAGS	+= -lbsd

# flag pour associer la librarie static libmy.a aux projets de tests
LDFLAGS		+= -L. -lmy

# flags pour compiler avec check.h
TEST_FLAGS	+= -lcheck -lm -lpthread -lrt -lsubunit

NAME		= libmy.a

TEST_NAME	= check_tests

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)
	ranlib $(NAME)

$(TEST_NAME):	$(OBJS_TEST) $(NAME)
	$(CC) -o $@ $(OBJS_TEST) $(CFLAGS) $(LDFLAGS) $(TEST_FLAGS) $(BSD_FLAGS)

# cover:
# 	${MAKE} ${TEST_NAME} CFLAGS="${CFLAGS} -fprofile-arcs -ftest-coverage"

clean: ## Remove .o
	@ $(RM) $(OBJS)	$(SRC_COV) $(RES_COV)

fclean:	clean ## Run clean and remove compiled library
	$(RM) $(NAME)

re:	fclean all

test:	$(TEST_NAME)

%.c.gcov: $(TEST_NAME)
	./%<

cover: $(TEST_NAME)	 ## Generate cover, Please compile w/ gcc
	gcov *.c

clean\:test:
	$(RM) $(OBJS_TEST) ./$(TEST_REP)/*.gcno ./$(TEST_REP)/*.gcda ./$(TEST_REP)/*.c.gcov

fclean\:test: clean\:test
	$(RM) $(TEST_NAME)

test\:re:	fclean\:test $(TEST_NAME)


.PHONY:		all clean fclean re

.PHONY:		help
help: ## Display this help screen
	@echo "Usage: \n"
	@grep -h -E '^[a-zA-Z\.\-_-]+:.*?## .*$$' $(MAKEFILE_LIST) | \
		awk 'BEGIN {FS = ":.*?## "}; {printf "  \033[36m%-30s\033[0m %s\n", $$1, $$2}'
