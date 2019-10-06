###################################################
##########Yishay seroussi 305027948################
###################################################

CC=g++
CFLAGS = -std=c++0x -g 

a.out: Card.o Player.o Game.o main.o 
	$(CC) $(CFLAGS) -o a.out Card.o Player.o  Game.o main.o
Game.o: Game.h Game.cpp  
	$(CC) $(CFLAGS) -c Game.cpp -o Game.o
Player.o: Player.cpp Player.h  
	$(CC) $(CFLAGS) -c Player.cpp -o Player.o
Card.o: Card.h Card.cpp 
	$(CC) $(CFLAGS) -c Card.cpp -o Card.o
main.o: main.cpp 
	$(CC) $(CFLAGS) -c main.cpp -o main.o
