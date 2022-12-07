NAME=phonebook

CXX=c++
CXXFLAGS= -Wall -Wextra -Werror -std=c++98
RM=rm -rf

SRC= main.cpp
CLASS= PhoneBook.class.cpp \
	   Contact.class.cpp
	
SRC_OBJS=$(SRC:.cpp=.o)
CLASS_OBJS=$(CLASS:.cpp=.o)

OBJS= $(SRC_OBJS) $(CLASS_OBJS)

$(NAME) : $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

all : $(NAME)

debug :
	$(CXX) $(SRC) $(CLASS) -g3 -o megaphone

clean :
	$(RM) $(OBJS)

fclean : clean
	$(RM) $(NAME)
	$(RM) phonebook.dSYM

re : fclean all

.PHONY : all clean fclean re