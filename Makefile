.SUFFIXES : .x .o .c .s

CFLAGS = -Wall -std=c++11
CC = g++

TARGET = runme
SRCS = gameOfLife.c
OBJS = $(SRCS:.c=.o)

all: $(TARGET)

$(TARGET):$(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $@ $(LIBS)

%.o:%.cpp
	$(CC) $(CFLAGS) $(INCS) -c $<

clean:
	rm -f *.o
	rm -f $(TARGET)

