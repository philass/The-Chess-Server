#include <iomanip>
#include <iostream>


class ChessGame 
{
  private:
    bool turn; // True means Whites turn
    bool gameOn;// True means game is not over
    int board[8][8] =
      {{-1, -2, -3, -4, -5, -3, -2, -1},
       {-6, -6, -6, -6, -6, -6, -6, -6}, 
        {0,  0,  0,  0,  0,  0,  0,  0},
        {0,  0,  0,  0,  0,  0,  0,  0},
        {0,  0,  0,  0,  0,  0,  0,  0}, 
        {0,  0,  0,  0,  0,  0,  0,  0},
        {6,  6,  6,  6,  6,  6,  6,  6},    
        {1,  2,  3,  4,  5,  3,  2,  1}}; 

    
  
  public:
    ChessGame(): turn(true), gameOn(true) {}
  
    void printBoard() {
      for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
          std::cout << board[i][j] << std::setw(4);
        }
        std::cout << "\n";
        std::cout << "\n";
        std::cout << "\n";
      }
    }
    void move(int rowFrom, int columnFrom, int rowTo, int columnTo)
    {
      int piece = board[columnFrom][rowFrom];
      std::cout << "The piece selected is " << piece << std::endl;
    }
};

int main() 
{
ChessGame c;
c.printBoard();
return 0;
}
