#ifndef KING_H
#define KING_H

#include "Piece.h"

class King : public Piece{
public:
  King(int startingSquare, int isWhite);
  bool move(int square, bool activeArray[64]);
  int castle(int square);
  ~King();
};


#endif
