SRCS		= main.cpp 

OBJS		= $(addprefix $(OBJS_DIR), $(SRCS:.cpp=.o))

INCLUDE		= -Iiterator \
			  -Iutils

OBJS_DIR	= objs/

CC			= clang++

CPPFLAGS	= -Wall -Werror -Wextra -std=c++98 -g3 -fsanitize=address

NAME		= ft_containers

all			: $(NAME)

$(OBJS_DIR)%.o	: ./%.cpp
			  	  $(CC) $(CPPFLAGS) $(INCLUDE) -c $< -o $@

$(NAME)		: $(OBJS_DIR) $(OBJS)
			  $(CC) $(CPPFLAGS) $(OBJS) -o $(NAME)

$(OBJS_DIR)	:
			  @mkdir $(OBJS_DIR)

clean		:
		 	 rm -rf $(OBJS_DIR)

fclean		: clean
		 	 rm -rf $(NAME)

re			: clean all

.PHONY		: all clean re