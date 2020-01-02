NAME        := npuzzle

CXX         := g++
CXXFLAGS    := -std=c++11

SRC_DIR     = ./srcs/
INC_DIR     = ./includes/
OBJ_DIR     = ./obj/

SRCS_FILES := main.cpp \
				Node.cpp \
				Puzzle.cpp

HDRS_FILES := npuzzle.hpp \
				Node.hpp \
				Puzzle.hpp

OBJS_FILES := $(SRCS_FILES:.cpp=.o)

SRCS       := $(addprefix $(SRC_DIR), $(SRCS_FILES))
HDRS       := $(addprefix $(INC_DIR), $(HDRS_FILES))
OBJS       := $(addprefix $(OBJ_DIR), $(OBJS_FILES))

# Compile and create everything.
all: obj $(NAME)

obj:
	@mkdir -p $(OBJ_DIR)

# This won't run if the source files don't exist or are not modified.
$(OBJ_DIR)%.o:$(SRC_DIR)%.cpp
	$(CXX) $(CXXFLAGS) -o $@ -c $< -I $(INC_DIR)

# Compile the program with the objects.
$(NAME): $(OBJS) $(HDRS)
	@$(CXX) $(OBJS) -o $@

# Rule to remove all the object files.
clean:
	@rm -rf $(OBJ_DIR)

# Rule to remove everything that has been created by the makefile.
fclean: clean
	@rm -f $(NAME)

# Rule to re-make everything.
re:     fclean all

# Makes sure that gnu make will still run even if files called
# clean / fclean / all and re already exist in the directory
.PHONY: all clean fclean re