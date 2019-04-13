#include <iomanip>
#include <iostream>
#include <cmath>
#include <vector>
class ChessGame 
{
  private:
    bool turn; // True means Whites turn
    bool gameOn;// True means game is not over
    std::vector<std::vector<int>> board =
      {{-1, -2, -3, -4, -5, -3, -2, -1},
       {-6, -6, -6, -6, -6, -6, -6, -6}, 
        {0,  0,  0,  0,  0,  0,  0,  0},
        {0,  0,  0,  0,  0,  0,  0,  0},
        {0,  0,  0,  0,  0,  0,  0,  0}, 
        {0,  0,  0,  0,  0,  0,  0,  0},
        {6,  6,  6,  6,  6,  6,  6,  6},    
        {1,  2,  3,  4,  5,  3,  2,  1}}; 
    


    bool canMoveDiag(int rowFrom, int colFrom, int rowTo, int colTo) {
      if (rowTo < 0 || colTo < 0 || rowTo > 7 || colTo > 7) {
        return false;
      }

      if (std:abs(rowTo - rowFrom) == std::abs(colTo - colFrom) && rowTo != rowFrom) {
        int deltaCol = colTo > colFrom ? 1 : -1; 
        int deltaRow = rowTo > rowFrom ? 1 : -1;
        int currentRow = rowFrom;
        int currentCol = colFrom;
        while (currentRow != rowTo) {
          currentRow += deltaRow;


        }
      }
    }
    bool canMoveStraight(int rowFrom, int colFrom, int rowTo, int colTo) {
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
        if (board[rowTo][colTo] > 0) {
          return false; 
        } else {
          std::vector<std::vector<int>> copy = board;
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
        if (board[rowTo][colTo] > 0) {
          return false; 
        } else {
          std::vector<std::vector<int>> copy = board;
          copy[rowTo][colTo] = copy[rowFrom][colFrom];
          copy[rowTo][colTo] = 0;
          return !inCheck(copy);
        }
      }

    }
    bool inCheck(std::vector<std::vector<int>> boardState) 
    {
      return false;
    }
    bool canMovePawn(int rowFrom, int colFrom, int rowTo, int colTo) {
      return true;
    }
    bool canMoveKing(int rowFrom, int colFrom, int rowTo, int colTo)
    {
      int colDif = std::abs(colFrom - colTo); 
      int rowDif = std::abs(rowFrom - rowTo); 
      bool withinOneSquare = colDif + rowDif > 0 && colDif < 2 && rowDif < 2;
      bool canMove = canMoveStraight(rowFrom, colFrom, rowTo, colTo) || 
        canMoveStraight(rowFrom, colFrom, rowTo, colTo);
    }
    bool canMoveQueen(int rowFrom, int colFrom, int rowTo, int colTo)
    {
      return canMoveStraight(rowFrom, colFrom, rowTo, colTo) || canMoveStraight(rowFrom, colFrom, rowTo, colTo);
    }
    bool canMoveKnight(int rowFrom, int colFrom, int rowTo, int colTo) {
      return false; 
    }
    bool canMoveBishop(int rowFrom, int colFrom, int rowTo, int colTo)
    {
      return canMoveStraight(rowFrom, colFrom, rowTo, colTo);
    }
    bool canMoveRook(int rowFrom, int colFrom, int rowTo, int colTo)
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

    void move(int rowFrom, int colFrom, int rowTo, int colTo)
    {
      std::vector<std::vector<int>> copy = board;
      int piece = board[rowFrom][colFrom];
      bool legal = false;
      if (piece == 0) {
        std::cout << "Illegal Move" << std::endl;   
        legal = false;
      } else if (piece == 1) {
        legal = canMoveRook(rowFrom, colFrom, rowTo, colTo);  
      } else if (piece == 2) {
        legal = canMoveKnight(rowFrom, colFrom, rowTo, colTo);
      } else if (piece == 3) {
        legal = canMoveBishop(rowFrom, colFrom, rowTo, colTo);
      } else if (piece == 4) {
        legal = canMoveQueen(rowFrom, colFrom, rowTo, colTo);
      } else if (piece == 5) {
        legal = canMoveKing(rowFrom, colFrom, rowTo, colTo);
      } else if (piece == 6) {
        legal = canMovePawn(rowFrom, colFrom, rowTo, colTo);
      }

      // Need case for ampersant pond
      // Need cases for black pieces
      if (legal) {
        board[rowFrom][colFrom] = 0;
        board[rowTo][colTo] = piece;
      }
      std::cout << "The piece selected is " << piece << std::endl;
      std::cout << "col : " << colFrom << " | row : " << rowFrom << std::endl;
    }
};

int main() 
{
  ChessGame c;
  c.printBoard();
  c.move(6, 7, 0, 0);
  c.printBoard();
  c.move(7, 7, 4, 7);
  c.printBoard();
  c.move(4, 7, 0, 7);
  c.printBoard();
  return 0;
}
