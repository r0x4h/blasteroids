COMPILER := gcc
FLAGS := -g -Wall
LIBS := -lallegro -lallegro_primitives

.DEFAULT_GOAL := all

blasteroids.o: blasteroids.c spaceship.o spaceship.h
	$(COMPILER) -c $(FLAGS) blasteroids.c

spaceship.o: spaceship.c spaceship.h
	$(COMPILER) -c $(FLAGS) spaceship.c

all: blasteroids.o spaceship.o
	$(COMPILER) blasteroids.o spaceship.o $(LIBS) -o blasteroids
	
clean:
	rm *.o blasteroids
