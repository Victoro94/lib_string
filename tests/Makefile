CC=gcc
CFLAGS=-Wall -Wextra -Werror -Wvla
LDFLAGS=-g -fsanitize=address
LDLIBS=-lcriterion
EXE=testsuite

SRCS=\
../src/string/string_init.c \
../src/string/string_data.c \
../src/string/string_io.c \
../src/string/string_cmp.c \
../src/string/string_dup.c

OBJS=$(SRCS:.c=.o)

TEST_SRCS= \
test_string_init.c \
test_string_cmp.c \
test_string_dup.c \
test_string_data.c

TEST_OBJS=$(TEST_SRCS:.c=.o)

check: test
	@echo "launching testsuite:"
	@./testsuite

test:CFLAGS+= $(LDFLAGS)
test: $(OBJS) $(TEST_OBJS)
	$(CC) -o testsuite $(OBJS) $(TEST_OBJS) $(LDFLAGS) $(LDLIBS)

.PHONY: clean

clean:
	@echo "removing tests objects:"
	$(RM) $(TEST_OBJS)
	@echo "\nremoving testsuite:"
	$(RM) $(EXE)
