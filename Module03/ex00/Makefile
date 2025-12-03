
NAME 		:= umlTest

CC			:= g++

CFLAGS		:= -Wall -Wextra -Werror -std=c++98

DIR_SRC 	:= src


SRC			:= main.cpp \
				Brake.cpp \
				BrakeController.cpp \
				Car.cpp \
				Cockpit.cpp \
				Crankshaft.cpp \
				DAE.cpp \
				Direction.cpp \
				Electronics.cpp \
				ExplosionChamber.cpp \
				GearLever.cpp \
				Gear.cpp \
				Injector.cpp \
				LinkablePart.cpp \
				Motor.cpp \
				Pedal.cpp \
				SteerWheel.cpp \
				Transmission.cpp \
				Wheel.cpp \
				iMovable.cpp \
				iTurnable.cpp \
				DriverInfo.cpp

SRCS		:= $(addprefix $(DIR_SRC)/, $(SRC))

DIR_HEAD	:= include

DIR_OBJ		:= obj
			
OBJ 		:= $(addprefix $(DIR_OBJ)/, $(SRC:.cpp=.o))


all		: $(NAME)


$(NAME)	: $(OBJ)
			$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

$(OBJ)	: $(DIR_OBJ)/%.o : $(DIR_SRC)/%.cpp
			$(CC) $(CFLAGS) -c $< -o $@



clean	: 
			rm -f $(OBJ)

fclean	: clean
			rm -f $(NAME)

re		: fclean all

.PHONY	:all clean fclean re

