CC=g++
CFLAGS= -g -Wall
EXEC = Money_Change
CFILES = Money_Change.cpp
OBJS = Money_Change.o

$(EXEC): $(OBJS)
	$(CC) $(CFLAGS) -o $(EXEC) $(OBJS)

$(OBJS):
	$(CC) $(CFLAGS) -c $(CFILES)
clean:
	rm -f $(OBJS)