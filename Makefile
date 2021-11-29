NAME		= array
SRCDIR		= ./src
SRCS		= $(shell find $(SRCDIR) -name "*.cpp" -type f | xargs)
OBJS		= $(SRCS:.cpp=.o)
DEPENDS		= $(OBJS:.o=.d)
INCLUDES	= $(SRCDIR)
CXX			= clang++
CXXFLAGS	= -Wall -Wextra -Werror -std=c++98 -pedantic-errors -MMD -MP

.PHONY: all
all: $(NAME)

-include $(DEPENDS)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) -I$(INCLUDES) -o $(NAME) $(OBJS)

.PHONY: clean
clean:
	rm -f $(OBJS) $(DEPENDS)

.PHONY: fclean
fclean: clean
	rm -f $(NAME)

.PHONY: re
re: fclean all

.PHONY: debug
debug: CXXFLAGS += -g -fsanitize=integer -fsanitize=address -fsanitize=leak
debug: re
