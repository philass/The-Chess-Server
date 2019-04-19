#include <iostream>
#include <iostream>
#include <string>
#include "ChessGame.h"
int main() 
{
  std::cout << "Yo we made it here" << std::endl;
  ChessGame c;
  std::cout << "Initialzied the board" << std::endl;
  c.printBoard();
  std::cout << "Printed the board" << std::endl;
  while (true) {
    std::cout << "It is " << (c.isWhiteTurn() ? "white" : "black") << "'s turn!" << std::endl;
    std::string squareFrom;
    std::cout << "SquareFrom : ";
    std::cin >> squareFrom;
    std::string squareTo;
    std::cout << "SquareTo : ";
    std::cin >> squareTo;
    std::pair<int, int> f = c.getCoords(squareFrom);
    std::pair<int, int> t = c.getCoords(squareTo);
    c.move(f.first, f.second, t.first, t.second);
    c.printBoard();


  }

return 0;
}
