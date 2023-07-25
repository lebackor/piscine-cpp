SRCS =	main.cpp\
		PmergeMe.cpp

NAME = PmergeMe

CC			=	clang++
INCLUDES	=	includes
CPPFLAGS	=	-Wall -Werror -Wextra -I$(INCLUDES) -std=c++98 -fsanitize=address -g3 
RM			=	rm -rf

OBJS		=	$(SRCS:%.cpp=%.o)

all:		$(NAME)

$(NAME):	$(OBJS)
			@$(CC) $(CPPFLAGS) $(OBJS) -o $(NAME)
			@echo "Create $<."

.cpp.o:
			@$(CC) $(CPPFLAGS) -c $< -o $(<:.cpp=.o)
			@echo "Compiling $<."

clean:
			@$(RM) $(OBJS)

fclean:		clean
			@$(RM) $(NAME)

re:			fclean all

.PHONY:		fclean, all, re

