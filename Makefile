CC=clang++
CCFLAGS="-Wall -Wextra -Werror -std=c++98"


# Compiling
all		: tests


# Testing
test	:
		  @cd Cavalry && ./Cavalry.sh

main	: main.cpp compile_main
		  @./ft_containers


# Cleaning commands
clean	: 
		  @rm -f main.cpp ft_containers
		  @cd Cavalry && ./Cavalry.sh clean

re		: clean all

.PHONY	: all test main clean re


# Main for hand testing
create_main	:
		  	  $(file > main.cpp, ${MAIN_CODE})

compile_main:
		  	  $(CC) $(CCPFLAGS) main.cpp -o ft_containers


define MAIN_CODE
#include "vector.hpp"
#include "stack.hpp"
#include "map.hpp"
#include "set.hpp"

#include <vector>
#include <stack>
#include <map>
#include <set>

#include <iostream>

int main()
{
}
endef
