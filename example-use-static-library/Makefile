REP			= .

SRC			= $(REP)/$(wildcard *.c)

RM			= rm -f

CC			= gcc

OBJS		= $(SRC:.c=.o)

CFLAGS		+= -Wall -Wextra -Werror
CFLAGS		+= -ansi -pedantic
CFLAGS		+= -O0 -g3
CFLAGS		+= -I./includes
CFLAGS		+= -std=gnu99

LDFLAGS		+= -L. -lmy

NAME		= binary

all:		$(NAME)

$(NAME):	$(OBJS)
			$(CC) -o $(NAME) $(OBJS) $(CFLAGS) $(LDFLAGS)
clean:
			$(RM) $(OBJS)

fclean:		clean
			$(RM) $(NAME)

re:			fclean $(NAME)

.PHONY:		all clean fclean re