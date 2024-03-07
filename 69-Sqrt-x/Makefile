
# Compiler
CC=clang++
# Formatter
FF=clang-format
# CFLAGS will be the options passed to the compiler.
CFLAGS=-std=c++17
# Format flags
FFLAGS=-style=file -i
# Dependencies
OBJS=main.o

all: main

main: main.cpp
	$(CC) $(CFLAGS) main.cpp -o $(OBJS)

format: main.cpp
	$(FF) $(FFLAGS) main.cpp


%.o: %.cpp $(DEPS)
	$(CXX) $(CXXFLAGS) -c -o $@ $<

clean:
	rm -rf *.o
