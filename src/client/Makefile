CC	:= gcc

RM	:= rm -rf

LDFLAGS	+= -L. 

CFLAGS	+= -Iinclude

SRCS	:= main.c

OBJS	:= $(SRCS:.c=.o)

NAME	:= ../../bin/Client

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) -o $(NAME) $(OBJS) $(LDFLAGS)

clean:
	$(RM) $(OBJS)
	$(RM) *~

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all re clean fclean