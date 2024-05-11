NAME = RPN

CXX = c++

CPPFLAGS = -Wall -Werror -Wextra -std=c++98 -fsanitize=address 

RM = rm -rf

SRCS = main.cpp RPN.cpp

OBJS = $(SRCS:%.cpp=%.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CPPFLAGS) $(OBJS) -o $(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all