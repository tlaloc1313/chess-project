#ifndef BISHOP_H
#define BISHOP_H

#include "Piece.h"

class Bishop : public Piece {
public:
  Bishop(int startingSquare, int isWhite);
  bool move(int square, bool activeArray[64]);
  ~Bishop();
};

#endif
