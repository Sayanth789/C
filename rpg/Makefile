CC = gcc

CFLAGS = -Wall -Wextra -std=c11

SRC = src/main.c \
      src/game.c \
      src/player.c \
      src/enemy.c \
      src/combat.c

TARGET = rpg

all:
	$(CC) $(CFLAGS) $(SRC) -o $(TARGET)

clean:
	rm -f $(TARGET)
