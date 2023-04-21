# Makefile #
OBJECTS = game_of_life.o functions.o
CC = gcc
TARGET = game
FLAGS = -lncursesw -Wall -ansi -pedantic
$(TARGET): $(OBJECTS)
	$(CC) $(OBJECTS) -o $(TARGET) $(FLAGS)
game_of_life.o: game_of_life.c headers.h
	$(CC) -c game_of_life.c
functions.o: functions.c headers.h
	$(CC) -c functions.c
clean:
	rm -f $(OBJECTS) $(TARGET)
