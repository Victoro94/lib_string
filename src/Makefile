CC=gcc
SRCS=main.c string/basic_string.c
CFLAGS=-Wall -Wextra -Werror -Wvla
DBG_FLAGS=-g -fsanitize=address
OBJS=$(SRCS:.c=.o)
EXE=main debug test


all: $(OBJS)
	$(CC) -o main $^
	@echo ''
	@echo 'main done'

debug:CFLAGS+= $(DBG_FLAGS)
debug: $(OBJS)
	$(CC) $(DBG_FLAGS) -o debug $^ 
	@echo ''
	@echo 'debug done'

.PHONY: clean

clean:
	$(RM) $(OBJS) $(EXE)
