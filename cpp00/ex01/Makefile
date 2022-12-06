NAME=phonebook

CC=g++
CFLAGS= -Wall -Wextra -Werror
RM=rm -rf

SRC= main.cpp
CLASS= PhoneBook.class.cpp \
	   Contact.class.cpp
	
SRC_OBJS=$(SRC:.c=.o)
CLASS_OBJS=$(CLASS:.c=.o)

OBJS= $(SRC_OBJS) $(CLASS_OBJS)

$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

all : $(NAME)

debug :
	$(CC) -g3 $(SRC) $(CLASS) -o megaphone

clean :
	$(RM) $(OBJS)

fclean : clean
	$(RM) $(NAME)
	$(RM) megaphone.dSYM

re : fclean all

.PHONY : all clean fclean re