#ifndef PAWN_H
#define PAWN_H

#include "Piece.h"

class Pawn : public Piece {
public:
  Pawn(int startingSquare, int isWhite);
  bool move(int square, bool activeArray[64]);
  int checkEnPassant();
  ~Pawn();
};

#endif
