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

NAME		= libmy.a

all:		$(NAME)

$(NAME):	$(OBJS)
			ar rcs $(NAME) $(OBJS)
			ranlib $(NAME)

clean:
			$(RM) $(OBJS)

fclean:		clean
			$(RM) $(NAME)

re:			fclean $(NAME)

.PHONY:		all clean fclean re