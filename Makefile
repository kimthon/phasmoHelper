CC=gcc
SRCS=phasmo.cpp Ghost.cpp
OBJS=$(SRCS:.cpp=.o)
LDLIBS=-I common/
CFLAGS=-Wall
TARGET=PhasmoHelper

vpath %.cpp src
vpath %.h include
vpath %.o object

all: $(OBJS)
	$(CC) -o $(TARGET) $(OBJS)

%.o: %.cpp %.h
	$(CC) -c $< -o object/$@ $(LDLIBS) $(CFLAGS)

clean:
	rm -f obj/*.o


