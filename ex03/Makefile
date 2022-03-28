NAME := prog.out
CXX  := c++
CXXFLAGS := -g -Wall -Wextra -Werror -std=c++98 -Iinclude/

SRC := $(wildcard src/*.cpp)
OBJ := $(SRC:%.cpp=%.o)

ifeq ($(OS),Windows_NT)
	$(error "Sorry, Windows is not supported")
endif


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
