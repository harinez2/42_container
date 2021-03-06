NAME		= mycontainer
SRCDIR		= ./srcs
SRCS		= $(shell find $(SRCDIR) -name "*.cpp" -type f | xargs)
OBJS		= $(SRCS:.cpp=.o)
DEPENDS		= $(OBJS:.o=.d)
INCLUDES	= ./includes
CXX			= clang++
CXXFLAGS	= -Wall -Wextra -Werror -std=c++98 -pedantic-errors -MMD -MP

.PHONY: all
all: $(NAME)

-include $(DEPENDS)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) -I$(INCLUDES) -o $(NAME) $(OBJS)

.PHONY: clean
clean:
	$(RM) $(OBJS) $(DEPENDS)

.PHONY: fclean
fclean: clean
	$(RM) $(NAME)
	$(RM) tester
	$(RM) -r $(gtestdir)
	$(RM) -r cov_test

.PHONY: re
re: fclean all

.PHONY: debug
debug: CXXFLAGS += -g -fsanitize=integer -fsanitize=address -fsanitize=leak -fsanitize=undefined
debug: re

gtestdir		= ./gtest
gtest_release	= googletest-release-1.11.0
gtest			= $(gtestdir)/gtest $(gtestdir)/$(gtest_release)
mytestdir		= ./tests

$(gtest):
	mkdir -p $(gtestdir)
	curl -OL https://github.com/google/googletest/archive/refs/tags/release-1.11.0.tar.gz
	tar -xvzf release-1.11.0.tar.gz $(gtest_release)
	rm -rf release-1.11.0.tar.gz
	python3 $(gtest_release)/googletest/scripts/fuse_gtest_files.py $(gtestdir)
	mv $(gtest_release) $(gtestdir)

.PHONY: test
test: $(gtest) 
	$(CXX) -std=c++11 $(mytestdir)/gtest.cpp \
		$(gtestdir)/$(gtest_release)/googletest/src/gtest_main.cc \
		$(gtestdir)/gtest/gtest-all.cc \
		-D DEBUG -g -fsanitize=integer -fsanitize=address -fsanitize=leak -fsanitize=undefined \
		-I$(gtestdir) -I$(includes) -lpthread -o tester $(lcovflags)
	./tester
	$(RM) tester

.PHONY: wtest
wtest:
	$(CXX) $(mytestdir)/test_wrapper_main.cpp
	./a.out
	$(RM) a.out

.PHONY: lcov
lcov: CXX = g++
lcov: lcovflags += -fprofile-arcs -ftest-coverage
lcov: test
lcov:
	lcov -c -b . -d . -o cov_test.info
	genhtml cov_test.info -o cov_test

.PHONY: usage
usage:
	@echo "Available options for make:"
	@echo "  make"
	@echo "  make all       Build everything."
	@echo "  make clean"
	@echo "  make flean"
	@echo "  make re"
	@echo "  make debug     Build with fsanitize options."
	@echo "  make test      Build and run tests using google test."
	@echo "  make wtest     Build and run tests using original basic test."
	@echo "  make lcov      Count line of code."
