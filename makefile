CC=g++
CFLAGS=-c -Wall -std=c++11 

all: chicken

chicken: driver.o bone.o yard.o hand.o player.o game.o field.o
	$(CC) driver.o bone.o yard.o hand.o player.o game.o field.o -o chicken

driver.o: driver.cpp
	$(CC) $(CFLAGS) driver.cpp

bone.o: bone.cpp
	$(CC) $(CFLAGS) bone.cpp

yard.o: yard.cpp
	$(CC) $(CFLAGS) yard.cpp

hand.o: hand.cpp
	$(CC) $(CFLAGS) hand.cpp

player.o: player.cpp
	$(CC) $(CFLAGS) player.cpp

game.o: game.cpp
	$(CC) $(CFLAGS) game.cpp

field.o: field.cpp
	$(CC) $(CFLAGS) field.cpp

clean:
	rm *o 




