CC=g++
CFLAGS= -g -Wall
EXEC = Car_Fueling
CFILES = Car_Fueling.cpp
OBJS = Car_Fueling.o

$(EXEC): $(OBJS)
	$(CC) $(CFLAGS) -o $(EXEC) $(OBJS)

$(OBJS):
	$(CC) $(CFLAGS) -c $(CFILES)
clean:
	rm -f $(OBJS)