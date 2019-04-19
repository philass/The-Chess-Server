main: main.o ChessGame.o
	g++ -std=c++11 main.o ChessGame.o -o main
	
ChessGame.o: ChessGame.cpp ChessGame.h
	g++ -std=c++11 -c ChessGame.cpp -o ChessGame.o

main.o: main.cpp
	g++ -std=c++11 -c main.cpp -o main.o

client: client.c
	gcc client.c -o client

server: server.c
	gcc server.c -o server

clean: 
	rm -f main server client ChessGame *.o
