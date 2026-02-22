CC=gcc
CFLAGS=-Wall -Wextra -Werror -Wvla
LDFLAGS=-g -fsanitize=address
LDLIBS=-lcriterion
EXE=main debug ../tests/testsuite

SRCS=string/basic_string.c
OBJS=$(SRCS:.c=.o)

TEST_SRCS=../tests/test_basic_string.c
TEST_OBJS=$(TEST_SRCS:.c=.o)

all: $(OBJS)
	$(CC) -o main $^ main.c
	@echo "\nmain done\n"
	@echo "running main\n==================="
	@./main

debug:CFLAGS+= $(LDFLAGS)
debug: $(OBJS)
	$(CC) $(LDFLAGS) -o debug $^ main.c
	@echo "\ndebug done"
	@echo "running debug\n===================="
	@./debug

check: test
	@../tests/testsuite

test: $(OBJS) $(TEST_OBJS)
	$(CC) -o ../tests/testsuite $(OBJS) $(TEST_OBJS) $(LDFLAGS) $(LDLIBS)


.PHONY: clean

clean:
	$(RM) $(OBJS) $(TEST_OBJS) $(EXE) 
