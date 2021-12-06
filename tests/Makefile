# Variables
SRC_DIR		= src/
SRCS		= 

MAIN		= main.cpp

OBJS_DIR	= obj/
OBJS		= $(addprefix $(OBJS_DIR), $(SRCS:.cpp=.o))
MAIN_OBJ	= $(addprefix $(OBJS_DIR), $(MAIN:.cpp=.o))

INCLUDE		= -I../ \
			  -I../iterator/ \
			  -I../utils/ \
			  -I./ \
			  -I./src/ \
			  -I./src/utils

CC			= clang++

CPPFLAGS	= -Wall -Werror -Wextra -std=c++98 #-g3 -fsanitize=address

NAME		= ft_containers


# Compilation
all			: $(NAME)

# Compiles the .o
$(OBJS_DIR)%.o	: $(SRC_DIR)%.cpp
			  	  $(CC) $(CPPFLAGS) $(INCLUDE) -c $< -o $@

# Creates executable
$(NAME)		: $(OBJS_DIR) $(OBJS) $(MAIN_OBJ)
			  $(CC) $(CPPFLAGS) $(INCLUDE) $(MAIN_OBJ) $(OBJS) -o $(NAME)

$(OBJS_DIR)	:
			  @mkdir -p $@
			  @mkdir -p $@utils


# Launching tests
run			: 
			  @./ft_containers



# Cleaning
clean		:
		 	 rm -rf $(OBJS_DIR)

fclean		: clean
		 	 rm -rf $(NAME)

re			: clean all

.PHONY		: all clean re run