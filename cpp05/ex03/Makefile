CXX			= c++
CXXFLAGS	= -Wall -Wextra -Werror -std=c++17

NAME		= intern
OBJ_DIR		= obj
SRC_DIR		= src
INC_DIR		= include
REMOVE		= rm -rf

# INTERNAL FUNCTIONS
FUNCTIONS	=	$(SRC_DIR)/main.cpp \
				$(SRC_DIR)/Bureaucrat.cpp \
				$(SRC_DIR)/AForm.cpp \
				$(SRC_DIR)/ShrubberyCreationForm.cpp \
				$(SRC_DIR)/RobotomyRequestForm.cpp \
				$(SRC_DIR)/PresidentialPardonForm.cpp \
				$(SRC_DIR)/Intern.cpp \


# INTERNAL OBJECT
OBJECTS		= $(addprefix $(OBJ_DIR)/, $(notdir $(FUNCTIONS:.cpp=.o)))

all : $(NAME)

# INTERNAL RULE
$(NAME) : $(OBJECTS)
	$(CXX) $(CXXFLAGS) $(OBJECTS) -o $(NAME)

# DIRECTORY
$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp | $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean :
	$(REMOVE) $(OBJECTS)
	$(REMOVE) $(OBJ_DIR)
	$(REMOVE) Christmas_shrubbery

fclean : clean
	$(REMOVE) $(NAME)

re : fclean all

.PHONY : all clean fclean re