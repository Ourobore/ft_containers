MAKE_FLAGS = --no-print-directory

# Compiling
all		: 
		@cd tests && $(MAKE) $(MAKE_FLAGS)


# Testing
tests	:
		@cd tests && $(MAKE) $(MAKE_FLAGS) run


# Cleaning commands
clean	:
		@cd tests && $(MAKE) $(MAKE_FLAGS) clean

fclean	: 
		@cd tests && $(MAKE) $(MAKE_FLAGS) fclean

re		: 
		@cd tests && $(MAKE) $(MAKE_FLAGS) re


.PHONY		: all clean re tests