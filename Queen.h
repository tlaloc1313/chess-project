#ifndef QUEEN_H
#define QUEEN_H

#include "Piece.h"

class Queen : public Piece {
public:
  Queen(int startingSquare, int isWhite);
	bool checkPath(int destination, bool activeArray[64]);
  bool move(int square, bool activeArray[64]);
  ~Queen();
};

#endif