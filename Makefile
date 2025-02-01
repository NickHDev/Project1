CC = gcc
CFLAGS = -g -Wall -std=c99
PROGRAM = oss user
SRCS = oss.c user.c
OBJS = $(SRCS: .c = .o)
.PHONY: all clean
all: %(PROGRAM)

$(PROGRAM): $(OBJS)
	$(CC) $(CFLAGS) $^ -o $@

clean:
	rm -f $(PROGRAM) $(OBJS)

help:
	@echo "Usage: make [all|clean|help]"
	@echo "    all:    Build the $(PROGRAM) program"
	@echo "    clean:  Remove build artifacts"
	@echo "    help:   Print this help message"