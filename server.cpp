#include <netdb.h> 
#include <netinet/in.h> 
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h> 
#include <string.h> 
#include <sys/socket.h> 
#include <sys/types.h> 
#define MAX 80 
#define PORT 8080 
#include <cstdio>
#define SA struct sockaddr 
// Function designed for chat between client and server. 

#include "ChessGame.h"

/*
---- Pseudo code for func -----

while ChessGame is not over:
  ask for white move:
  while white move isNotLegal:
    get white move
    ask for black move:
  while black move isNotLegal:
    get black move
    ask for black move:
*/

void fun(int sockfd1, int sockfd2, ChessGame c)
{
  char buff1[MAX];
  char buff2[MAX];
  int n;
  for (;;) {
    bzero(buff1, MAX);
    bzero(buff2, MAX);
    if (c.isWhiteTurn()) {
      while (c.isWhiteTurn()) {
        write(sockfd1, "square from ? ", sizeof(buff1));
        read(sockfd1, buff1, sizeof(buff1));
        write(sockfd1, "square to ? ", sizeof(buff2));
        read(sockfd1, buff2, sizeof(buff2));
        std::string squareFrom (buff1);
        std::string squareTo (buff2);
        std::pair<int, int> f = c.getCoords(squareFrom);
        std::pair<int, int> t = c.getCoords(squareTo);
        c.move(f.first, f.second, t.first, t.second);
     }
   } else {
      while (!c.isWhiteTurn()) {
        write(sockfd2, "square from ? ", sizeof(buff1));
        read(sockfd2, buff1, sizeof(buff1));
        write(sockfd2, "square to ? ", sizeof(buff2));
        read(sockfd2, buff2, sizeof(buff2));
        std::string squareFrom (buff1);
        std::string squareTo (buff2);
        std::pair<int, int> f = c.getCoords(squareFrom);
        std::pair<int, int> t = c.getCoords(squareTo);
        c.move(f.first, f.second, t.first, t.second);
     }
  }
}
}
/**
void func(int sockfd1, int sockfd2, ChessGame c) 
{ 
    char buff[MAX]; 
    int n; 
    // infinite loop for chat 
    for (;;) { 
        bzero(buff, MAX); 
  
        // read the message from client and copy it in buffer 
        read(sockfd1, buff, sizeof(buff)); 
        // print buffer which contains the client contents 
        printf("From client: %s\t To client : ", buff); 
        bzero(buff, MAX); 
        n = 0; 
        // copy server message in the buffer 
        while ((buff[n++] = getchar()) != '\n') 
            ; 
  
        // and send that buffer to client 
        write(sockfd1, buff, sizeof(buff)); 
        write(sockfd2, buff, sizeof(buff)); 
        // if msg contains "Exit" then server exit and chat ended. 
        if (strncmp("exit", buff, 4) == 0) { 
            printf("Server Exit...\n"); 
            break; 
        } 
    } 
} 
*/
// Driver function 
int main() 
{ 
    ChessGame c;
    c.printBoard();
    int sockfd, connfd, len, connfd1, len1;
    struct sockaddr_in servaddr, cli, cli1; 
  
    // socket create and verification 
    sockfd = socket(AF_INET, SOCK_STREAM, 0); 
    if (sockfd == -1) { 
        printf("socket creation failed...\n"); 
        exit(0); 
    } 
    else
        printf("Socket successfully created..\n"); 
    bzero(&servaddr, sizeof(servaddr)); 
  
    // assign IP, PORT 
    servaddr.sin_family = AF_INET; 
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY); 
    servaddr.sin_port = htons(PORT); 
  
    // Binding newly created socket to given IP and verification 
    if ((bind(sockfd, (SA*)&servaddr, sizeof(servaddr))) != 0) { 
        printf("socket bind failed...\n"); 
        exit(0); 
    } 
    else
        printf("Socket successfully binded..\n"); 
  
    // Now server is ready to listen and verification 
    if ((listen(sockfd, 5)) != 0) { 
        printf("Listen failed...\n"); 
        exit(0); 
    } 
    else
        printf("Server listening..\n"); 
    len = sizeof(cli); 
    len1 = sizeof(cli1); 
    // Accept the data packet from client and verification 
    socklen_t socklen;
    socklen_t socklen1;
    connfd = accept(sockfd, (SA*)&cli, &socklen); 
    connfd1 = accept(sockfd, (SA*)&cli1, &socklen1); 
 
    if (connfd < 0) { 
        printf("server acccept failed...\n"); 
        exit(0); 
    } 
    else
        printf("server acccept the client0...\n"); 
    
    if (connfd1 < 0) { 
        printf("server acccept failed...\n"); 
        exit(0); 
    } 
    else
        printf("server acccept the client1...\n"); 
  
    // Function for chatting between client and server 
    fun(connfd, connfd1, c); 
  
    // After chatting close the socket 
    close(sockfd); 
} 
