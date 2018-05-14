COMPILER := gcc
FLAGS := -g -Wall
LIBS := -lallegro -lallegro_primitives -lm

.DEFAULT_GOAL := all

util.o: util.h
	$(COMPILER) -c $(FLAGS) util.c

spaceship.o: util.o
	$(COMPILER) -c $(FLAGS) spaceship.c

asteroid.o: util.o
	$(COMPILER) -c $(FLAGS) asteroid.c

blasteroids.o: spaceship.o asteroid.o
	$(COMPILER) -c $(FLAGS) blasteroids.c

all: blasteroids.o spaceship.o asteroid.o util.o
	$(COMPILER) blasteroids.o spaceship.o asteroid.o util.o $(LIBS) -o blasteroids
	
clean:
	rm *.o blasteroids

run:
	./blasteroids
