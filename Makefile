ChessGame: ChessGame.cpp
	g++ -std=c++11 ChessGame.cpp -o ChessGame

client: client.c
	gcc client.c -o client

server: server.c
	gcc server.c -o server

clean: 
	rm server client ChessGame
