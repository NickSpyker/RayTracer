##
## EPITECH PROJECT, 2022
## RayTracer
## File description:
## Makefile
##

MAKEFLAGS += --no-print-directory

BIN = raytracer

SRC_DIRS = ./core/src
SRCS := $(shell find $(SRC_DIRS) -name "*.cpp")
OBJS = $(SRCS:.cpp=.o)
CFLAGS =
CPPFLAGS = $(shell find ./core ./api -type d | awk '{printf "-I%s ", $$0}')

all: $(BIN)

$(BIN): $(OBJS)
	@$(CXX) -o $(BIN) $(SRCS) $(CFLAGS) $(CPPFLAGS) -lconfig++

clean:
	@$(RM) -rf $(OBJS)
	@$(RM) -rf *.gcda
	@$(RM) -rf *.gcno

fclean: clean
	@$(RM) -rf $(BIN)

re: fclean all
