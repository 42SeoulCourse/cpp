NAME=megaphone

CC=g++
CFLAGS= -Wall -Wextra -Werror
RM=rm -rf

SRC= megaphone.cpp
	
SRC_OBJS=$(SRC:.c=.o)

OBJS= $(SRC_OBJS)

$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

all : $(NAME)

debug :
	$(CC) $(SRC) $(UTILS) -g3  -fsanitize=address -o megaphone

clean :
	$(RM) $(OBJS)

fclean : clean
	$(RM) $(NAME)
	$(RM) megaphone.dSYM

re : fclean all

.PHONY : all clean fclean re