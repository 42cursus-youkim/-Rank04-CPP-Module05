NAME := prog.out
CXX  := c++
CXXFLAGS := -g -Wall -Wextra -Werror -std=c++98 -pedantic -Iinclude/

SRC := $(wildcard src/*.cpp)
OBJ := $(SRC:%.cpp=%.o)

.PHONY: run re clean

$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $@ $^

all: $(NAME)
re: clean all
run: all
	./$(NAME)

clean:
	$(RM) $(OBJ) $(NAME)

leak: all
	colour-valgrind --leak-check=full ./$(NAME)
