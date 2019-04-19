
/** Header file for ChessGame.cpp **/


#ifndef CHESSGAME_H
#define CHESSGAME_H

#include <vector>
#include <string>
#include <utility>
class ChessGame

{
private:
  bool whiteTurn;
  bool gameOn;
    std::vector<std::vector<int> > boardState =
      {{-1, -2, -3, -4, -5, -3, -2, -1},
       {-6, -6, -6, -6, -6, -6, -6, -6}, 
        {0,  0,  0,  0,  0,  0,  0,  0},
        {0,  0,  0,  0,  0,  0,  0,  0},
        {0,  0,  0,  0,  0,  0,  0,  0}, 
        {0,  0,  0,  0,  0,  0,  0,  0},
        {6,  6,  6,  6,  6,  6,  6,  6},    
        {1,  2,  3,  4,  5,  3,  2,  1}}; 
    bool canMoveDiag(int rowFrom, int colFrom, int rowTo, int colTo, std::vector<std::vector<int> > board);
    bool canMoveStraight(int rowFrom, int colFrom, int rowTo, int colTo, std::vector<std::vector<int> > board);
    bool positionThreatened(int rowIn, int colIn, std::vector<std::vector<int> > state);
    bool isLegal(int row, int col);
    bool inCheck(std::vector<std::vector<int> > board);
    bool canMovePawn(int rowFrom, int colFrom, int rowTo, int colTo, std::vector<std::vector<int> > board);
    bool canMoveKing(int rowFrom, int colFrom, int rowTo, int colTo, std::vector<std::vector<int> > board);
    bool canMoveQueen(int rowFrom, int colFrom, int rowTo, int colTo, std::vector<std::vector<int> > board);
    bool canMoveKnight(int rowFrom, int colFrom, int rowTo, int colTo, std::vector<std::vector<int> > board);
    bool canMoveBishop(int rowFrom, int colFrom, int rowTo, int colTo, std::vector<std::vector<int> > board);
    bool canMoveRook(int rowFrom, int colFrom, int rowTo, int colTo, std::vector<std::vector<int> > board);
    std::vector<std::vector<int> > blackBoard();
    std::vector<std::vector<int> > flip(std::vector<std::vector<int> > board);
  public:;
    ChessGame();
    std::pair<int, int> getCoords(std::string location);
    std::string intToPiece(int i);
    void printBoard();
    bool isWhiteTurn();
    void move(int rowFrom, int colFrom, int rowTo, int colTo);
};

#endif
