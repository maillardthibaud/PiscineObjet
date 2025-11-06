
NAME 	:= idkwid

CC		:= g++

CFLAGS 	:= -Wall -Wextra -Werror -std=c++98

SRC		:= Graph.cpp \
			main.cpp

OBJ		:= $(SRC:.cpp=.o)



all		:$(NAME)

$(NAME) : $(OBJ) 
			$(CC) $(OBJ) -o $(NAME)

%.o		:%.cpp %.hpp
			$(CC) $(CFLAGS) -c $< -o $@


clean	:
			rm -f $(OBJ)


fclean	: clean
			rm -f $(NAME)

re		: fclean clean

.PHONY	: all re clean fclean