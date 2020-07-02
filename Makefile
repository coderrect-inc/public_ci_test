# the compiler to use
CC = clang
CXX = clang++

# compiler flags:
#   -g        adds debugging information to the executable file
#   -Wall     turns on most, but not all, compiler warnings
CFLAGS = -g -Wall -I.

# the name to use for both the target source file, and the output file:
TARGET = race

all: $(TARGET)

$(TARGET): race.o 
	$(CXX) -o $(TARGET) race.o -lpthread 

clean:
	rm -f *.o $(TARGET)
