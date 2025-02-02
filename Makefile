CC = gcc
CFLAGS = -g -Wall -pedantic
TARGET1 = oss
TARGET2 = user
SRCS = oss.c user.c
OBJS1 = oss.o
OBJS2 = user.o
.PHONY: all clean
all: $(TARGET1) $(TARGET2)

$(TARGET1):	$(OBJS1)
	$(CC) -o $(TARGET1) $(OBJS1)

$(TARGET2):	$(OBJS2)
	$(CC) -o $(TARGET2) $(OBJS2)

oss.o: oss.c
	$(CC) $(CFLAGS) -c oss.c

user.o: user.c
	$(CC) $(CFLAGS) -c user.c

clean:
	/bin/rm -f *.o $(TARGET1) $(TARGET2)

help:
	@echo "Usage: make [all|clean|help]"
	@echo "    all:    Build the $(TARGET) TARGETS"
	@echo "    clean:  Remove build artifacts"
	@echo "    help:   Print this help message"