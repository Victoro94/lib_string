CC=gcc
CFLAGS=-Wall -Wextra -Werror -Wvla
LDFLAGS=-g -fsanitize=address
EXE=main debug

SRCS=\
string/string_init.c \
string/string_data.c \
string/string_io.c \
string/string_cmp.c \
string/string_dup.c

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
