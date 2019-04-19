#makefile

CC = g++
CFLAGS =
TARGET = P0
OBJS = main.o tree.o
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

tree.o: tree.cpp tree.h node.h	
	$(CC) $(CFLAGS) -c tree.cpp
main.o: main.cpp tree.h node.h
	$(CC) $(CFLAGS) -c main.cpp

clean:
	/bin/rm -f *.o $(TARGET)
