CC=gcc
CFLAGS=-Wall -Wextra -std=c11 -O2

TARGET=register_simulator
SRC=main.c register.c

$(TARGET): $(SRC)
	$(CC) $(CFLAGS) $(SRC) -o $(TARGET)

clean:
	rm -f $(TARGET)
