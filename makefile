# Make file for operator overloading assignment

OBJS	= main.o crop.o garden.o
CC		= g++
CCFLAGS	= -Wall -Wextra -pedantic -std=c++11 -g
DEPS	= crop.h garden.h

all: main

main: $(OBJS)
	@echo "Linking Objects..."
	$(CC) $(CCFLAGS) -o garden $(OBJS)
	@echo "Done! Finished building garden program"

main.o:	main.cpp $(DEPS)
	@echo "Compiling Main..."
	$(CC) $(CCFLAGS) -c main.cpp
crop.o: crop.cpp $(DEPS)
	@echo "Compiling Crops..."
	$(CC) $(CCFLAGS) -c crop.cpp
garden.o: garden.cpp $(DEPS)
	@echo "Compiling Garden..."
	$(CC) $(CCFLAGS) -c garden.cpp

# -----
# clean by removing object files.

clean:
	rm $(OBJS) garden
