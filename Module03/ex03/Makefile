NAME			:= Interface

CC				:= g++

CFLAGS			:= -Wall -Wextra -Werror -std=c++98

SRCS			:= main.cpp \
					Employee.cpp \
					EmployeeManagement.cpp \
					HourlyEmployee.cpp \
					SalariedEmployee.cpp \
					Apprentice.cpp


OBJS			:= $(SRCS:.cpp=.o)


all				: $(NAME)

$(NAME)			: $(OBJS)
					$(CC) $(OBJS) -o $(NAME)

%.o				: %.cpp
					$(CC) $(CFLAGS) -c $< -o $@

clean			: 
					rm -f $(OBJS)

fclean			: clean
					rm -f $(NAME)
		
re				: fclean
				
.PHONY			: all clean fclean re