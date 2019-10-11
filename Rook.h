#ifndef ROOK_H
#define ROOK_H

#include "Piece.h"

class Rook : public Piece{
public:
  Rook(int startingSquare, int isWhite);
  bool move(int square, bool activeArray[64]);
  int castle(int square);
  ~Rook();
};

#endif
