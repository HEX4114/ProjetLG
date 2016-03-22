CC=g++
CFLAGS=-c -Wall -std=c++11
LDFLAGS=
SRCS=$(wildcard *.cpp) $(wildcard */*.cpp) $(wildcard */*/*.cpp) $(wildcard */*/*/*.cpp)
OBJS=$(SRCS:%.cpp=%.o)
EXEC=lutin

all: $(SRCS) $(EXEC)
    
$(EXEC): $(OBJS) 
	$(CC) $(LDFLAGS) -o $(EXEC) $(OBJS) $(LDFLAGS)

%.o : %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf *.o

mrproper: clean
	rm -rf hello
