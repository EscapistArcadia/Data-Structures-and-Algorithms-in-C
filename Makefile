CC := gcc
CFLAGS := -Wall -Wextra -Wpedantic -Wshadow -Wconversion -Wformat -Wnull-dereference -Wfloat-equal

SRCS := $(wildcard src/*.c)
TEST_SRC := test.c
OBJS := $(SRCS:.c=.o)
INCLUDE := include
TARGET := test

all:
	$(CC) $(CFLAGS) -I $(INCLUDE) -o $(TARGET) $(SRCS) $(TEST_SRC)

clean:
	rm -f $(TARGET)

# %.o: %.c
# 	$(CC) $(CFLAGS) -c $< -o $@