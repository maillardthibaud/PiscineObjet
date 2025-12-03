
NAME			:= PuttingItIntoPractice

CC				:= c++

CFLAGS			:= -Wall -Wextra -Werror -std=c++98

SRC				:= main.cpp \
					Worker.cpp \
					Shovel.cpp \
					Hammer.cpp \
					Tool.cpp \
					Workshop.cpp

OBJ				:= $(SRC:.cpp=.o)





all				: $(NAME)

$(NAME)			: $(OBJ)
					$(CC) $(OBJ) -o $(NAME)

%.o				: %.cpp
					$(CC) $(CFLAGS) -c $< -o $@

clean			:
					rm -f $(OBJ)

fclean			: clean
					rm -f $(NAME)

re				: fclean all

.PHONY			: all clean fclean re
