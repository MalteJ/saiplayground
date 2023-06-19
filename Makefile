CC = gcc
CFLAGS = -I/usr/include/sai -I/usr/include/sai/experimental
LDFLAGS = -L/usr/lib -lsai
SRCS = $(wildcard *.c)
OBJS = $(SRCS:.c=.o)
TARGET = target/supersai

.PHONY: all clean

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(OBJS) $(LDFLAGS) -o $@

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

run: all
	./$(TARGET)

clean:
	rm -f $(OBJS) $(TARGET)
