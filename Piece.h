#ifndef PIECE_H
#define PIECE_H

#include <cmath>
using std::abs;

extern int col(int location);
extern int row(int location);

// Superclass
class Piece {
protected:
  char pieceType;
  int location;
  bool isWhite;
  bool hasMoved;

public:
  Piece();
	int direction(int destination);
	bool checkStraight(int destination, bool activeArray[64]);
	bool checkDiagonal(int destination, bool activeArray[64]);
	virtual bool checkPath(int destination, bool activeArray[64]);
  virtual bool move(int square, bool activeArray[64]);
  int getPosition();
  char getType();
  bool getIsWhite();
  virtual ~Piece ();
};

#endif
