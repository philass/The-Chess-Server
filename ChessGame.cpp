#include <iomanip>
#include <iostream>
#include <cmath>

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
    
    bool canMoveDiag(rowFrom, colFrom, rowTo, colTo) {
      return true;
    }
    bool canMoveStraight(rowFrom, colFrom, rowTo, ColumnTo) {
      if (rowTo < 0 || colTo < 0 || rowTo > 7 || colTo > 7) {
        return false;
      }
      if (rowTo == rowFrom && colTo != colFrom) {
        int delta = colTo > colFrom ? 1 : -1;
        for (int i = colFrom + delta; (i - colTo) * delta < 0; i += delta) {
          if (board[rowTo][i] != 0) {
            return false;
          }
        }
        if (board[rowTo][colTo] < 0) {
          return false; 
        } else {
          int* copy = copyBoard();
          copy[rowTo][colTo] = copy[rowFrom][colFrom];
          copy[rowTo][colTo] = 0;
          return !inCheck(copy);
        }
      }
      if (colTo == colFrom && rowTo != rowFrom) {
        int delta = rowTo > rowFrom ? 1 : -1;
        for (int i = rowFrom + delta; (i - rowTo) * delta < 0; i += delta) {
          if (board[i][colFrom] != 0) {
            return false;
          }
        }
        if (board[rowTo][colTo] < 0) {
          return false; 
        } else {
          int* copy = copyBoard();
          copy[rowTo][colTo] = copy[rowFrom][colFrom];
          copy[rowTo][colTo] = 0;
          return !inCheck(copy);
        }
      }

    }
    bool inCheck(int[8][8] boardState) 
    {
      return false;
    }
    bool canMovePawn(rowFrom, colFrom, rowTo, colTo) {
      return true;
    }
    bool canMoveKing(rowFrom, colFrom, rowTo, colTo)
    {
      int colDif = std::abs(colFrom - colTo); 
      int rowDif = std::abs(rowFrom - rowTo); 
      bool withinOneSquare = colDif + rowDif > 0 && colDif < 2 && rowDif < 2;
      bool canMove = canMoveStraight(rowFrom, colFrom, rowTo, colTo) || 
        canMoveStraight(rowFrom, colFrom, rowTo, colTo);
    }
    bool canMoveQueen(rowFrom, colFrom, rowTo, colTo)
    {
      return canMoveStraight(rowFrom, colFrom, rowTo, colTo) || canMoveStraight(rowFrom, colFrom, rowTo, colTo);
    }
    bool canMoveKnight(rowFrom, colFrom, rowTo, colTo) {
      return false; 
    }
    bool canMoveBishop(rowFrom, colFrom, rowTo, colTo)
    {
      return canMoveStraight(rowFrom, colFrom, rowTo, colTo);
    }
    bool canMoveRook(rowFrom, colFrom, rowTo, colTo)
    {
      return canMoveStraight(rowFrom, colFrom, rowTo, colTo);
    }
    
  
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

    int* boardCopy() 
    {
      int* copy = new int[8][8];
      for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
          copy[i][j] = board[i][j];
        }
      }
      return copy
    }

    void move(int rowFrom, int colFrom, int rowTo, int colTo)
    {
      int *copy = boardCopy();
      int piece = board[rowFrom][colFrom];
      bool legal;
      if (piece == 0) {
        std::cout << "Illegal Move" << std::endl;   
        legal = false;
      } else if (piece == 1) {
        legal = canMoveRook(rowFrom, colFrom, rowTo, ColumnTo);  
      } else if (piece == 2) {
        legal = canMoveKnight(rowFrom, colFrom, rowTo, ColumnTo);
      } else if (piece == 3) {
        legal = canMoveBishop(rowFrom, colFrom, rowTo, ColumnTo);
      } else if (piece == 4) {
        legal = canMoveQueen(rowFrom, colFrom, rowTo, ColumnTo);
      } else if (piece == 5) {
        legal = canMoveKing(rowFrom, colFrom, rowTo, ColumnTo);
      }

      // Need case for ampersant pond
      // Need cases for black pieces
      if (legal) {
        board[rowFrom][colFrom] = 0;
        board[rowTo][rowFrom] = piece;
      }
      std::cout << "The piece selected is " << piece << std::endl;
      std::cout << "col : " << colFrom << " | row : " << rowFrom << std::endl;
    }
};

int main() 
{
  ChessGame c;
  c.printBoard();
  c.move(0, 6, 0, 0);
  return 0;
}
