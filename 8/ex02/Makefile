#==============================================================
# DECLARATION
#==============================================================

NAME = mutant_stack
CC = c++
CFLAGS = -Wall -Wextra -Werror -Wshadow -std=c++98

GREEN = \033[1;32m
RESET = \033[0m

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
	@echo "$(GREEN)program name ->$(RESET) ./$(NAME)"
	
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
