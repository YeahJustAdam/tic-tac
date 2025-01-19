CC = gcc
CFLAGS = -Wall -Wextra -std=c99
TARGET = tictac

all: $(TARGET)

$(TARGET): TICTAC.o
    $(CC) $(CFLAGS) -o $(TARGET) TICTAC.o

TICTAC.o: TICTAC.c
    $(CC) $(CFLAGS) -c TICTAC.c

clean:
    rm -f $(TARGET) *.o

.PHONY: all clean
