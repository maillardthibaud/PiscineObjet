
NAME			:= OpenClose

CC				:= g++

CFLAGS			:= -Wall -Wextra -Werror -std=c++98

SRC				:= Command.cpp \
					PackageReductionDiscount.cpp \
					TuesdayDiscount.cpp \
					main.cpp


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

.PHONY			: all fclean clean re


