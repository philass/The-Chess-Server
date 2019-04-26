main: main.o ChessGame.o
	g++ -std=c++11 main.o ChessGame.o -o main

server: server.o ChessGame.o
	g++ -std=c++11 server.o ChessGame.o -o server

ChessGame.o: ChessGame.cpp ChessGame.h
	g++ -std=c++11 -c ChessGame.cpp -o ChessGame.o

main.o: main.cpp
	g++ -std=c++11 -c main.cpp -o main.o

client: client.c
	gcc client.c -o client

server.o: server.cpp
	g++ -std=c++11 -c server.cpp -o server.o

clean: 
	rm -f main server client ChessGame *.o
