CC=gcc
TARGET = A
SOURCE = src/main.c
FLAGS = -fopenmp -Wall -Wextra -ggdb -mcmodel=large

all:	$(SOURCE)
	$(CC) -o $(TARGET) $(SOURCE) $(FLAGS)
