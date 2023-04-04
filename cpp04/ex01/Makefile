SRCS =	main.cpp\
		srcs/Animal.cpp\
		srcs/Cat.cpp\
		srcs/Dog.cpp\
		srcs/WrongAnimal.cpp\
		srcs/WrongCat.cpp\
		srcs/Brain.cpp

NAME = main

CC			=	clang++
INCLUDES	=	includes
CPPFLAGS	=	-Wall -Werror -Wextra -I$(INCLUDES) -g3
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

