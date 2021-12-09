# Compiling
all		: tests

# Testing
tests	:
		  @cd tests && ./test.sh

# Cleaning commands
clean	: 
		  @cd tests && ./test.sh clean

re		: clean all

.PHONY	: all clean re tests