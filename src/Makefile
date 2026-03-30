CC=gcc
CFLAGS=-Wall -Wextra -Werror -Wvla
LDFLAGS=-g -fsanitize=address
LDLIBS=-lcriterion
EXE=main debug

SRCS=string/basic_string.c string/easy_string.c
OBJS=$(SRCS:.c=.o)


all: $(OBJS)
	$(CC) -o main $^ main.c
	@echo "\nmain done\n"
	@echo "running main\n==================="

debug:CFLAGS+= $(LDFLAGS)
debug: $(OBJS)
	$(CC) $(LDFLAGS) -o debug $^ main.c
	@echo "\ndebug done"
	@echo "running debug\n===================="
	@./debug

.PHONY: clean

clean:
	@echo "removing objects:"
	$(RM) $(OBJS) 
	@echo "\nremoving tests objects:"
	$(RM) $(TEST_OBJS) 
	@echo "\nremoving executables:"
	$(RM) $(EXE) 
