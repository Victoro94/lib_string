CC=gcc
CFLAGS=-Wall -Wextra -Werror -Wvla
LDFLAGS=-g -fsanitize=address
LDLIBS=-lcriterion
EXE=main debug

SRCS=\
string/init_string.c \
string/data_string.c \
string/print_string.c \
string/cmp_string.c \
string/dup_string.c

OBJS=$(SRCS:.c=.o)
lib=string/libstring.a


all: $(OBJS)
	$(CC) -o main $^ main.c
	ar csr $(lib) $(OBJS)
	@echo "\nmain done\n"

debug:CFLAGS+= $(LDFLAGS)
debug: $(OBJS)
	$(CC) $(LDFLAGS) -o debug $^ main.c
	@echo "\ndebug done"

.PHONY: clean

clean:
	@echo "removing objects:"
	$(RM) $(OBJS)
	@echo "\nremoving libraries:"
	$(RM) $(lib)
	@echo "\nremoving executables:"
	$(RM) $(EXE) 
