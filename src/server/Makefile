CC	:= gcc

RM	:= rm -rf

LDFLAGS	+= -L. -lpthread -ggdb

CFLAGS	+= -Iinclude -Wall

SRCS	:=  	main.c \
				server.c \
				../common/common.c

OBJS	:= $(SRCS:.c=.o)

NAME	:= ../../bin/Server

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