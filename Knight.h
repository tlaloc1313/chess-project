#ifndef KNIGHT_H
#define KNIGHT_H

#include "Piece.h"

class Knight : public Piece {
public:
  Knight(int startingSquare, int isWhite);
  bool move(int square, bool activeArray[64]);
  ~Knight();
};

#endif