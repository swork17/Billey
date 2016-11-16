CC	:= gcc

RM	:= rm -rf

LDFLAGS	+= -L. 

CFLAGS	+= -Iinclude

SRCS	:=  src/main.c \
			src/server.c

OBJS	:= $(SRCS:.c=.o)

NAME	:= Billey

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