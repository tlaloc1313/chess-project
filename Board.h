#include "Piece.h"

#ifndef BOARD_H
#define BOARD_H

class Board {
private:
  Piece pieceArray[64];
  bool activeArray[64];

public:
  Board ();
  bool spaceOccupied(int space);

  //Returns 2 if a piece is taken, 1 if the piece is moved, -1 if the move is illegal, -2 if the piece doesn't exist
  int movePiece(int startSpace, int endSpace);

  //Returns 1 if the piece was added, 0 if the space is taken
  int addPiece(int type, int startSpace);
  virtual ~Board ();
};

#endif
