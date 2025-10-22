#==============================================================
# DECLARATION
#==============================================================

NAME = re_brain
CC = c++
CFLAGS = -Wall -Wextra -Werror -Wshadow -std=c++98

#==============================================================
# FILES
#==============================================================

SRCS =	$(wildcard *.cpp)

OBJS = $(SRCS:.cpp=.o)

#==============================================================
# BUILD COMMAND
#==============================================================

all: $(NAME)

$(NAME): $(OBJS) 
	$(CC) $(CFLAGS) -o $@ $^
	
%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

leak: $(NAME)
	valgrind --leak-check=full ./$(NAME)

clean:
	rm -f $(OBJS) 

fclean: clean
	rm -f $(NAME) 

re: fclean all

.PHONY: all leak clean fclean re
