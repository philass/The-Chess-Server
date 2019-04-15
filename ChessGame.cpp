/*
This Class Emulates a Chess game in the terminal
*/

#include <iomanip>
#include <iostream>
#include <cmath>
#include <vector>

class ChessGame 
{
  private:
    bool whiteTurn;   // True means Whites turn
    bool gameOn;      // True means game is not over
    
    // Initial Board
    std::vector<std::vector<int>> boardState =
      {{-1, -2, -3, -4, -5, -3, -2, -1},
       {-6, -6, -6, -6, -6, -6, -6, -6}, 
        {0,  0,  0,  0,  0,  0,  0,  0},
        {0,  0,  0,  0,  0,  0,  0,  0},
        {0,  0,  0,  0,  0,  0,  0,  0}, 
        {0,  0,  0,  0,  0,  0,  0,  0},
        {6,  6,  6,  6,  6,  6,  6,  6},    
        {1,  2,  3,  4,  5,  3,  2,  1}}; 
    

    // Test whether a diagonal move from coordinates (rowFrom, ColFrom) -> (rowTo, colTo) on the board
    // is a legal move.
    bool canMoveDiag(int rowFrom, int colFrom, int rowTo, int colTo, std::vector<std::vector<int>> board)
    {
      if (rowTo < 0 || colTo < 0 || rowTo > 7 || colTo > 7) {
        return false;
      }

      if (!(std::abs(rowTo - rowFrom) == std::abs(colTo - colFrom) && rowTo != rowFrom)) {
        return false;
      }
      int deltaCol = colTo > colFrom ? 1 : -1; 
      int deltaRow = rowTo > rowFrom ? 1 : -1;
      int currentRow = rowFrom;
      int currentCol = colFrom;
      while (currentRow != rowTo) {
        currentRow += deltaRow;
        currentCol += deltaCol;
        if (board[currentRow][currentCol] != 0) {
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
    
    // Test whether a straight move from coordinates (rowFrom, ColFrom) -> (rowTo, colTo) on the board
    // is a legal move.
    bool canMoveStraight(int rowFrom, int colFrom, int rowTo, int colTo, std::vector<std::vector<int>> board) 
    {
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
    
    
    // Checks if boardState is in check 
    bool inCheck(std::vector<std::vector<int>> boardState) 
    {
      return false;
    }

    // Test whether a pawn move from coordinates (rowFrom, ColFrom) -> (rowTo, colTo) on the board is legal
    bool canMovePawn(int rowFrom, int colFrom, int rowTo, int colTo, std::vector<std::vector<int>> board) 
    {
      if (rowTo < 0 || colTo < 0 || rowTo > 7 || colTo > 7) {
        return false;
      }
      bool isPossibleMove = false;
      if (colTo == colFrom && rowTo == rowFrom - 1 && board[rowTo][colTo] == 0) {
        isPossibleMove = true;
      } else if (colTo == colFrom && rowTo == rowFrom - 2 && rowFrom == 6 
                    && board[rowTo - 1][colTo] == 0 && board[rowTo][colTo] == 0) {
        isPossibleMove = true;
      } else if (std::abs(colTo - colFrom) == 1 && rowFrom == rowTo + 1 && board[rowTo][colTo] < 0) {
        isPossibleMove = true;
      }
      if (isPossibleMove) {
        std::vector<std::vector<int>> copy = board;
        copy[rowTo][colTo] = copy[rowFrom][colFrom];
        copy[rowTo][colTo] = 0;
        return !inCheck(copy);
      } else {
        return false;
      }
    }
    
    // Test whether a King move from coordinates (rowFrom, ColFrom) -> (rowTo, colTo) on the board is legal
    bool canMoveKing(int rowFrom, int colFrom, int rowTo, int colTo, std::vector<std::vector<int>> board)
    {
      int colDif = std::abs(colFrom - colTo); 
      int rowDif = std::abs(rowFrom - rowTo); 
      bool withinOneSquare = colDif + rowDif > 0 && colDif < 2 && rowDif < 2;
      bool canMove = canMoveStraight(rowFrom, colFrom, rowTo, colTo, board) || 
        canMoveStraight(rowFrom, colFrom, rowTo, colTo, board);
    }
    
    // Test whether a Queen move from coordinates (rowFrom, ColFrom) -> (rowTo, colTo) on the board is legal
    bool canMoveQueen(int rowFrom, int colFrom, int rowTo, int colTo, std::vector<std::vector<int>> board)
    {
      return canMoveStraight(rowFrom, colFrom, rowTo, colTo, board) || canMoveStraight(rowFrom, colFrom, rowTo, colTo, board);
    }
    
    
    // Test whether a Knight move from coordinates (rowFrom, ColFrom) -> (rowTo, colTo) on the board is legal
    bool canMoveKnight(int rowFrom, int colFrom, int rowTo, int colTo, std::vector<std::vector<int>> board) {
      int colDif = std::abs(colFrom - colTo);
      int rowDif = std::abs(rowFrom - rowTo);
      if (rowTo < 0 || rowTo > 7 || colTo < 0 || colTo > 7) {
        return false;
      }
      if (! (colDif + rowDif == 3 && 0 < rowDif && rowDif < 3)) {
        return false;
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
    
    // Test whether a Bishop move from coordinates (rowFrom, ColFrom) -> (rowTo, colTo) on the board is legal
    bool canMoveBishop(int rowFrom, int colFrom, int rowTo, int colTo, std::vector<std::vector<int>> board)
    {
      return canMoveStraight(rowFrom, colFrom, rowTo, colTo, board);
    }
    
    // Test whether a Rook move from coordinates (rowFrom, ColFrom) -> (rowTo, colTo) on the board is legal
    bool canMoveRook(int rowFrom, int colFrom, int rowTo, int colTo, std::vector<std::vector<int>> board)
    {
      return canMoveStraight(rowFrom, colFrom, rowTo, colTo, board);
    }
    
  
  public:
    ChessGame(): whiteTurn(true), gameOn(true) {}
  
    // Print the current state of the board
    void printBoard() {
      for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
          std::cout << boardState[i][j] << std::setw(4);
        }
        std::cout << "\n";
        std::cout << "\n";
        std::cout << "\n";
      }
    }
    
    //Translate the Black pieces to have white orientation
    std::vector<std::vector<int>> blackBoard() {
      std::vector<std::vector<int>> copy = boardState;
      for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
          copy[i][j] = boardState[7 - i][j] * -1;
        }
      }
      return copy;
    }



    // Make move from coordinates (rowFrom, colFrom) -> (rowTo, colTo) if move is legal
    void move(int rowFrom, int colFrom, int rowTo, int colTo)
    {
      int piece = boardState[rowFrom][colFrom];
      bool legal = false;
      bool correctColor = (whiteTurn && piece > 0) || (!whiteTurn && piece < 0);
      int uRowTo = whiteTurn ? rowTo : 7 - rowTo;
      int uRowFrom = whiteTurn ? rowFrom : 7 - rowFrom; 

      std::vector<std::vector<int>> board = whiteTurn ? boardState : blackBoard();
      int uPiece = board[uRowFrom][colFrom];
      if (uPiece == 0 || !correctColor) {
        std::cout << "Illegal Move" << std::endl;   
        legal = false;
      } else if (uPiece == 1) {
        legal = canMoveRook(uRowFrom, colFrom, uRowTo, colTo, board);  
      } else if (uPiece == 2) {
        legal = canMoveKnight(uRowFrom, colFrom, uRowTo, colTo, board);
      } else if (uPiece == 3) {
        legal = canMoveBishop(uRowFrom, colFrom, uRowTo, colTo, board);
      } else if (uPiece == 4) {
        legal = canMoveQueen(uRowFrom, colFrom, uRowTo, colTo, board);
      } else if (uPiece == 5) {
        legal = canMoveKing(uRowFrom, colFrom, uRowTo, colTo, board);
      } else if (uPiece == 6) {
        legal = canMovePawn(uRowFrom, colFrom, uRowTo, colTo, board);
      }

      if (legal) {
        boardState[rowFrom][colFrom] = 0;
        boardState[rowTo][colTo] = piece;
        whiteTurn = !whiteTurn;
      }
      std::cout << "The piece selected is " << piece << std::endl;
      std::cout << "col : " << colFrom << " | row : " << rowFrom << std::endl;
    }
};

int main() 
{
  ChessGame c;
  c.printBoard();
  // Repeatdly ask for moves
  while(true) {
    int rowFrom;
    std::cout << "Row From : ";
    std::cin >> rowFrom;
    int colFrom;
    std::cout << "Col From : ";
    std::cin >> colFrom;
    int rowTo;
    std::cout << "Row to : ";
    std::cin >> rowTo;
    int colTo;
    std::cout << "Col to : ";
    std::cin >> colTo;
    c.move(rowFrom, colFrom, rowTo, colTo);
    c.printBoard();
  }
return 0;
}
