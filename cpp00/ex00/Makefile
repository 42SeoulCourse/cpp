NAME=megaphone

CXX=g++
CXXFLAGS= -Wall -Wextra -Werror -std=c++98
RM=rm -rf

SRC= megaphone.cpp
	
SRC_OBJS=$(SRC:.cpp=.o)

OBJS= $(SRC_OBJS)

$(NAME) : $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

all : $(NAME)

debug :
	$(CXX) $(SRC) $(UTILS) -g3  -fsanitize=address -o megaphone

clean :
	$(RM) $(OBJS)

fclean : clean
	$(RM) $(NAME)
	$(RM) megaphone.dSYM

re : fclean all

.PHONY : all clean fclean re