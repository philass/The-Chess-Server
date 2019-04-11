#include <iostream>


class ChessGame 
{

  private board [8][8] = 
    {{-1, -2, -3, -4, -5, -3, -2, -1},
     {-6, -6, -6, -6, -6, -6, -6, -6}, 
      {0,  0,  0,  0,  0,  0,  0,  0},
      {0,  0,  0,  0,  0,  0,  0,  0},
      {0,  0,  0,  0,  0,  0,  0,  0}, 
      {0,  0,  0,  0,  0,  0,  0,  0},
      {6,  6,  6,  6,  6,  6,  6,  6},    
      {1,  2,  3,  4,  5,  3,  2,  1}};
  
  public void printBoard() {
    for (int i = 0; i < 8; i++) {
      for (int j = 0; j < 8; j++) {
        std::cout << board[i][j] << " ";
      }
      std::cout << "\n";
    }
    return 0;
  }
}

