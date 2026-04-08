CC=gcc
CFLAGS=-Wall -Wextra -Werror -Wvla
LDFLAGS=-g -fsanitize=address
LDLIBS=-lcriterion
EXE=testsuite

SRCS=\
../src/string/init_string.c \
../src/string/data_string.c \
../src/string/print_string.c \
../src/string/cmp_string.c \
../src/string/dup_string.c

OBJS=$(SRCS:.c=.o)

TEST_SRCS= \
test_cmp_string.c \
test_init_string.c \
test_dup_string.c 

TEST_OBJS=$(TEST_SRCS:.c=.o)


check: test
	@echo "launching testsuite:"
	@./testsuite


test:CFLAGS+= $(LDFLAGS)
test: $(OBJS) $(TEST_OBJS)
	$(CC) -o testsuite $(OBJS) $(TEST_OBJS) $(LDFLAGS) $(LDLIBS)

.PHONY: clean

clean:
	@echo "renoving tests objects:"
	$(RM) $(TEST_OBJS)
	@echo "\nremoving testsuite:"
	$(RM) $(EXE)
