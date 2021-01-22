CC = g++
CFLAGS = -g -Wall
EXEC = LCM
OBJS = LCM.o GCD.o

$(EXEC): $(OBJS)
	$(CC) $(CFLAGS) -o $(EXEC) $(OBJS)

GCD.o: GCD.cpp GCD.h
	$(CC) $(CFLAGS) -c GCD.cpp

LCM.o: LCM.cpp GCD.h
	$(CC) $(CFLAGS) -c LCM.cpp

clean:
	rm -f $(EXEC) $(OBJS)