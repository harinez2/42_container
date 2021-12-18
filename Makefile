NAME		= mycontainer
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
debug: CXXFLAGS += -g -fsanitize=integer -fsanitize=address -fsanitize=leak -fsanitize=undefined
debug: re

gtestdir    =   ../test
gtest       =   $(gtestdir)/gtest $(gtestdir)/googletest-release-1.11.0

testdir = ./src

$(gtest):
	mkdir -p $(dir ../test)
	curl -OL https://github.com/google/googletest/archive/refs/tags/release-1.11.0.tar.gz
	tar -xvzf release-1.11.0.tar.gz googletest-release-1.11.0
	rm -rf release-1.11.0.tar.gz
	python3 googletest-release-1.11.0/googletest/scripts/fuse_gtest_files.py $(gtestdir)
	mv googletest-release-1.11.0 $(gtestdir)

test: $(gtest) 
	clang++ -std=c++11 $(testdir)/gtest.cpp \
		$(gtestdir)/googletest-release-1.11.0/googletest/src/gtest_main.cc \
		$(gtestdir)/gtest/gtest-all.cc \
		-DDEBUG -g -fsanitize=integer -fsanitize=address \
		-I$(gtestdir) -I$(includes) -lpthread $(srcs_test) -o tester
	./tester
	rm tester
