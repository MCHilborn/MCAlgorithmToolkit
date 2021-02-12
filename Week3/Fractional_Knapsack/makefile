CC=g++
CFLAGS= -g -Wall
EXEC = Fractional_Knapsack
CFILES = Fractional_Knapsack.cpp
OBJS = Fractional_Knapsack.o

$(EXEC): $(OBJS)
	$(CC) $(CFLAGS) -o $(EXEC) $(OBJS)

$(OBJS):
	$(CC) $(CFLAGS) -c $(CFILES)
clean:
	rm -f $(OBJS)