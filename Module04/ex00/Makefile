
NAME			:= Prepa

CC				:= c++

CFLAGS			:= -Wall -Wextra -Werror -std=c++11

SRC				:= main.cpp \
					Room.cpp \
					HeadmasterOffice.cpp \
					SecretarialOffice.cpp \
					StaffRestRoom.cpp \
					Classroom.cpp \
					Courtyard.cpp \
					Person.cpp \
					Student.cpp \
					Staff.cpp \
					Secretary.cpp \
					Headmaster.cpp \
					Professor.cpp \
					Form.cpp 
					




OBJ				:= $(SRC:.cpp=.o)



all				: $(NAME)

$(NAME)			: $(OBJ)
					$(CC) $(OBJ) -o $(NAME)

%.o 			: %.cpp
					$(CC) $(CFLAGS) -c $< -o $@

clean			:
					rm -f $(OBJ)

fclean			: clean
					rm -f $(NAME)

re				: fclean all

.PHONY			: all clean fclean re


