
NAME			:= Facade

CC				:= g++

CFLAGS			:= -Wall -Wextra -Werror -std=c++11

SRC_DIR			:= src

OBJ_DIR			:= obj

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
					Form.cpp \
					NeedCourseCreationForm.cpp \
					NeedMoreClassRoomForm.cpp \
					SubscriptionToCourseForm.cpp \
					CourseFinishedForm.cpp \
					Course.cpp 


OBJ				:= $(addprefix $(OBJ_DIR)/, $(SRC:.cpp=.o))

all				: $(NAME)

$(NAME)			: $(OBJ)
					$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

$(OBJ)			: $(OBJ_DIR)/%.o : $(SRC_DIR)/%.cpp
					$(CC) $(CFLAGS) -c $< -o $@

clean			:
					rm -f $(OBJ)

fclean			: clean
					rm -f $(NAME)

re				: fclean all

.PHONY			: all clean fclean re


